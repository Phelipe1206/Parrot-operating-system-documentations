#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child = fork();
    if (child == 0) {
        // Child process
        while (1) {
            printf("Child running...\n");
            sleep(1);
        }
    } else {
        // Parent process
        sleep(5); // Let the child run for a while
        kill(child, SIGKILL); // Send SIGKILL to terminate child
        printf("Child process killed\n");
    }
    return 0;
}
