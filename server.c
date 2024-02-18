/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:40:45 by zabdulza          #+#    #+#             */
/*   Updated: 2023/08/01 13:40:48 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_info(int info)
{
	static int	i;
	static char	chrt;

	if (info == SIGUSR1)
		chrt = (chrt << 1) | 1;
	else if (info == SIGUSR2)
		chrt = (chrt << 1);
	i++;
	if (i == 8)
	{
		ft_printf("%c", chrt);
		i = 0;
		chrt = 0;
	}
}

int	main(void)
{
	ft_printf("this is ur PID (use it wisely) -> %d\n", getpid());
	signal(SIGUSR1, handle_info);
	signal(SIGUSR2, handle_info);
	while (1)
		pause();
	return (0);
}
