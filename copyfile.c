#include "copyfile.h"
#include <stdio.h>

void copyFile(const char *source, const char *destination, int startPercentage, int endPercentage) {
    // Declare buffer here, outside of any loops or blocks
    //char buffer[BUFFER_SIZE];  // Use BUFFER_SIZE defined in copyfile.h

    FILE *srcFile, *destFile;
    long fileSize, start, end;
    int bytesToCopy;
    char buffer[BUFFER_SIZE];

    srcFile = fopen(source, "rb");
    if (srcFile == NULL) {
        perror("Error opening source file");
        return;
    }

    destFile = fopen(destination, "ab");
    if (destFile == NULL) {
        perror("Error opening destination file");
        fclose(srcFile);
        return;
    }

    fseek(srcFile, 0, SEEK_END);
    fileSize = ftell(srcFile);
    fseek(srcFile, 0, SEEK_SET);

    start = fileSize * startPercentage / 100;
    end = fileSize * endPercentage / 100;

    fseek(srcFile, start, SEEK_SET);

    bytesToCopy = end - start;
    while (bytesToCopy > 0) {
        int bytesRead = fread(buffer, 1, sizeof(buffer), srcFile);
        if (bytesRead <= 0)
            break;
        fwrite(buffer, 1, bytesRead, destFile);
        bytesToCopy -= bytesRead;
    }

    fclose(srcFile);
    fclose(destFile);

    printf("Successfully copied %ld bytes\n", end - start);
}
