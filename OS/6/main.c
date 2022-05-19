#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define SHMNAME "my_shm"

void dochernij();

int main() {
    int rod = getpid();
    printf("PID процесса: %d\n", rod);
    int SIZE = 2048;
    int fd;
    void *memory;
    fd = shm_open(SHMNAME, O_CREAT | O_RDWR, 0777);
    if (fd < 0) {
        printf("cant open file\n");
        return -1;
    }
    ftruncate(fd, SIZE);
    memory = mmap(NULL, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
    int pid = fork();
    if (pid == 0) {
        signal(SIGUSR1, dochernij);
        pause();
    } else {
        char chislo[100];
        printf("Введите числа: ");
        scanf("%s", chislo);
        strcat(memory, chislo);
        printf("Родитель отправил: %s\n", (char *) memory);
        kill(pid, SIGUSR1);
        waitpid(pid, NULL, 0);
        printf("Родитель принял: %s\n", (char *) memory);
        shm_unlink(SHMNAME);
    }
    close(fd);
    exit(0);
}

void dochernij() {
    int doch = getpid();
    printf("PID процесса: %d\n", doch);
    int SIZE = 1000;
    int fd;
    void *memory;
    fd = shm_open(SHMNAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE);
    memory = mmap(NULL, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
    printf("Ребёнок принял: %s\n", (char *) memory);
    int numbers = atoi(memory);

    int max = 0, min = 99999;

    for (int i = 0; i < 5; i++) {
        int digit = numbers % 10;
        numbers /= 10;
        if (digit < min) min = digit;
        if (digit > max) max = digit;
    }

    char rez[100];
    sprintf(rez, "%d %d", max, min);
    strcpy(memory, rez);
    printf("Процесс %d отправил максимальное число: %d\n", getpid(), max);
    printf("Процесс %d отправил минимальное число: %d\n", getpid(), min);
    printf("Процесс %d завершается\n", getpid());

}
