/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:34:10 by fstaryk           #+#    #+#             */
/*   Updated: 2022/06/17 18:14:36 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

t_temp_state	g_temp_state;

void	sig_handle(int sig, siginfo_t *info, void *ucontext)
{
	int	bit;

	bit = sig - SIGUSR1;
	if (info->si_pid != g_temp_state.client_pid)
		init_temp_state();
	g_temp_state.prog_char = g_temp_state.prog_char << 1 | bit;
	g_temp_state.i++;
	if (g_temp_state.i == 8)
	{
		if (!g_temp_state.prog_char)
			kill(g_temp_state.client_pid, SIGUSR1);
		ft_putchar_fd(g_temp_state.prog_char, STDOUT_FILENO);
		init_temp_state();
	}
	g_temp_state.client_pid = info->si_pid;
}

void	init_temp_state(void)
{
	g_temp_state.client_pid = 0;
	g_temp_state.i = 0;
	g_temp_state.prog_char = 0;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Servers PID is : %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_handle;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (0 == 0)
		usleep(1);
}
