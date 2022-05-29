#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define SHM_NAME "shared_memory"
#define SIZE 1024

void handler();

int main() {
    pid_t pid;
    printf("PID %d: parent created\n", getpid());
    int fd;
    void *memory;
    fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd < 0) {
        printf("PID %d: cant open shared memory\n", getpid());
        return -1;
    }
    ftruncate(fd, SIZE);
    memory = mmap(NULL, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
    if ((pid = fork()) == 0) {
        signal(SIGUSR1, handler);
        pause();
        exit(0);
    } else {
        char digits[6];
        printf("PID %d: input 5 digits without spaces: ", getpid());
        scanf("%s", digits);
        strcat(memory, digits);
        printf("PID %d: parent sent %s\n", getpid(), (char *) memory);
        kill(pid, SIGUSR1);
        waitpid(pid, NULL, 0);
        printf("PID %d: parent received min and max: %s\n", getpid(), (char *) memory);
        shm_unlink(SHM_NAME);
    }
    close(fd);
    printf("PID %d: parent exited\n", getpid());
    exit(0);
}

void handler() {
    printf("PID %d: child created\n", getpid());
    int fd;
    void *memory;
    fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);
    memory = mmap(NULL, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
    printf("PID %d: child received %s\n", getpid(), (char *) memory);
    int digits = atoi(memory);
    int digit, minDigit = 9, maxDigit = 0;
    for (int i = 0; i < 5; i++) {
        digit = digits % 10;
        digits /= 10;
        if (digit < minDigit) minDigit = digit;
        if (digit > maxDigit) maxDigit = digit;
    }
    char values[4];
    sprintf(values, "%d %d", minDigit, maxDigit);
    strcpy(memory, values);
    printf("PID %d: child sent min and max: %s\n", getpid(), (char *) memory);
    printf("PID %d: child exited\n", getpid());
    exit(0);
}
