/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabenman <yabenman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 08:13:32 by yabenman          #+#    #+#             */
/*   Updated: 2024/12/14 08:14:02 by yabenman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	handle_signal(int signum) {
    if (signum == SIGINT)
        printf("SIGINT reçu (Ctrl+C) !\n");
}

int	main() {
    signal(SIGINT, handle_signal);

    printf("Appuyez sur Ctrl+C pour envoyer SIGINT...\n");

    while (1) {
        printf("En attente de signal...\n");
        sleep(1);
    }

    return 0;
}
