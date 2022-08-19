#include <stdio.h>
#include <stdlib.h>

typedef char *string;

int main(){
    string filename;
    int countsyscall = 0; // Contador para quantidade de syscalls
    printf("cat "); //syscall
    countsyscall++;
    scanf("%s", filename); //syscall
    countsyscall++;
    FILE *file = fopen(filename, "r"); //syscall
    countsyscall++;
    char c = fgetc(file); //syscall
    countsyscall++;
    while (c != EOF){
        printf("%c", c); //syscall
        c = fgetc(file); //syscall
        countsyscall+=2;
    }
    fclose(file); //syscall
    countsyscall++;
    countsyscall++;
    printf("\nForam feitas %d syscalls", countsyscall); //syscall
    return 0;
}
