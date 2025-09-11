/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/09/11 04:15:14 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	*message;
	int		pid;

	if (ac != 3)
		return (0);
	if (!av[2])
		return (0);
	message = av[2];
	pid = ft_atoi(av[1]);
	i = 0;
	if (pid < 0)
		return (0);
	while (message[i])
	{
		send_char(message[i], pid);
		i++;
	}
    send_char('\n', pid);
	send_char('\0', pid);
}
