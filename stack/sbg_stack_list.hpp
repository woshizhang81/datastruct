#ifndef SBG_STACK_LIST_H
#define SBG_STACK_LIST_H
template<typename T>
struct _SNode{
    T data;
    _SNode<T> * next;
};

template<typename T>
class sbg_stack_list
{
public:
    sbg_stack_list():_top(nullptr)
    {
       _top = new _SNode<T>;
       _top->next = nullptr;
    }
    ~sbg_stack_list()
    {
        reset();
        delete _top;
    }

    bool is_empty(){
        return _top->next == nullptr;
    }
    void push(T v)
    {
        _SNode<T>* newNode = new _SNode<T>;
        newNode->next = _top->next;
        newNode->data = v;
        _top->next = newNode;
    }
    void pop(T & val)
    {
        auto t = _top->next;
        val = t->data;
        _top->next = t->next;
        delete t;
    }
    void reset()
    {
       while(!is_empty())
       {
           T val;
            pop(val);
       }
    }
private:
    _SNode<T> * _top;
};

#endif // SBG_STACK_LIST_H
