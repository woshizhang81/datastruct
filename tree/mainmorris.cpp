#include <iostream>
#include "sbg_tree.hpp"
using namespace std;

int main()
{
    sbg_tree<int> obj;
    obj.insert(1);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.insert(21);
    obj.insert(6);
    obj.insert(19);
    obj.insert(12);
    obj.pre_traverse();
    printf("\n");
    obj.morris_pre_traverse();
    printf("\n");
    obj.morris_post_traverse();
}
