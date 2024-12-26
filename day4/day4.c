#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkBorders(int i, int j) {
    if(i < 0 || j < 0 || i >= 140 || j >= 140) {
        return 0;
    }
    return 1;
}

/*Check combination*/
int checkXmas(char matrix[140][140], int i, int j, int stepi, int stepj){
    if(matrix[i][j] == 'X') {
        i += stepi;
        j += stepj;
        if(!checkBorders(i, j)) {
            return 0;
        }
        if(matrix[i][j] == 'M') {
            i += stepi;
            j += stepj;
            if(!checkBorders(i, j)) {
                return 0;
            }
            if(matrix[i][j] == 'A') {
                i += stepi;
                j += stepj;
                if(!checkBorders(i, j)) {
                    return 0;
                }
                if(matrix[i][j] == 'S') {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    FILE *file;
    char matrix[140][140];
    int result = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening the file\n");
        exit(1);
    }

    /*Read input*/
    int a = 0;
    while(fgets(matrix[a], sizeof(matrix), file)) {
        a++;
    }

    /*Iterate matrix testing all permutations*/
    for(int i = 0; i < 140; i++) {
        for(int j = 0; j < 140; j++) {
            if(checkXmas(matrix, i, j, 1, 0)) {
                result++;
            }
            if(checkXmas(matrix, i, j, 0, 1)) {
                result++;
            }
            if(checkXmas(matrix, i, j, 1, 1)) {
                result++;
            }
            if(checkXmas(matrix, i, j, -1, 1)) {
                result++;
            }
            if(checkXmas(matrix, i, j, 1, -1)) {
                result++;
            }
            if(checkXmas(matrix, i, j, -1, -1)) {
                result++;
            }
            if(checkXmas(matrix, i, j, -1, 0)) {
                result++;
            }
            if(checkXmas(matrix, i, j, 0, -1)) {
                result++;
            }
        }
    }

    fclose(file);

    printf("The result is: %d\n", result);
    return 0;
}
