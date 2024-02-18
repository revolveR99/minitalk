/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:40:09 by zabdulza          #+#    #+#             */
/*   Updated: 2023/08/01 13:40:19 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *s)
{
	int	outcome;
	int	i;
	int	signchange;

	signchange = 1;
	i = 0;
	outcome = 0;
	while (s[i] == '\t' || s[i] == '\v' || s[i] == '\f'
		|| s[i] == '\n' || s[i] == ' ' || s[i] == '\r')
	{
		i++;
	}
	if (s[i] == '-')
	{
		signchange = signchange * -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		outcome = ((s[i] - '0') + (outcome * 10));
		i++;
	}
	return (outcome * signchange);
}

void	info_transfer(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c << bit & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(420);
		bit++;
	}
}

int	main(int arc, char **agv)
{
	int	pid;
	int	i;

	i = 0;
	if (arc == 3)
	{
		pid = ft_atoi(agv[1]);
		while (agv[2][i])
		{
			info_transfer(pid, agv[2][i]);
			i++;
		}
	}
	else
		ft_printf("U sure u included both PID + ur message dear?\n");
	return (0);
}
