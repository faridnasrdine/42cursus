/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:00:37 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/21 15:53:26 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# define MAX_PHILO 200

typedef struct s_data t_data;

typedef struct s_philo
{
    int             id;
    pthread_t       thread;
    pthread_mutex_t *fork_l;
    pthread_mutex_t *fork_r;
    unsigned long long last_meal;
    int             eat_count;
    t_data          *data;
}   t_philo;

typedef struct s_data
{
    int                 num_philo;
    unsigned long long  time_to_die;
    unsigned long long  time_to_eat;
    unsigned long long  time_to_sleep;
    int                 num_must_eat;
    unsigned long long  start_time;
    int                 dead;
    pthread_t           *thread_id;
    pthread_mutex_t     *forks;
    pthread_mutex_t     print;
    t_philo             *philos;
}   t_data;

int     is_philo_valide(int ac, char **av);
int     ft_atoi(char *str);
int     init(t_data *philo, int ac, char **av);
unsigned long long get_time(void);
int     philo_thread(t_data *philo);
void    *check_all_dead(void *data);

#endif
