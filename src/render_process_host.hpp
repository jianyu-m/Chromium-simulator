
#ifndef RENDER_PROCESS_HOST_H
#define RENDER_PROCESS_HOST_H

#include "channel.hpp"

class RenderProcessHost {
	static int id = 0;
  private:
  	Channel *channel;
  public:
	RenderProcessHost();
	~RenderProcessHost();
  	bool render(int type);
};

#endif