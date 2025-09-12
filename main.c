#include "Shell.h"

int main(void) {
  // Set up signal handlers once at the start.
  setup_signals();

  // Run the main shell loop.
  shell_loop();

  return 0;
}