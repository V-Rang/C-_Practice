#include<iostream>
#include<vector>


using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node*createNode(int val)
{
    Node*temp = new Node;
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void pusher(Node*root,int val)
{
    if(root == NULL)
    {
        root = createNode(val);
        return;
    }
    while(root->next != NULL)
    {
        root = root->next;
    }
    root->next = createNode(val);
}

void printlist(Node*root)
{
    if(root == NULL) return;

    while(root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
}

void remove_node_from_back(Node*root,int k)
{
    Node*prev;
    Node*curr1 = root;
    Node*curr2=root;

    for(int i=1;i<k;i++) // k-1 steps to go from 1st to kth node
    {
        curr2 = curr2->next;
    }

    while(curr2->next != NULL)
    {
        prev = curr1;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    prev->next = curr1->next;

}

int main()
{
    Node *head = createNode(3);
    pusher(head,4);
    pusher(head,5);
    pusher(head,6);
    pusher(head,7);
    pusher(head,8);
    pusher(head,9);
    pusher(head,10);
    pusher(head,11);
    //3rd from end = 9

    printlist(head);
    cout<<endl;
    remove_node_from_back(head,3);
    printlist(head);

}


