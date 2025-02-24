#ifndef SO_LONG_H
# define SO_LONG_H
typedef struct s_map
{
    char **map;
} t_map;

typedef struct s_var
{
    int x;
    int y;
    int p;
    int e;
    int c;
}              t_var;

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
void check_map_is_valid(t_map *map);
void ft_error(char *str);
int ft_strlen(char *str);
int ft_linelen(char **str);
void filed_elements(t_map *map);

#endif