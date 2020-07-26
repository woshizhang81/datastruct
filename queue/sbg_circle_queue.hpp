#ifndef SBG_CIRCLE_QUEUE_H
#define SBG_CIRCLE_QUEUE_H
#include <unistd.h>
#define CIRCLE_QUEUE_MAXSIZE 4096
//循环队列
template<typename T>
class sbg_circle_queue
{
public:
    sbg_circle_queue(size_t size = CIRCLE_QUEUE_MAXSIZE)
    {
        _size  = size+1; //预留一个 作满判断条件
        _space = new T[_size];
        _front = _rear = 0;
    }
    ~sbg_circle_queue()
    {
        delete[] _space;
    }

    bool is_full()
    {
        return (_rear + 1)% _size == _front;
    }
    bool is_empty()
    {
        return _rear == _front;
    }
    void enqueue(T val)
    {
        _space[_rear] = val;
        _rear = ++_rear % _size;
    }
    T dequeue()
    {
        T &t = _space[_front];
        _front = ++_front % _size;
        return t;
    }
private:
    T * _space ;
    size_t _size;
    size_t _front ; //指向将要出队的 index
    size_t _rear  ; //指向将被压入的 index
};

#endif // SBG_CIRCLE_QUEUE_H
