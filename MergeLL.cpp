#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int x)
    {
    data = x;
    next = NULL;
    }
};
void printList(Node *head)
{
    Node *temp = head;
    while(temp->next != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}
Node *sortedMerge(Node *head1,Node *head2)
{
    Node *list = NULL;
    if(head1 == NULL)
    return head2;
    else if(head2 == NULL)
    return head1;
   if(head1->data <= head2->data)
   {
       list = head1;
       list->next = sortedMerge(head1->next,head2);
   }
   else{
    list = head2;
    list->next = sortedMerge(head1,head2->next);
   }
}

int main() {

    Node *head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(40);

    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    Node* res =  sortedMerge(head1, head2);
    printList(res);
}