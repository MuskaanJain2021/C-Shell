#include "execute.h"

#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

int execute_command(Command *cmd) {
  // Check for the 'cd' built-in command
  if (strcmp(cmd->name, "cd") == 0) {
    char *dir = (cmd->arg_count > 1) ? cmd->args[1] : getenv("HOME");
    if (dir == NULL) {
      fprintf(stderr, "cd: HOME not set\n");
    } else if (chdir(dir) != 0) {
      perror(cmd->args[1]);
    }
    return 1;
  }

  // Check for 'exit'
  if (strcmp(cmd->name, "exit") == 0) {
    return 0; // Signal to terminate the shell loop
  }

  // Fork and execute external commands
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    return 1;
  }

  if (pid == 0) {
    // Child process: restore default signals
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    execvp(cmd->name, cmd->args);
    // execvp only returns on error
    fprintf(stderr, "%s: %s\n", cmd->name, strerror(errno));
    _exit(127);
  }

  // Parent process: wait for child
  int wstatus;
  for (;;) {
    if (waitpid(pid, &wstatus, 0) < 0) {
      if (errno == EINTR) continue;
      perror("waitpid");
      break;
    }
    if (WIFEXITED(wstatus) || WIFSIGNALED(wstatus)) break;
  }

  return 1; // Continue REPL
}