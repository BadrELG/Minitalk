#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static char chara = 0; // Variable Globale pour le caractere en court de build
static int bit_count = 0; // Variable Globale pour le nombre de bits reçu (0 a 7)


void signal_handler(int signal)
{
    chara *= 2;
    if (signal == SIGUSR2)
    {
      chara = chara | 1;
    }
    bit_count++;
    if (bit_count == 8)
    {
        ft_printf("%c", chara);
        chara = 0;
        bit_count = 0;
    }
    
}

void setup_signals(void)
{
    struct sigaction sa;

    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

int main(void)
{
    ft_printf("Pid Server : %d\n", getpid());
    setup_signals();
    while (1)
        pause();
}