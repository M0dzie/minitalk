/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:38 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/26 09:27:38 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>

int	ft_atoi(const char *str);

// SIGUSR1 = 0 / SIGUSR2 = 1

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

void	send_message(char *str, int pid)
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
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		return (ft_printf("Error\nPID is not valid.\n"), 0);
	size = ft_strlen(argv[2]);
	ft_printf("size = %d\n", size);
	send_size(size, pid);
	send_message(argv[2], pid);
	return (0);
}
