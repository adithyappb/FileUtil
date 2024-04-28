#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

void listDirectory(const char *path, const char *displayPath) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(path)) == NULL) {
        perror("Unable to open directory");
        return;
    }

    printf("\n%s%s:\n", displayPath, path);

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        printf("%s/%s\n", displayPath, entry->d_name);

        if (entry->d_type == DT_DIR) {
            char newPath[BUFFER_SIZE];
            sprintf(newPath, "%s/%s", path, entry->d_name);
            listDirectory(newPath, displayPath);
        }
    }

    closedir(dir);
}
