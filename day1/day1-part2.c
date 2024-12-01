#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* For quicksort */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char **argv) {
    /* Declaration and initialization of variables */
    FILE *file;
    char line[32];
    int list1[1000], list2[1000];
    int n = sizeof(list1) / sizeof(list1[0]), result = 0;

    /* Opening the file */
    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening the file\n");
        exit(1);
    }

    /* Storing data in the lists */
    for(int i = 0; fgets(line, sizeof(line), file); i++) {
        sscanf(line, "%d %d", &list1[i], &list2[i]);
    }

    int counter = 0;
    for(int i = 0; i < n; i++) {
        counter = 0;
        for(int j = 0; j < n; j++) {
            if(list1[i] == list2[j]) {
                counter++;
            }
        }
        result += list1[i] * counter;
    }



    printf("The result is: %d\n", result);
}

