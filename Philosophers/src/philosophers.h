/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:00:37 by nafarid           #+#    #+#             */
/*   Updated: 2025/06/17 15:23:35 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
/*=========================== Includes ==========================*/
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
/*=========================== Macros =======================*/
# define NUM_ARG "Error: Invalid number of arguments"
# define TAKE_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define IS_DEAD "died"

/*=========================== Data Types ===========================*/

typedef struct s_data	t_data;


typedef struct s_philo
{
	t_data				*data;
	pthread_t			thread;
	int					id;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		meal_lock;
	unsigned long long	last_meal;
	int					eat_count;
	int					finished;
}						t_philo;

typedef struct s_data
{
	int					num_philo;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int					num_must_eat;
	unsigned long long	start_time;
	int					dead;
	int					all_finished;
	int					simulation_stop;

	pthread_t			*thread_id;
	pthread_t			monitor_thread;
	pthread_mutex_t		*forks;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		finish_lock;
	t_philo				*philos;
}						t_data;
/*=========================== function used ========================*/

int						is_philo_valide(int ac, char **av);
int						ft_atoi(char *str);
void					print_error(char *str);
int						init(t_data *philo, int ac, char **av);
unsigned long long		get_time(void);
int						philo_thread(t_data *philo);
void					*check_all_dead(void *data);
int	ft_usleep(unsigned long long time, t_philo *philo);
int	philo_eat(t_philo *philo);
void					*routine(void *data);
int	print_message(t_philo *philo, char *message);
int						philo_think(t_philo *philo);
int						simulation_stopped(t_data *data);
void					stop_simulation(t_data *data);
int						simulation_stopped(t_data *data);
#endif
