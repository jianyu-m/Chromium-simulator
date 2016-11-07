//
// Created by jianyu on 11/6/16.
//

#include "render_process_host.hpp"

RenderProcessHost::RenderProcessHost() {
    channel = new Channel(id++);
}

RenderProcessHost::~RenderProcessHost() {
    delete channel;
}

bool RenderProcessHost::render(int type) {
    Message *message = nullptr;
    switch (type) {
        case 0: message = new Message(normalmsg);
            break;
        case 1: message = new Message(shortmsg);
            break;
        default:message = new Message(longmsg);
            break;
    }
    channel->write_msg(message);
}