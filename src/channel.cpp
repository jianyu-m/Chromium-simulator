//
// Created by jianyu on 11/6/16.
//

#include <unistd.h>
#include <iostream>
#include <cstring>
#include <fcntl.h>
#include "channel.hpp"

Channel::Channel(int id) {
    int fd[2];
    pipe(fd);
    read_fd = fd[0];
    write_fd = fd[1];
    channel_id = id;
    set_non_block(read_fd);
}

void Channel::set_non_block(int fd) {
    int retval = fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK);
    if (retval != 0) {
        std::cout << "set non-blocking failed\n";
    }
}

bool Channel::read_msg(Message *message) {
    int read_len = read(read_fd, buf, BUF_LEN);
    if (read_len <= 0) {
        return false;
    }
    if (read_len < sizeof(MessageHeader)) {
        std::cout << "msg error\n";
        return false;
    }
    MessageHeader *header = (MessageHeader*)buf;
    message->header.type = header->type;
    message->header.len = read_len;
    //simulate copy
    return true;
}

bool Channel::write_msg(Message *message) {
    memcpy(buf, message->header, sizeof(MessageHeader));
    int msg_len = sizeof(MessageHeader);
    switch (message->header.type) {
        case shortmsg: msg_len = SHORT_LEN;
            break;
        case normalmsg: msg_len = NORMAL_LEN;
            break;
        case longmsg: msg_len = LONG_LEN;
            break;
        default:msg_len = NORMAL_LEN;
        std::cout << "empty msg sent\n";
    }
    write(write_fd, buf, msg_len);
    delete message;
    return true;
}