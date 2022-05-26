#include <iostream>
#include <unistd.h>
#include <sys/fcntl.h>
#include <cstring>

char** split(char *st1, const char *delim = "\n") {
    char** lines = new char * [100];
    for (int i=0; i<100; i++)
        lines[i] = new char[1024] {'\0'};

    int n = 0;
    auto split = strtok(st1, delim);
    while (split != NULL) {
        strcpy(lines[n++], split);
        split = strtok(NULL, delim);
    }
    return lines;
}


int main() {
    char st1[10000];
    read(0, st1, sizeof st1);
    auto lines = split(st1);
    int file1 = open("./output1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int file2 = open("./output2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    char line[100];
    for (int i=0; i<100; i++) {
        if (lines[i][0] == '\0') break;
        auto word = split(lines[i], ":");
        sprintf(line, "UID: %5s, username: %s\n", word[2], word[0]);
        write(file1, line, strlen(line));
        sprintf(line, "GID: %5s, username: %s\n", word[3], word[0]);
        write(file2, line, strlen(line));
    }
    close(file1);
    close(file2);
}