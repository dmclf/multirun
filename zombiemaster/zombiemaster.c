
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


void sig_receive_zombie_master(int signum);
void sig_receive_zombie(int signum);

int stop = 0;

int main(int argc, char* const* argv) {
    struct sigaction ssig;
    memset(&ssig, 0, sizeof ssig);
    int nbr_processes = 1;
    printf("Executing zombie master\n");
    for (int i = 0; i < nbr_processes; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Executing zombie %d\n", i);
            ssig.sa_handler = sig_receive_zombie;
            if (sigaction(SIGINT, &ssig, NULL))
                exit(-2);
            if (sigaction(SIGTERM, &ssig, NULL))
                exit(-2);
            while (!stop) {
                sleep(1);
            }
            printf("Zombie %d sleeps a little\n", i);
            sleep(3);
            printf("Hi! I'm zombie %d and I die\n", i);
            exit(0);
        } else {
            // nothing
        }
    }

    ssig.sa_handler = sig_receive_zombie_master;
    if (sigaction(SIGINT, &ssig, NULL))
        exit(-2);
    if (sigaction(SIGTERM, &ssig, NULL))
        exit(-2);

    while (!stop) {
        sleep(1);
    }
    printf("Zombie master sleeps a little\n");
    sleep(3);
    
    printf("Hi! I'm zombie master and I die\n");
    exit(0);
}

void sig_receive_zombie_master(int signum) {
    printf("Me zombie master, me received %s bullet in the head\n", strsignal(signum));
    stop = 1;
}

void sig_receive_zombie(int signum) {
    printf("Me zombie, me received %s bullet in the head\n", strsignal(signum));
    stop = 1;
}
