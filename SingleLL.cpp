#include<iostream>
#include<vector>
using namespace std;
class node {
public:
    int data;
    node *next;
node()
{
    this->data = 0;
    this->next = NULL;
}
node(int data)
{
    this->data = data;
    this->next = NULL;
}
};
void print(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"\n";
}
// node *insertAtrandomanddelte(node *head)
// {
// 	node *temp,*prev,*demo;
// 	int val,num;
// 	 cout<<"Enter the data!";
//   cin>>num;
//   cout<<"Enter the val";
//   cin>>val;
//   temp = head;
//   node *newnode = new node();
//   newnode->data = num;
//   prev = head;

//   while(temp->data != val)
//   {
//   	prev = temp;
//   	temp = temp->next;
  
//   }
  
//   prev->next = newnode;
//   newnode->next = temp;

//   free(temp->next);
//  temp->next = NULL;

//  newnode->next = temp;	
//  head = newnode;
//   return head;
  
// }
// node *deleteAtbegning(node *head)
// {
//     node *temp = head;
//     head = head->next;
//     free(temp);
//     temp = NULL;
//     return head;
// }
// node *deleteAtEnd(node *head)
// {
//     node *prev = head;
//     node *temp = head;
//     while(temp->next->next != NULL)
//     { 
//         temp = temp->next;
//     }
//     free(temp->next);
//     temp->next = NULL;
//     return head;
// }
// int getMiddleElement(struct node *p)
// {
// 	vector <int> v;
//     node *temp = p;
// 	while(temp != NULL)
// 	{
// 		v.push_back(temp->data);
// 		temp = temp->next;
// 	}
// 	int middleIndex = v.size()/2;
// 	return v[middleIndex];
// }
node * deletemiddleElement(node *head)
{
    node *slow = head;
    node *fast = head;
    node *prev = NULL;
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }
    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete(slow);
return head;
}
int main()
{
   node *one = new node(10);
   node *two = new node(20);
   node *three = new node(30);
   node *four = new node(40);
   one->next = two;
   two->next = three;
   three->next = four;
   
   print(one);
//    insertAtrandomanddelte(one);
//    print(one);
//   one= deleteAtbegning(one);
//    print(one);
//   one = deleteAtEnd(one);
//   print(one);
//     cout<<getMiddleElement(one)<<endl;
   deletemiddleElement(one);
   print(one);
}