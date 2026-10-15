#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        for (int i = 1; i <= 5; i++) {
            printf("Sono il processo figlio %d\n", i);
            fflush(stdout);
            sleep(1);

        }
    } else {
        wait(NULL);
        for (int i = 6; i <= 10; i++) {
            printf("Sono il processo padre %d\n", i);
            fflush(stdout);
            sleep(1);
        }

    }
    return 0;
}
