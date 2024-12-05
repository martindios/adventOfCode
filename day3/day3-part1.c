#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#include <stdio.h>
#include <regex.h>
#include <string.h>

int result = 0;

int useRegex(char* textToCheck) {
    regex_t compiledRegex;
    int reti;
    char messageBuffer[100];
    size_t maxMatches = 3; 
    regmatch_t matches[maxMatches];

    reti = regcomp(&compiledRegex, "mul\\(([0-9]+),([0-9]+)\\)", REG_EXTENDED | REG_ICASE);
    if (reti) {
        perror("Error compiling the regex\n");
        return -2;
    }

    const char *currentPosition = textToCheck;
    while ((reti = regexec(&compiledRegex, currentPosition, maxMatches, matches, 0)) == 0) {
        char num1[10], num2[10];
        int len1 = matches[1].rm_eo - matches[1].rm_so;
        int len2 = matches[2].rm_eo - matches[2].rm_so;

        strncpy(num1, currentPosition + matches[1].rm_so, len1);
        strncpy(num2, currentPosition + matches[2].rm_so, len2);
        num1[len1] = '\0';
        num2[len2] = '\0';

        result += atoi(num1) * atoi(num2);

        currentPosition += matches[0].rm_eo;
    }

    if (reti == REG_NOMATCH) {
        printf("No matches found.\n");
    } else {
        regerror(reti, &compiledRegex, messageBuffer, sizeof(messageBuffer));
        fprintf(stderr, "Error in regex match: %s\n", messageBuffer);
    }

    regfree(&compiledRegex);
    return (reti == REG_NOMATCH) ? 1 : -3;
}


int main() {
    FILE *file;
    char line[5000];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening the file\n");
        exit(1);
    }

    while(fgets(line, sizeof(line), file) != NULL) {
        useRegex(line);
    }

    fclose(file);

    printf("The result is: %d\n", result);
    return 0;
}
