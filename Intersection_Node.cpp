/*

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.

//////////////////////////////////////////////
Idea:
Method 1: Get length of both lists. Move ptr from  longer of list till remaining length = length of other linked lists.
Then compare ptr1->data and ptr2->data.


Method 2: Move ptr1 and ptr2. If ptr1 == NULL, move it to root2. Similarly, if ptr2 == NULL, move it to root1.
At this point both ptrs will have equal length left to traverse. Compare ptr1->data and ptr2->data.


*/


#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
};


Node* createNode(int val)
{
    Node*temp = new Node;
    temp->data = val;
    temp->next=  NULL;
    return temp;
}


void pusher(Node*root, int val)
{
    if(root == NULL) root = createNode(val);

    while(root->next != NULL)
    {
        root = root->next;
    }

    root->next = createNode(val);
}


void printlist(Node *root)
{
    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
}


Node *rev(Node *root)
{
    Node *prev = NULL;
    Node *curr = root;
    Node *next;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


Node *inter(Node*root1,Node*root2)
{

    /*
    Node *ptr1 = root1;
    Node *ptr2 = root2;

    while(ptr1 != NULL && ptr2 != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

     if(ptr1 == NULL) ptr1 = root2;
     if(ptr2 == NULL) ptr2 = root1;

     while(ptr1!= NULL && ptr2 != NULL)
     {
         ptr1 = ptr1->next;
         ptr2 = ptr2->next;
     }

     if(ptr1 == NULL) ptr1 = root2;
     if(ptr2 == NULL) ptr2 = root1;

     while(ptr1 != NULL)
     {
         if(ptr1->data == ptr2->data) return ptr1;
         ptr1 = ptr1->next;
         ptr2 = ptr2->next;
     }
     return NULL;
     */

     Node *ptr1 = root1;
     Node *ptr2 = root2;

     if(ptr1 == NULL || ptr2 == NULL) return NULL;

     while(ptr1 != ptr2)
     {
         if(ptr1 == NULL)  ptr1 = root2;
         if(ptr2 == NULL) ptr2 = root1;

         if(ptr1 == ptr2) return ptr1;

         ptr1 = ptr1->next;
         ptr2 = ptr2->next;

     }
     return ptr1;


}

int main()
{

    //3->6->9->15->30
    //10->15->30

    Node* newNode;
    Node* head1 = new Node();
    head1->data = 10;
    Node* head2 = new Node();
    head2->data = 3;
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;
    head1->next->next->next = NULL;

    Node*ans = inter(head1,head2);

    printlist(head1);
    cout << endl;
    printlist(head2);
    cout <<endl;

    while(ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }



}
