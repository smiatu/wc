//Napisz program w C, który działa jak wc, tylko na pliku. (liczenie słów, bajtów, linii)
//lab8 zad3

#include<stdio.h>
#include <unistd.h>

int main(){
    FILE *fp;
    int words, lines, bytes;
    char buffer[1];
    enum states { WHITESPACE, WORD };
    int state = WHITESPACE;
    words = 0;
    lines = 0;
    bytes = 0;

    fp=fopen("sample.txt","r");
    while (read(fileno(fp),buffer,1) ==1 ) {
        bytes++;
        if (buffer[0] == ' ' || buffer[0] == '\t' || buffer[0] == '\v' || buffer[0] == '\f' || buffer[0] == '\r') {
            state = WHITESPACE;
        } else if (buffer[0] == '\n') {
            lines++;
            state = WHITESPACE;
        } else {
            if (state == WHITESPACE) {
                words++;
            }
            state = WORD;
        }
    }
    printf("lines: %d, words: %d, bytes: %d", lines, words, bytes);
    return 0;
}

