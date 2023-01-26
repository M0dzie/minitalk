/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:14:58 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/26 19:09:46 by thmeyer          ###   ########.fr       */
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

char	*handling_char(int sig, char *str, int *index)
{
	static int	i;
	static int	bit = 8;
	static char	c;

	if (sig == 30)
	{
		c = c * 2 + 0;
		ft_printf("0 et ");
	}
	else
	{
		c = c * 2 + 1;
		ft_printf("1 et ");
	}
	ft_printf("c = %d\n", c);
	bit--;
	if (bit == 0)
	{
		str[i] = c;
		ft_printf("str[%d] = %c\n", i, str[i]);
		bit = 8;
		c = 0;
		i++;
	}
	if (str[i] == '\0')
		*index = 3;
	*index = 2;
	return (str);
}

// void	mt_printstr()

void	receive_signal(int sig)
{
	static char	*str;
	static int	index;
	static int	size;

	if (index == 0)
			size = handling_size(sig, size, &index);
	if (index == 1)
	{
		ft_printf("size = %d\n", size);
		str = malloc(sizeof(char) * (size + 1));
		if (!str)
			exit(0);
		str[size] = '\0';
		index = 2;
	}
	if (index == 2)
		str = handling_char(sig, str, &index);
	if (index == 3)
		ft_printf("Coucou\n");
	// if (index == 3)
	// ft_printf("str : %s\n", str);
	// PRINT + *index = 0 dans la fonction finale
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
