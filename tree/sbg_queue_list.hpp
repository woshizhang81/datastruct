#ifndef SBG_QUEUE_LIST_H
#define SBG_QUEUE_LIST_H

template<typename T>
struct QNode{
  T     data;
  QNode<T> *next;
};

template<typename T>
class sbg_queue_list
{
public:
    sbg_queue_list(){
        _front = _rear = new QNode<T>;
        _front->next = nullptr;
    }
    ~ sbg_queue_list(){
        reset();
        delete _front;
    }

    bool is_empty()
    {
        return _front == _rear;
    }
    void enqueue(T val)
    {
        QNode<T> * cur = new  QNode<T>;
        cur->data = val;
        cur->next = nullptr;
        _rear->next = cur;
        _rear = cur;
    }

    T dequeue()
    {
        T tmp ;
        if (_front->next == _rear)
        {
            tmp = _rear->data;
            delete _rear;
            _rear = _front;
            _front->next = nullptr;
        }else {
            auto cur = _front->next;
            tmp = cur->data;
            _front->next = cur->next;
            delete cur;
        }
        return tmp;
    }

    void reset(){
        QNode<T> *head = _front->next;
        _front->next = nullptr;
        _rear = _front;
        while(head)
        {
            auto nxt = head->next;
            delete head;
            head = nxt;
        }
    }
private:
    QNode<T> * _front;
    QNode<T> * _rear;
};

#endif // SBG_QUEUE_LIST_H
