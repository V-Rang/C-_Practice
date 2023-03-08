#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *xnode;
};

Node *XOR(Node *x, Node *y)
{
    return reinterpret_cast<Node*>(  reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

void insert(Node **head_ref,int val)
{
    Node *temp = new Node();
    temp->data = val;

    temp->xnode = *head_ref;

    if(  (*head_ref) != NULL)
    {
        (*head_ref)->xnode = XOR(temp, (*head_ref)->xnode );
    }

    *head_ref = temp;
}

void add_at_beg(Node *&head, int val)
{
    Node *temp = new Node;
    temp->data = val;

    temp->xnode = head;

    if(head != NULL )
    {
        head->xnode = XOR(temp,head->xnode);
    }

    head = temp;
}


printlist(Node *head)
{
    Node *prev = NULL;
    Node *next;
    Node *curr = head;

    while(curr != NULL)
    {
        next = XOR(prev,curr->xnode);
        cout << curr->data << " ";
        prev = curr;
        curr = next;
    }
}


void add_at_end(Node *head, int val)
{
    Node *temp = new Node;
    temp->data = val;

    Node*prev = NULL;
    Node*curr = head;
    Node*next;

    while(curr->xnode != prev)
    {
        next = XOR(prev,curr->xnode);
        //cout << curr->data << " ";
        prev = curr;
        curr = next;
    }

    curr->xnode = XOR(prev,temp);
    temp->xnode = XOR(curr,NULL);

}


int get(Node *head, int index)
{
    Node*prev = NULL;
    Node*curr = head;
    Node *next;
    int counter = 0;
    while(counter != index)
    {
        if(curr == NULL) return -1;

        next = XOR(prev,curr->xnode);
        prev = curr;
        curr = next;
        counter += 1;
    }

    return curr->data;
}

int main()
{
    Node * head = NULL;
    insert(&head,10);
    insert(&head,100);
    insert(&head,1000);
    insert(&head,10000);


    add_at_end(head,20);
    add_at_end(head,200);
    add_at_end(head,2000);
    add_at_end(head,20000);

    printlist(head);

    cout << endl;
    cout << get(head,4);

    printlist(head);
}
