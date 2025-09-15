/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/09/12 19:37:27 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_data = 0;

void	signal_handler(int signal)
{
	int	count;
	int	current_char;

	count = (g_data >> 8) & 0xFF;
	current_char = g_data & 0xFF;
	current_char *= 2;
	if (signal == SIGUSR2)
		current_char |= 1;
	count++;
	if (count == 8)
	{
		ft_printf("%c", current_char);
		g_data = 0;
	}
	else
		g_data = (count << 8) | current_char;
}

void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	ft_printf("Pid Server : %d\n", getpid());
	setup_signals();
	while (1)
		pause();
	return (0);
}
