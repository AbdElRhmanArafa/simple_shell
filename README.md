
# Simple Shell

The shell serves as a command-line interface (CLI) that allows users to interact with the operating system by entering commands and receiving output. It provides basic functionality such as executing programs, navigating directories, and managing files.



## Features

- Command parsing: The shell can parse user input and identify commands, arguments, and options.
- Built-in commands: The shell supports a set of built-in commands, such as 'cd' for changing directories, 'pwd' for displaying the current directory, and 'exit' for terminating the shell.
- External command execution: The shell can execute external programs by searching for them in the system's PATH and creating a new process to run the program.
- Command history: The shell maintains a history of previously executed commands, allowing users to easily recall and re-execute them.
- Error handling: The shell provides informative error messages when it encounters issues, such as invalid commands or incorrect syntax

## Getting Started

To get started with this project, you will need to have a C compiler installed on your system. This project has been tested with GCC on Linux.

1. Clone the repository to your local machine.
2. Open a terminal and navigate to the project directory.
3. Compile the code using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
##  Main Flowchart

[![download.png](https://i.postimg.cc/bwVcmFNs/download.png)](https://postimg.cc/YvFs9RFH)

## Usage/Examples
####  Once the shell is running, you can enter commands just like you would in a regular terminal. The shell supports commands with or without arguments and handles errors, including the "end of file" condition (Ctrl+D).
- Flowchart and Problem Solving
    1. Start
    2. Initialize the shell environment
    3. Display the shell prompt
    4. Read user input
    5. Check for EOF (Ctrl+D) or exit command
        - If EOF or exit command is detected, go to step 9
    6. Parse the input to extract the command
    7. Check if the command is an executable
        - If not, print an error message and go back to step 3
    8. Execute the command using execve
        - Pass the environment variables to execve
        - Wait for the command to finish executing
        - Go back to step 3
    10. Terminate the shell
### Simple shell 0.1 +
Handle command lines with arguments
```bash
Simple output:
$ ls -l
total 8
-rw-r--r-- 1 user user  186 May 11 10:00 README.md
-rw-r--r-- 1 user user  662 May 11 10:00 simple_shell.c
```
 ### Simple shell 0.2 +
1. Handle the PATH
2. Fork must not be called if the command doesn’t exist

```bash
Simple output:
$ echo "Hello, world!"
Hello, world!
$ /bin/echo "Hello, world!"
Hello, world!
$ nonexistent_command
sh: 1: nonexistent_command: not found
```
### Simple shell 0.3 +
1. Implement the exit built-in, that exits the shell
2. Usage: exit
3. You don’t have to handle any argument to the built-in exit
```bash
Simple output:
$ exit
```
### Simple shell 0.4 +
1. Implement the env built-in, that prints the current environment
```bash
Simple output:
$ env
USER=user
HOME=/home/user
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
```