### FileUtil
FileUtil is a command-line utility program designed to perform file-related operations such as listing directory contents and copying files. It provides a simple and efficient way to manage files and directories through a command-line interface.

## Features:
List Directory Contents: View the contents of a directory, including files and subdirectories, in a hierarchical structure.
Copy Files: Copy a portion of a file to another file based on specified start and end percentages.

## File Structure:
>main.c: Contains the main function that interacts with the user to execute commands.
>listdir.h / listdir.c: Functions for listing directory contents recursively.
>copyfile.h / copyfile.c: Functions for copying files with specified start and end percentages.

Usage:
>Compilation: Compile the program using a C compiler such as gcc.
-> gcc main.c listdir.c copyfile.c -o FileUtil

>Execution: Run the compiled executable.

Commands:
1) list: List the contents of a directory.
2) copy: Copy a portion of a file to another file.
3) exit: Exit the program.
-> Follow on-screen prompts to execute commands and provide necessary inputs.
