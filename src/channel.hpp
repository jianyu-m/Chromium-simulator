
#ifndef CHANNEL_H
#define CHANNEL_H

#include "message.hpp"

#define BUF_LEN 1024
#define SHORT_LEN 32
#define NORMAL_LEN 512
#define LONG_LEN 1024
class Channel {
  private:
  	int read_fd;
  	int write_fd;
	char buf[BUF_LEN];
  	/* 0 is read, 1 is write */
  	bool write_or_read;
  	int channel_id;
	void set_non_block(int fd);

  public:
    Channel(int id);
  	bool write_msg(Message *message);
  	bool read_msg(Message *message);
  	int get_id() { return channel_id; }
};

#endif