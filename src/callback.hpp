
typedef callback_args_t {
  int argc;
  void **args;
} CallbackArgs;

typedef void func(CallbackArgs args) CallbackFunc;