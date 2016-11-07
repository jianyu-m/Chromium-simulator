
#include "message.hpp"

class Channel {
  private:
  	int read_fd;
  	int write_fd;
  	/* 0 is read, 1 is write */
  	bool write_or_read;
  	int channel_id;
  public:
  	bool write(Message *message);
  	bool read(Message *message);
  	int get_id();
}