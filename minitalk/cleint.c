#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int ft_atoi(char *np)
{
    int i = 0;
    int r = 0;
    int s = 1;

    while (np[i] >= 9 && np[i] <= 13 || np[i] == ' ')
        i++;
    if (np[i] == '+' || np[i] == '-')
    {
        if (np[i] == '-')
            s = -1;
        i++;
    }

    while (np[i] >= '0' && np[i] <= '9')
    {
        r = r * 10 + (np[i] - '0');
        i++;
    }

    return s * r;
}

void bitatoi(int pid, char c)
{
    int bit = 0;

    while (bit < 8)
    {
        if (c >> (7 - bit) & 1)
        {
            kill(pid, SIGUSR1);
        }
        else
        {
            kill(pid, SIGUSR2);
        }
        bit++;
        usleep(100);
    }
}

int main(int ac, char **av)
{
    int i = 0;
    int pid;

    if (ac == 3)
    {
        pid = ft_atoi(av[1]);
        while (av[2][i])
        {
            bitatoi(pid, av[2][i]);
            i++;
        }
    }
    return 0;
}
