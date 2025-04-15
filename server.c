/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:09:04 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/15 19:09:16 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	static unsigned char	current_c;
	static int				bit_index;

	current_c |= (sig == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (!current_c)
			write(1, "\n", 1);
		else
			write(1, &current_c, 1);
		bit_index = 0;
		current_c = 0;
	}
	else
		current_c <<= 1;
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
