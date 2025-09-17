#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {
    int data;
    struct node *next;
};
void printlinkedlist(struct node *p)
{
    while(p != NULL)
    { 
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"\n";
}
int countNode(struct node *p)
{
    int count=0;
    if(p == NULL)
    return -1;
    while(p != NULL)
    {
      count++;
        p=p->next;
    }
    return count;

}
bool searchnode(struct node *p,int key)
{
    while(p != NULL)
    {
        if(p->data==key)
        return true;
        else p=p->next;
    }
        return false;
}
void searchlastele(struct node *p)
{
    
    while(p!=NULL)
    {
        if(p->next==NULL)
    {
       cout<<"last element is->"<<p->data<<"\n";
   }
        p=p->next;
    }
}
 void seclastele(struct node *p)
 {
     while(p->next->next != NULL)
         {
        p=p->next;
         }
         cout<<"sec last element->"<<p->data<<"\n";
     }
void alternatenode(struct node *p)
{
    int count = 0;
    while(p != NULL)
    {
        if(count % 2 == 0)
        {
        cout<<" "<<"alternative node is->"<<p->data<<endl;
    }
        count++;
        p=p->next;
    }
}
struct node* insertion(struct node *p,int key)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data = key;     
    if(temp == NULL)
    {
        p = temp;
        p->next = NULL;
    }
    else
    temp->next = p;
p = temp;
}
struct node *postion(struct node *p)
{
struct node *temp,*NewNode;
struct node *prev;
int val,num;
cout<<"Enter the data";
cin>>num;
cout<<"Enter the data before which is inserted in value";
cin>>val;

NewNode = (struct node *)malloc(sizeof (struct node));
NewNode->data = num;
temp = p;
while(temp->data != val)
{
    prev = temp;
    temp = temp->next;
}
prev->next = NewNode;
NewNode->next = temp;
return p;
}
   int main()
{
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *start = NULL;
    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three = (struct node*)malloc(sizeof(struct node));
    if(one != NULL)
    {
        one->data = 1;
        one->next = two;
    }
    if( two != NULL){
    two->data = 2;
    two->next  = three;
       }
       if(three != NULL)
       {
           three->data = 3;
           three->next = NULL;
       }
       start = one;
      printlinkedlist(start);
      int cnt = countNode(start);
      cout<<"Total Node is"<<cnt<<"\n";
      int status = searchnode(start,3);
      if(status==true)
      cout<<"element is found"<<"\n";
      else
      cout<<"Element is not found";
      searchlastele(start);
       seclastele(start);
       alternatenode(start);
       start  =  insertion(start,5);
      printlinkedlist(start);
      start =   postion(start);
        printlinkedlist(start);
      return 0;
}