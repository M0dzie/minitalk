/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <thmeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:38 by thmeyer           #+#    #+#             */
/*   Updated: 2023/02/06 16:40:01 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>

int	mt_atoi(const char *str);

void	send_size(int size, int pid)
{
	int	bit;

	bit = 32;
	while (--bit >= 0)
	{
		if (size >> bit & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	send_str(char *str, int pid)
{
	int	bit;
	int	i;

	i = -1;
	while (str[++i])
	{
		bit = 8;
		while (--bit >= 0)
		{
			if (str[i] >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	size;

	if (argc != 3)
	{
		ft_printf("Error\nClient takes 2 parameters : a PID and a string.");
		return (0);
	}
	pid = mt_atoi(argv[1]);
	if (pid == -1)
		return (ft_printf("Error\nPID is not valid.\n"), 0);
	size = ft_strlen(argv[2]);
	send_size(size, pid);
	send_str(argv[2], pid);
	return (0);
}
