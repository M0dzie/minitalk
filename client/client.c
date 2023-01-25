/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:38 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/25 13:56:49 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	received(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("SIGUSR1 received\n");
	if (signal == SIGUSR2)
		ft_printf("SIGUSR2 received\n");
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_printf("Error\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid > INT_MAX)
		return (ft_printf("Error\n"), 0);
	kill(pid, 0);
	return (0);
}
