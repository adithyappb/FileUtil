#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Include string.h for strcmp
#include "listdir.h"
#include "copyfile.h"

#define BUFFER_SIZE 1024  // Define BUFFER_SIZE here or in a common header file

int main() {
    char command[64];

    while (1) {
        printf("Enter command (list, copy, exit): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0)
            break;
        else if (strcmp(command, "list") == 0) {
            char sourcePath[BUFFER_SIZE];
            printf("Enter directory path: ");
            scanf("%s", sourcePath);
            listDirectory(sourcePath, "");
        } else if (strcmp(command, "copy") == 0) {
            char source[BUFFER_SIZE], dest[BUFFER_SIZE];
            int start, end;
            printf("Enter source file path: ");
            scanf("%s", source);
            printf("Enter destination file path: ");
            scanf("%s", dest);
            printf("Enter start percentage: ");
            scanf("%d", &start);
            printf("Enter end percentage: ");
            scanf("%d", &end);
            copyFile(source, dest, start, end);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}
