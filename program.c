#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "greet_controller.h"

char *(*action_delegate)(char*);

int main() {
  void *handle = dlopen("./greet_controller.so", RTLD_LAZY);
  if (!handle) {
    fprintf(stderr, "%s\n", dlerror());
    exit(1);
  }
  action_delegate = dlsym(handle, "hello_action");
  if (!action_delegate) {
    fprintf(stderr, "%s\n", dlerror());
    exit(1);
  }
  char *input = "input";
  char *ar = action_delegate(input);
  printf("Action returned:\n%s\n", ar);
  free(ar);
}
