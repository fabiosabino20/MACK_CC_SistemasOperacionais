#include <stdio.h>
#include <stdlib.h>

typedef char *string;

int main(){
    string file1;
    string file2;
    int countsyscall = 0; // Contador para quantidade de syscalls
    printf("cat "); //syscall
    countsyscall++;
    printf("\nDigite o nome do arquivo de entrada : ");
    scanf("%s", file1); //syscall
    countsyscall++;
    FILE *fileRead = fopen(file1, "r"); //syscall
    countsyscall++;
    printf("\nDigite o nome do arquivo da saida : ");
    scanf("%s", file2); //syscall
    countsyscall++;
    FILE *fileWrite = fopen(file2, "w");
    countsyscall++;
    char c = fgetc(fileRead); //syscall
    countsyscall++;
    while (c != EOF){
        fputc(c, fileWrite);
        c = fgetc(fileRead); //syscall
        countsyscall+=2;
    }
    fclose(fileRead); //syscall
    fclose(fileWrite); //syscall
    countsyscall++;
    countsyscall++;
    printf("\nForam feitas %d syscalls", countsyscall); //syscall
    return 0;
}
