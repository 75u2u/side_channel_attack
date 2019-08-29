#include <stdio.h>
#include <sys/time.h>
#define ITR_NUM 20000000
#define CHAR_NUM 26

int check_password(char password[], int id) {
    char master[] = "password"; // secret word
    for(; password[id] != '\0'; id++) {
        if(master[id] != password[id]) {
            return 1;
        }
    }
    if(master[id] != '\0') {
        return 1;
    }
    return 0;
}

int main(void) {
    int i,j;
    int id = 0; // Number of string to parse
    struct timeval start, end, past;
    char test[] = "aaaaaaaa";
    long record[CHAR_NUM];
    
    for(i = 0; i < CHAR_NUM; i++) {
        gettimeofday(&start, NULL);
        // compare string many times
        for(j = 0; j < ITR_NUM; j++) {
            check_password(test, id);
        }
        gettimeofday(&end, NULL);
        timersub(&end, &start, &past);
        record[i] = past.tv_usec;
        test[id]++; // next character
    }
    for(i = 0; i < CHAR_NUM; i++) {
        printf("%c:%ld\n", 'a' + i, record[i]);
    }
    return 0;
}
