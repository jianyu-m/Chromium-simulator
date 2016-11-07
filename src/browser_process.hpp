
#define IO_THREAD 10000
#define PROCESS_THREAD 10001
#define MAIN_THREAD 10002

class BrowserProcess {
  private:
  	BrowserThread *io_thread;
  	//BrowserThread *process_thread;
  	BrowserThread *main_thread;
  public:
  	void post_task(int thread_id, CallbackFunc callback, CallbackArgs args);
  	RenderProcess create_render();
};