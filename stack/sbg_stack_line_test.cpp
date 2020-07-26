#include "sbg_stack_line_test.h"
#include "sbg_stack_line.hpp"
#include "sbg_stack_list.hpp"
#include <unistd.h>
void sbg_stack_line_test()
{
    sbg_stack_line<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);

    while (!stack.is_empty()) {
        int data;
        stack.pop(data);
        printf("%d ",data);
    }

}



void sbg_stack_list_test()
{
    {
        sbg_stack_list<int> stack;

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(6);
        stack.push(7);
        stack.push(8);
        stack.push(9);

        while (!stack.is_empty()) {
            int data;
            stack.pop(data);
            printf("%d ",data);
        }

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.reset();
        while (!stack.is_empty()) {
            int data;
            stack.pop(data);
            printf("%d- ",data);
        }
    }
  //  system('pluse')
    getchar();
}

