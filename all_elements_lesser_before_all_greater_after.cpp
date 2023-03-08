//code to create a linked list such that all values < come before and always > come after.

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
    Node*head = createNode(4);
    pusher(head,3);
    pusher(head,12);
    pusher(head,14);
    pusher(head,2);
    pusher(head,-1);
    pusher(head,-65);
    pusher(head,2);
    pusher(head,3);

    Node*root = head;
    Node*head1 = createNode(0);
    Node*head2 = createNode(0);
    Node*temp1 = head1;
    Node*temp2 = head2;
    Node*firstend;

    while(root != NULL)
    {
        if(root->data <= 3)
        {

            temp1->next = createNode(root->data);
            temp1 = temp1->next;
            firstend = temp1;
        }
        else
        {
            temp2->next = createNode(root->data);
            temp2 = temp2->next;

        }
        root = root->next;
    }

    head1 = head1->next;
    head2 = head2->next;
    printlist(head);
    cout << endl;

    printlist(head1);
    cout <<endl;
    printlist(head2);
    cout<<endl;

    firstend->next = head2;
    printlist(head1);


    ////////////////////////////////////////
    //Method2////////

/*
    Node*beforestart = NULL;
    Node*afterstart = NULL;
    Node*root = head;

    while(root != NULL)
    {
        Node*next = root->next;
        if(root->data <= 3)
        {
            root->next = beforestart;
            beforestart = root;
        }
        else
        {
            root->next = afterstart;
            afterstart = root;
        }
        root = next;
    }

    printlist(beforestart);
    cout<<endl;
    printlist(afterstart);

    Node*temp = beforestart;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = afterstart;

    cout <<endl;
    printlist(beforestart);
*/
}
