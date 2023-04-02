#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a maximum length of 256 characters 
#define MAX_FNAME_LENGTH 256

struct filestructure {
    char filename[MAX_FNAME_LENGTH];
    unsigned int num_of_bytes;
};

// Create an alias for the filestructure struct called filestruct
typedef struct filestructure filestruct;

// Open the specified file in binary write mode using fopen() and store the resulting file pointer in the variable packed_file.
void file_packing(char *packed_file_name, int num_of_files, char **array_of_names) {
    FILE *packed_file = fopen(packed_file_name, "wb"); // wb means binary write mode
    if (packed_file == NULL) {
        printf("Error opening packed file for writing.\n");
        return;
    }

    // Write the number of files to the packed file
    fwrite(&num_of_files, sizeof(int), 1, packed_file);

    // Write the file structures to the packed file
    for (int i = 0; i < num_of_files; i++) {
        FILE *input_file = fopen(array_of_names[i], "rb"); // rb means binary read mode
        if (input_file == NULL) {
            printf("Error opening input file %s for reading.\n", array_of_names[i]);
            continue;
        }

        // Write the file name to the packed file structure
        filestruct file;
        strncpy(file.filename, array_of_names[i], MAX_FNAME_LENGTH);
        file.filename[MAX_FNAME_LENGTH - 1] = '\0'; // Ensure null-termination
        fseek(input_file, 0L, SEEK_END);
        file.num_of_bytes = ftell(input_file); // Get the file size
        fwrite(&file, sizeof(filestruct), 1, packed_file);

        // Copy the contents of the input file to the packed file
        fseek(input_file, 0L, SEEK_SET);
        char buffer[file.num_of_bytes];
        fread(buffer, file.num_of_bytes, 1, input_file);
        fwrite(buffer, file.num_of_bytes, 1, packed_file);

        fclose(input_file);
    }

    fclose(packed_file);
}

// Unpack multiple files that were previously packed into a single binary file
void file_unpacking(char *packed_file_name) {
    FILE *packed_file = fopen(packed_file_name, "rb"); // rb means binary read mode
    if (packed_file == NULL) {
        printf("Error opening packed file for reading.\n");
        return;
    }

    // Create a folder to store the unpacked files
    char folder_name[MAX_FNAME_LENGTH];
    strncpy(folder_name, packed_file_name, MAX_FNAME_LENGTH);
    folder_name[MAX_FNAME_LENGTH - 1] = '\0'; // Ensure null-termination
    char *dot = strrchr(folder_name, '.');
    if (dot != NULL) {
        *dot = '\0'; // Strip the file extension
    }
    strcat(folder_name, "_unpacked"); // Append the string with "_unpacked"
    char command[MAX_FNAME_LENGTH + 10];
    sprintf(command, "mkdir %s", folder_name); // Create new folder with that name
    system(command); // Ask terminal to do this command

    // Read the number of files from the packed file
    int num_of_files;
    fread(&num_of_files, sizeof(int), 1, packed_file);

    // Read the file structures and contents from the packed file
    for (int i = 0; i < num_of_files; i++) {
        filestruct file;
        fread(&file, sizeof(filestruct), 1, packed_file);

        // Create the output file in the unpacked folder
        char output_file_name[MAX_FNAME_LENGTH];
        // Format a string into output_file_name by taking the folder_name string and appending a forward slash (/)
        // Ffilename field of the file structure
        snprintf(output_file_name, MAX_FNAME_LENGTH, "%s/%s", folder_name, file.filename);
        FILE *output_file = fopen(output_file_name, "wb"); // wb means binary write mode
        if (output_file == NULL) {
            printf("Error opening output file %s for writing.\n", output_file_name);
            continue;
        }
        char *buffer = (char *)malloc(file.num_of_bytes);
        // Read file.num_of_bytes bytes of data from the packed file into the buffer
        fread(buffer, 1, file.num_of_bytes, packed_file);
        // Write the contents of the buffer to the output file
        fwrite(buffer, 1, file.num_of_bytes, output_file);
        free(buffer);

        fclose(output_file);
    }

    fclose(packed_file);
}

/*
Compile:
$ gcc -c packing_NGUYEN.c
$ gcc -o main_Uyen_E3.3.out main_Uyen_E3.3.c packing_NGUYEN.o -lm
$ ./main_Uyen_E3.3.out
*/