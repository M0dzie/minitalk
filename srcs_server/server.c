/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:14:58 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/26 09:34:46 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>

void	signal_handler(int signal)
{
	ft_printf("signal_handler = %d\n", signal);
}

int	receive_size(void)
{
	static int	size;
	int			bit;

	size = 0;
	bit = 32;
	while (--bit >= 0)
	{
		if (signal(SIGUSR1, signal_handler))
		{
			size *= 2 + 0;
			ft_printf("0\n");
		}
		if (signal(SIGUSR2, signal_handler))
		{
			size *= 2 + 1;
			ft_printf("1\n");
		}
	}
	ft_printf("size = %d\n", size);
	return (size);
}

int	main(void)
{
	pid_t	pid;
	int		size;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (1)
	{
		pause();
		size = receive_size();
	}
	return (0);
}
