#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    FILE *file = fopen("input.txt", "r");
    char line[256];
    char *aux = (char *)malloc(32);
    bool isSafe, increasing;
    int num1 = 0, num2 = 0, result = 0;
    strcpy(aux, " ");

    /*Open file*/
    if(file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    /*Read lines in the file*/
    while(fgets(line, sizeof(line), file) != NULL) {
        isSafe = true;
        sscanf(line, " %d %d", &num1, &num2);
        increasing = (num2 > num1) ? true : false;

        aux = strtok(line, " ");
        aux = strtok(NULL, " ");
        
        while(aux != NULL) {
            sscanf(aux, " %d", &num2);
            if(abs(num2 - num1) < 1 || abs(num2 - num1) > 3) {
                isSafe = false;
                break;
            }
            if(increasing && (num2 < num1)) {
                isSafe = false;
                break;
            }
            if(!increasing && (num2 > num1)) {
                isSafe = false;
                break;
            }
            num1 = num2;
            aux = strtok(NULL, " ");
        }
            if(isSafe) result++;
    }

    printf("Result: %d\n", result);

    exit(0);

}
