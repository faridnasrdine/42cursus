#include "so_long.h"
void ft_error(char *str)
{
    write(1, str, ft_strlen(str));
    exit(1);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_linelen(char **str)
{
    int i;

    i = 0;
    while (str[i] != NULL)
        i++;
    return (i);
}
void filed_elements(t_map *map)
{
    int x;

    while(map->map[x])
    {
        free(map->map[x]);
        x++;
    }
    free(map->map[x]);
        ft_error("Error\nfiled elements\n");
    
}