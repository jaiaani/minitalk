/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:22:06 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/15 17:43:26 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_c;
	static int				bit_index;

	(void)context;
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
	if (sig == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	if (sig == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_putnbr(get_pid());
	ft_putstr("\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
