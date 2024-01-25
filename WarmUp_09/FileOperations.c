#include <stdio.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    char line[100];

    // Writing to the file
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    fprintf(file, "Hello, World!");
    fclose(file);

    // Reading from the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
