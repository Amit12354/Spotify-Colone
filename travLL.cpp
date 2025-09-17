#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
    int data;
    struct node *next;
};

int main()
{
    struct node a = {1,NULL};
    struct node b = {2,NULL};
    struct node c = {3,NULL};
    a.next = &b;
    b.next = &c;
    struct node *start = &a;
    struct node *temp = start;
    while(temp != NULL)
    {
        cout<<" "<<temp->data;
        temp = temp->next;
    }
}