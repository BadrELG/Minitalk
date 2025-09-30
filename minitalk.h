/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:00:00 by badr              #+#    #+#             */
/*   Updated: 2025/09/30 19:20:19 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define BUFFER_SIZE 4096

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "src/Printf/ft_printf.h"

typedef struct s_server
{
	char			message_buffer[BUFFER_SIZE];
	int				buffer_index;
	unsigned char	current_char;
	int				bits_received;
}	t_server;

int	ft_atoi(char *str);

#endif