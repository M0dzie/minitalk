/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:38 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/25 17:09:30 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>

int	ft_atoi(const char *str);

// SIGUSR1 = 0 / SIGUSR2 = 1

void	send_size(int size, int pid)
{
	int	bytes;

	bytes = 32;
	while (--bytes >= 0)
	{
		if (size >> bytes & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	send_message(char *str, int pid)
{
	int	bytes;
	int	i;

	i = -1;
	while (str[++i])
	{
		bytes = 8;
		while (--bytes >= 0)
		{
			if (str[i] >> bytes & 1)
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
		return (ft_printf("Error\nClient takes 2 parameters : a PID and a string."), 0);
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		return (ft_printf("Error\nPID is not valid.\n"), 0);
	size = ft_strlen(argv[2]);
	send_size(size, pid);
	send_message(argv[2], pid);
	return (0);
}
