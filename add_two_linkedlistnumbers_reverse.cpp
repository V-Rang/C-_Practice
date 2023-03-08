// 3->5->6
// 4->7->8
// Ones digit is at head of lists => 7 -> 2 -> 5 -> 1
//
//


#include<iostream>
#include<map>
#include<set>
using namespace std;

class Node
{
    public:
    int data;
    Node*next;
};

Node*createNode(int val)
{
    Node *temp = new Node();
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void pusher(Node*root,int val)
{
    Node*temp = createNode(val);
    while(root->next != NULL)
    {
        root = root->next;
    }
    root->next = temp;
}

void printlist(Node*root)
{
    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
}


int main()
{
   Node*head1 = createNode(7);
   pusher(head1,1);
   pusher(head1,6);

   Node*head2 = createNode(5);
   pusher(head2,9);
   pusher(head2,2);


   //printlist(head1);
   //cout<<endl;
   //printlist(head2);

   Node*temp1 = head1;
   Node*temp2 = head2;
   int carry = 0;
   Node*headn = createNode(0);
   Node*temp = headn;
   int result;

   while(temp1 || temp2 || carry)
   {
       if(temp1 == NULL && temp2 == NULL)
       {
           result = carry;
       }
       else if(temp1 == NULL && temp2 != NULL)
       {
           result = temp2->data + carry;
           temp2 = temp2->next;
       }
       else if(temp1 != NULL && temp2 == NULL)
       {
           result = temp1->data + carry;
           temp1 = temp1->next;
       }
       else
       {
           result = temp1->data + temp2->data + carry;
           temp1 = temp1->next;
           temp2 = temp2->next;
       }

       carry = result/10;
       temp->next = createNode(result%10);
       temp = temp->next;
   }
   headn = headn->next;

   Node*prev = NULL;
   Node*curr = headn;
   Node*next;

   while(curr != NULL)
   {
       next = curr->next;
       curr->next = prev;
       prev = curr;
       curr = next;
   }

   printlist(head1);
   cout<<endl;
   printlist(head2);
   cout<<endl;
   printlist(prev);
}
