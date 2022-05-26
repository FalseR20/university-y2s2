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
    for (int i=0; i<100; i++) {
        if (lines[i][0] == '\0') break;
        auto word = split(lines[i], ":");
        if ((atoi(word[2]) % 2) == 0) write(1, word[2], 1024);
        else write(2, word[2], 1024);
        write(1,"\n", 1);
    }
}