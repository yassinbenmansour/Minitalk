/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:16:34 by yabenman          #+#    #+#             */
/*   Updated: 2024/12/14 06:42:26 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_character(int pid, char c) {
    int	i;

    i = 7; // On commence par le bit de poids fort.
    while (i >= 0) {
        if (c >> i & 1)       // Vérifie si le bit `i` est à 1.
            kill(pid, SIGUSR2); // Envoie SIGUSR2 pour un bit à 1.
        else
            kill(pid, SIGUSR1); // Envoie SIGUSR1 pour un bit à 0.
        i--;
        usleep(500);          // Pause pour ne pas surcharger le serveur.
    }
}

int	check_error(char *str) {
    int	pid;
    int	i;

    pid = ft_atoi(str);  // Conversion du PID en entier.
    if (pid < 0)         // PID négatif non valide.
        return (0);
    i = kill(pid, 0);    // Vérifie l'existence du processus.
    if (i == -1)
        return (0);      // Erreur si aucun processus n'existe.
    return (pid);
}

int	main(int ac, char **av) {
    int		pid;
    char	*str;
    int		i;

    i = 0;
    if (ac == 3) {              // Vérifie le nombre d'arguments.
        pid = check_error(av[1]); // Vérifie le PID.
        if (pid > 0) {
            str = av[2];          // Récupère la chaîne à envoyer.
            while (str[i]) {      // Envoie chaque caractère.
                send_character(pid, str[i]);
                i++;
            }
            ft_putchar('\n');    // Ajoute un retour à la ligne.
        } else
            ft_putstr("incorrect pid! \n");
    } else
        ft_putstr("Syntax error! \n");
    return (0);
}
