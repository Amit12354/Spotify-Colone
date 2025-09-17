#include<iostream>
using namespace std;
class Node{
    public:
    Node *prev;
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
    void print(Node *head)
    {
        Node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"->";
           temp = temp->next;
        }
    }
    void insertAtBeging(Node *&head)
    {
        Node *newnode = new Node();
        newnode->data = 5;
        if(head == NULL)
        {
            newnode = head;
        }
        else
        {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        }      
    }
    void insertAtEnd(Node *head)
    {
        Node *newnode = new Node();
        newnode->data = 12;
        Node *temp = head;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        }
        Node* insertAtafter(Node *head)
        {
            Node *curr,*prevnode;
            int val=30,num=102;
            // cout<<"Enter the number";
            // cin>>num;
            // cout<<"Enter the value";
            // cin>>val;
            Node *newnode = new Node();
            newnode->data = num;
            Node *temp = head;
           prevnode = head;
            while(prevnode->data != val)
            {
                prevnode = temp;
                temp = temp->next;
            }
               prevnode->next = newnode;
               newnode->prev = prevnode;
               newnode->next = temp;
               temp->prev = newnode;
        }
   void DeleteAtbening(Node *&head)
   {
      Node *temp = head;
      head = head->next;
      free(temp);
      temp = NULL;
   }
   void DeleteAtEnd(Node *&head)
   {
    Node *temp = head;
    Node *prevnode;
    while(temp->next != NULL ){
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = NULL;
   // temp->prev->next = NULL;
   //free(temp);
   }
 void deleteAtpos(Node *&head)
 {
    Node *temp = head;
    int i = 1,pos = 4;
    while(i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
 }
Node *reverse(Node *head)
{
    Node *current = head;
    Node *nextnode=NULL;
    Node *prev = NULL;
    while(current != NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    return prev;
}
Node* deleteMid(Node* head) {
        // Your Code Here
        Node *slow = head;
        Node *fast = head;
        Node *prev= NULL;
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow  = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete(slow);
        return head;
    }
    void MiddleEle(Node *head)
{
   
    Node *slow = head;
    Node *fast = head;
   
    while(fast != NULL && fast->next != NULL)
    {
      
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<< slow->data;
   
}
int main()
{
    Node *one = new Node(10);
    Node *two = new Node(20);
    Node *three = new Node(30);
    Node *four = new Node(40);
   
    one->next = two;
    two->prev = one;
    two->next = three;
    three->prev = two;
    three->next = four;
    four->prev = three;

    print(one);  
    cout<<endl;
    insertAtBeging(one);
    print(one);
    cout<<endl;
    insertAtEnd(one);
    print(one);
    cout<<endl;
    insertAtafter(one);
    print(one);
    cout<<endl;
    DeleteAtbening(one);
    print(one);
    cout<<endl;
   DeleteAtEnd(one);
    print(one);
    cout<<endl;
    deleteAtpos(one);
    print(one);
     cout<<endl;
  one = reverse(one);
   print(one);
   cout<<endl;
  one= deleteMid(one);
   print(one);
   cout<<endl;
   MiddleEle(one);
}