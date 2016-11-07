
#ifndef RENDER_PROCESS_H
#define RENDER_PROCESS_H

#include "browser_thread.hpp"

class RenderProcess {
	private:
		BrowserThread *io_thread;
		BrowserThread *main_thread;
	public:
		RenderProcess();
};

#endif