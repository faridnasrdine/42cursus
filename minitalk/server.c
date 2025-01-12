#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void bitatoi(int s)
{
    static int bit = 0;
    static int i = 0;

    if (s == SIGUSR1)
        i = i | (1 << (7 - bit)); 
    bit++;

    if (bit == 8)
    {
        printf("%c", i);  
        i = 0;  
        bit = 0; 
    }
}

int main(int ac, char **av)
{
    int pid;
    (void)av;

    pid = getpid();
    printf("%d\n", pid);
    if (ac == 1) {
        signal(SIGUSR1, bitatoi);
        signal(SIGUSR2, bitatoi);

        while (1) {
            pause();
        }
    }
    return 0;
}
