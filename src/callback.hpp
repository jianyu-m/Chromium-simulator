
#ifndef CALLBACK_H
#define CALLBACK_H

typedef struct callback_args_t {
  int argc;
  void **args;
} CallbackArgs;

typedef void (*CallbackFunc)(CallbackArgs args);

#endif