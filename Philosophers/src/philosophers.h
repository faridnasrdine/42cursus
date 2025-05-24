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
# include <string.h>
# define MAX_PHILO 200

typedef struct s_data t_data;

typedef struct s_philo
{
    t_data              *data;
    pthread_t           thread;
    int                 id;
    pthread_mutex_t     *fork_l;
    pthread_mutex_t     *fork_r;
    pthread_mutex_t     meal_lock;
    unsigned long long  last_meal;
    int                 eat_count;
    int                 finished;
}  t_philo;

typedef struct s_data
{
    int                 num_philo;
    unsigned long long  time_to_die;
    unsigned long long  time_to_eat;
    unsigned long long  time_to_sleep;
    int                 num_must_eat;
    unsigned long long  start_time;
    int                 dead;
    int                 all_finished;
    
    pthread_t           *thread_id;
    pthread_t           monitor_thread;
    pthread_mutex_t     *forks;
    pthread_mutex_t     dead_lock;
    pthread_mutex_t     print_lock;
    pthread_mutex_t     finish_lock;
    t_philo             *philos;
}   t_data;

// Function prototypes
int                    is_philo_valide(int ac, char **av);
int                    ft_atoi(char *str);
int                    init(t_data *philo, int ac, char **av);
unsigned long long     get_time(void);
int                    philo_thread(t_data *philo);
void                   *monitor_routine(void *data);
int                    ft_usleep(unsigned long long time);
void                   eating(t_philo *philo);
void                   *routine(void *data);
void                   print_message(t_philo *philo, char *message);
int                    is_dead(t_data *data);
void                   set_dead(t_data *data);
void                   ft_all_clean(t_data *philo);
void                   clean(t_data *philo);
int                    one_philo(t_data *philo);

#endif
