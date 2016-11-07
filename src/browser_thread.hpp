#include "callback.hpp"

class BrowserThread {
  private:
  	std::queue<std::pair<CallbackFunc, CallbackArgs>> work_queue;
  	std::lock;
  	std::condition_variable;
  public:
  	void post_task(CallbackFunc callback, CallbackArgs args);
};