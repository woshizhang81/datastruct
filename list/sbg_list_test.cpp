#include "sbg_list_test.h"
#include "sbg_list.hpp"
#include "sbg_list_tail.hpp"
#include <iostream>
using namespace std;

void list_tail_test_case()
{
    sbg_tail::sbg_list<int> list; //带有尾的单向连表
    list.push_back(-1);
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(6);
    list.push(7);
    list.push(8);
    list.push(9);
    cout<<"length="<<list.length()<<endl;
    list.push_back(11);
    list.push_back(12);
    list.push_back(13);
    list.push_back(14);
     cout<<"length="<<list.length()<<endl;
    list.push(100);
    list.push(101);
     cout<<"length="<<list.length()<<endl;
    list.show_list();
    list.pop();
    list.show_list();
     cout<<"length="<<list.length()<<endl;
    list.reverse();
     cout<<"length="<<list.length()<<endl;
    list.push_back(1001);
    list.push(1111);
     cout<<"length="<<list.length()<<endl;
    list.show_list();
    cout << "Hello World!" << endl;
}


void list_test_case()
{
    sbg_list<int> list; //带有尾的单向连表
    list.push(1);
    list.push(2);
    list.push(32);
    list.push(32);
    list.push(5);
    list.push(64);
    list.push(7);
    list.push(81);
    list.push(9);
    cout<<"length="<<list.length()<<endl;
    cout<<"length="<<list.length()<<endl;
    list.push(100);
    list.push(101);
    cout<<"length="<<list.length()<<endl;
    list.show_list();
    list.pop();
    list.show_list();
    cout<<"length="<<list.length()<<endl;
    list.reverse();
    cout<<"length="<<list.length()<<endl;
    list.push(1111);
    cout<<"length="<<list.length()<<endl;
    list.show_list();

    cout << "-----------------------------"<<endl;
    _Node<int> *node = list.find(3000);
    if(node == nullptr)
    {
        cout <<"not find "<<endl;
    }else {
        cout << "node val = "<< node->val<<endl;
        cout << "node next = "<< node->next<<endl;
        list.delete_node(node);
        list.show_list();
    }

    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
    //list.sort_changevalue();
    list.sort_changevalue();
    list.show_list();
    list.push(118);
    list.push(122);

    list.push(15);
    list.push(156);
    list.push(13);
    list.push(142);
    list.show_list();
    list.sort_changenode();
    list.show_list();

}
