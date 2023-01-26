/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:14:58 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/26 13:39:28 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>

// int	g_size = 0;
// int	g_char = 0;

int	handling_size(int sig, int size, int *index)
{
	static int	bit = 32;

	if (sig == 30)
		size = size * 2 + 0;
	else
		size = size * 2 + 1;
	bit--;
	if (bit == 0)
		*index = 1;
	return (size);
}

void	receive_signal(int sig)
{
	static int	index;
	static int	size;
	// static char	c = 0;

	if (index == 0)
			size = handling_size(sig, size, &index);
	ft_printf("size = %d\n", size);
	ft_printf("index = %d\n", index);
	// else if (index == 1)
	// 	size = handling_size(sig, &index);
	// if (index == 2)
	// 	size = handling_size(sig, &index);
	// if (index == 3)
	// 	size = handling_size(sig, &index);
	// index = 0;
}

int	main(int argc, char **argv)
{
	if (argc != 1 && argv[0][0] != '\0')
		return (ft_printf("Error\nServer does not take parameters"), 0);
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
		pause();
	return (0);
}

// void	handling_size(int signal)
// {
// 	if (signal == SIGUSR1)
// 		g_size = g_size * 2 + 0;
// 	if (signal == SIGUSR2)
// 		g_size = g_size * 2 + 1;
// }

// void	handling_char(int signal)
// {
// 	if (signal == SIGUSR1)
// 		g_char = g_char * 2 + 0;
// 	if (signal == SIGUSR2)
// 		g_char = g_char * 2 + 1;
// }

	// bit = 32;
	// i = 0;
	// while (--bit >= 0)
	// {
	// 	signal(SIGUSR1, handling_size);
	// 	signal(SIGUSR2, handling_size);
	// 	pause();
	// }
	// ft_printf("size = %d\n", g_size);
	// str = malloc(sizeof(char) * (g_size + 1));
	// if (!str)
	// 	return (0);
	// while (g_size - i > 0)
	// {
	// 	bit = 8;
	// 	g_char = 0;
	// 	while (--bit >= 0)
	// 	{
	// 		signal(SIGUSR1, handling_char);
	// 		signal(SIGUSR2, handling_char);
	// 		pause();
	// 	}
	// 	ft_printf("c = %c\n", g_char);
	// 	str[i] = g_char;
	// 	i++;
	// }
	// str[i] = '\0';
	// ft_printf("%s\n", str);
	// Faire une fonction tampon qui prend le sig en param et qui reparti ensuite
