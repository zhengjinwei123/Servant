/*
 * Author: Broglie 
 * E-mail: yibo141@outlook.com
 */

#ifndef EVENT_H
#define EVENT_H

namespace servant
{

class Event 
{
public:
    typedef void (*Callback)();
    Event(EventLoop *loop, const int fd)
        :this->loop(loop),
         this->fd(fd),
         events(0),
         revents(0)
    { }

    void handleEvent();

    void setReadCallback(const Callback &cb)
    { readCallback = cb; }
    void setWriteCallback(const Callback &cb)
    { writeCallback = cb; }
    void setErrorCallback(const Callback &cb)
    { errorCallback = cb; }
    
    int fd() const 
    { return fd; }
    
private:
    EventLoop *loop;
    const int fd;
    int events;
    int revents;

    Callback readCallback;
    Callback writeCallback;
    Callback errorCallback;
};

}
#endif // EVENT_H