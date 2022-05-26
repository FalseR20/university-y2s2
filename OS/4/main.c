#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Вариант 9
 * 0 1 1 2 2 5 6
 * 1 default
 *  2 $whoami
 *   4
 *   5
 *    6
 *     7
 *  3
 */


int main() { // 1
    pid_t pid;
    printf("+1. PID = %d <- PPID = %d\n", getpid(), getppid());

    if ((pid = fork()) == -1) // 2
        printf("Ошибка!\n");
    else if (pid == 0) {
        printf(" +2. PID = %d <- PPID = %d\n", getpid(), getppid());

        if ((pid = fork()) == -1) // 4
            printf("Ошибка!\n");
        else if (pid == 0) {
            printf("  +4. PID = %d <- PPID = %d\n", getpid(), getppid());
            printf("  -4. PID = %d <- PPID = %d\n", getpid(), getppid());
            exit(0); // 4
        }
        sleep(1);

        if ((pid = fork()) == -1) // 5
            printf("Ошибка!\n");
        else if (pid == 0) {
            printf("  +5. PID = %d <- PPID = %d\n", getpid(), getppid());
            if ((pid = fork()) == -1) // 6
                printf("Ошибка!\n");
            else if (pid == 0) {
                printf("   +6. PID = %d <- PPID = %d\n", getpid(), getppid());

                if ((pid = fork()) == -1) // 7
                    printf("Ошибка!\n");
                else if (pid == 0) {
                    printf("    +7. PID = %d <- PPID = %d\n", getpid(), getppid());
                    printf("    -7. PID = %d <- PPID = %d\n", getpid(), getppid());
                    exit(0); // 7
                }
                sleep(1);

                printf("   -6. PID = %d <- PPID = %d\n", getpid(), getppid());
                exit(0); // 6
            }
            sleep(2);

            printf("  -5. PID = %d <- PPID = %d\n", getpid(), getppid());
            exit(0); // 5
        }
        sleep(3);

        printf(" -2. PID = %d <- PPID = %d --> $ whoami\n", getpid(), getppid());
        execl("/bin/whoami", "", NULL); // 2
    }
    sleep(5);

    if ((pid = fork()) == -1) // 3
        printf("Ошибка!\n");
    else if (pid == 0) {
        printf(" +3. PID = %d <- PPID = %d\n", getpid(), getppid());
        printf(" -3. PID = %d <- PPID = %d\n", getpid(), getppid());
        exit(0); // 3
    }
    sleep(1);

    printf("-1. PID = %d <- PPID = %d\n", getpid(), getppid());
    exit(0); // 1
}
