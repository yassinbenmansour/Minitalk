/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:16:53 by yabenman          #+#    #+#             */
/*   Updated: 2024/12/14 06:42:34 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *sig_info, void *context) {
    static char	ascii;  // Stocke temporairement le caractère.
    static int	i;      // Compte les bits reçus.

    (void)context;
    signum -= SIGUSR1;      // Convertit le signal en 0 ou 1.
    if (g_pid != sig_info->si_pid) { // Nouveau client ?
        ascii = 0;          // Réinitialise les variables.
        i = 0;
        g_pid = sig_info->si_pid;
    }
    if (signum)             // Si `signum == 1`, ajoute un bit à 1.
        ascii = ascii << 1 | 1;
    else                    // Sinon, ajoute un bit à 0.
        ascii = ascii << 1 | 0;
    i++;
    if (i == 8) {           // Si 8 bits sont reçus :
        ft_putchar(ascii);  // Affiche le caractère.
        i = 0;
        ascii = 0;          // Réinitialise pour le prochain caractère.
    }
}

int	main(void) {
    struct sigaction	g;

    g.sa_sigaction = &handler; // Associe le gestionnaire de signal.
    g.sa_flags = SA_SIGINFO;   // Active les infos supplémentaires (siginfo_t).
    sigaction(SIGUSR1, &g, NULL);
    sigaction(SIGUSR2, &g, NULL);
    ft_putstr("PID = ");
    ft_putnbr(getpid());      // Affiche le PID.
    ft_putstr("\n");
    while (1)
        pause();              // Attend les signaux.
}
