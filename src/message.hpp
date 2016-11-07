
#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstdint>

typedef enum message_type_t {
    normalmsg,
    shortmsg,
    longmsg
} MessageType;

typedef struct message_header_t {
    uint32_t len;
    MessageType type;
} MessageHeader;

class Message {
public:
    MessageHeader header;
    Message(MessageType type) {
        header.type = type;
        header.len = 100;
    }
};

#endif