/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:14:58 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/26 11:15:46 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>

int	g_size = 0;

void	handling_size(int signal)
{
	if (signal == SIGUSR1)
		g_size = g_size * 2 + 0;
	if (signal == SIGUSR2)
		g_size = g_size * 2 + 1;
}

void	handling_char(int signal)
{
	static char	c;

	c = 0;
	if (signal == SIGUSR1)
		c = c * 2 + 0;
	if (signal == SIGUSR2)
		c = c * 2 + 1;
	ft_printf("c = %c", c);
}

int	main(void)
{
	int		bit;
	int		i;
	char	c;
	char	*str;

	ft_printf("PID : %d\n", getpid());
	bit = 32;
	i = -1;
	c = 0;
	while (--bit >= 0)
	{
		signal(SIGUSR1, handling_size);
		signal(SIGUSR2, handling_size);
		pause();
	}
	ft_printf("size = %d\n", g_size);
	str = malloc(sizeof(char) * (g_size + 1));
	if (!str)
		return (0);
	while (str[++i])
	{
		bit = 8;
		while (--bit >= 0)
		{
			signal(SIGUSR1, handling_char);
			signal(SIGUSR2, handling_char);
			pause();
		}
		str[i] = c;
	}
	ft_printf("str = %s", str);
	return (0);
}
