#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <name>\n", argv[0]);
        return 1;
    }

    char *name = argv[1];

    // Create pipe
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }


    // Create child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process

        // Redirect stdout to the write end of the pipe
        dup2(fd[1], STDOUT_FILENO);

        // Close the read end of the pipe
        close(fd[0]);
        close(fd[1]);

        // Execute the command to find the phone number
        execlp("grep", "grep", name, "phonebook.txt", NULL);

        // execlp will only return if an error occurs
        perror("execlp");
        exit(1);
    } else {
        // Parent process

        // Wait for the child to finish
        wait(NULL);

        // Redirect stdin to the read end of the pipe
        dup2(fd[0], STDIN_FILENO);

        // Close the write end of the pipe
        close(fd[0]);
        close(fd[1]);

        // Execute the command to format the output and extract the phone number
        execlp("sed", "sed", "s/ /#/g", NULL);

        // execlp will only return if an error occurs
        perror("execlp");
        exit(1);
    }

    return 0;
}
