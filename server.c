/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/09/30 19:26:16 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_server	g_server;

void	handle_signal(int signal)
{
	t_server	*s;

	if (signal == SIGUSR1)
		g_server.current_char = g_server.current_char << 1;
	else if (signal == SIGUSR2)
		g_server.current_char = (g_server.current_char << 1) | 1;
	g_server.bits_received++;
	if (g_server.bits_received == 8)
	{
		if (g_server.current_char == '\0')
		{
			write(1, g_server.message_buffer, g_server.buffer_index);
			write(1, "\n", 1);
			g_server.buffer_index = 0;
		}
		else
		{
			s = &g_server;
			if (s->buffer_index < BUFFER_SIZE - 1)
				s->message_buffer[s->buffer_index++] = s->current_char;
		}
		g_server.current_char = 0;
		g_server.bits_received = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
