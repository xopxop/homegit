/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 23:56:30 by dthan             #+#    #+#             */
/*   Updated: 2020/08/26 23:56:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/daemon.h"

void sigall_handler(int signo)
{
	strsignal(signo);
	exit(EXIT_SUCCESS);
}

void initSignal(void)
{
	// only sig_all first
	struct sigaction sig_all;

	sigemptyset(&sig_all.sa_mask);
	sig_all.sa_handler = sigall_handler;
	sig_all.sa_flags = 0;
	sigaction(SIGTERM, &sig_all, NULL);
	sigaction(SIGQUIT, &sig_all, NULL);
	sigaction(SIGUSR1, &sig_all, NULL);
	sigaction(SIGUSR2, &sig_all, NULL);
}
