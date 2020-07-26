#ifndef SBG_STACK_LINE_HPP
#define SBG_STACK_LINE_HPP
#include <stdio.h>

//线性堆栈结构
#define STACK_MAX_LEN 4096   //默认长度4k
template<typename T>
class sbg_stack_line
{
public:
    sbg_stack_line(size_t size = STACK_MAX_LEN )
        :_size(size),
        _top(0),
        _buf(nullptr)
    {
        _buf = new T[_size];
    }

    bool is_empty()
    {
        return _top == 0 ? true :false;
    }

    bool is_full()
    {
        return _top == _size ? true : false;
    }

    void push(const T v)
    {
        if (!is_full())
            _buf[_top++] = v;
    }

    void pop(T& data) {
        if (!is_empty())
            data = _buf[--_top];
    }


private:
    size_t _size;
    size_t _top;
    T *    _buf;
};

#endif // SBG_STACK_LINE_H
