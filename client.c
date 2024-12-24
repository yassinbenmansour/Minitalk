/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:16:34 by yabenman          #+#    #+#             */
/*   Updated: 2024/12/24 03:53:13 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_character(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(500);
	}
}

int	check_error(char *str)
{
	int	pid;
	int	i;

	pid = ft_atoi(str);
	if (pid < 0)
		return (0);
	i = kill(pid, 0);
	if (i == -1)
		return (0);
	return (pid);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = check_error(av[1]);
		if (pid > 0)
		{
			str = av[2];
			while (str[i])
			{
				send_character(pid, str[i]);
				i++;
			}
			ft_putchar('\n');
		}
		else
			ft_putstr("incorrect pid! \n");
	}
	else
		ft_putstr("Syntax error! \n");
	return (0);
}
