#include "sbg_circlequeue_test.h"
#include "sbg_circle_queue.hpp"
#include "sbg_queue_list.hpp"
#include <stdio.h>
void test_circle_queue()
{
    sbg_circle_queue<int> queue(26);
    for(char ch = 'a' ; ch <= 'z' ;ch ++)
    {
        if(!queue.is_full())
            queue.enqueue(ch);
    }

    while(!queue.is_empty())
    {
        int ret = queue.dequeue();
        printf("%c",ret);
    }
}

void test_list_queue()
{
    sbg_queue_list<int> queue;
    for(char ch = 'a' ; ch <= 'z' ;ch ++)
    {
            queue.enqueue(ch);
    }
    //queue.reset();
    while(!queue.is_empty())
    {
        int ret = queue.dequeue();
        printf("%c",ret);
    }
}
