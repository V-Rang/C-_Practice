/*

This problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1


 5: (1), (1), (1), (0), (1,1,1).

*/



#include<iostream>
#include <queue>
using namespace std;

#define COUNT 10
#define MARKER -1
struct Node
{
    int data;
    Node *left, *right;
};

Node* createNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
}

void pusher(Node *head, int val)
{
    Node *newn= createNode(val);
    if(head == NULL)
    {
        head = newn;
        return;
    }
    queue<Node*>q;
    q.push(head);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp->left == NULL)
        {
            temp->left = newn;
            return;
        }
        else
        {
            q.push(temp->left);
        }
        if(temp->right == NULL)
        {
            temp->right = newn;
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }

}

void inorder(Node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void print2dlist(Node *root, int space)
{
    if(root == NULL) return;

    space += COUNT;

    print2dlist(root->right,space);
    cout << endl;
    for(int i=COUNT;i<space;i++)
    {
        cout << " ";
    }
    cout << root->data<<"\n";


    print2dlist(root->left,space);
}

void print2d(Node *root)
{
    if(root == NULL) return;
    print2dlist(root,0);

}

bool nunival(Node *root,int &counter)
{
    if(root == NULL) return true;

    bool left = nunival(root->left,counter);
    bool right = nunival(root->right,counter);

    if(left == false || right == false) return false;

    if(root->left && root->data != root->left->data) return false;

    if(root->right && root->data != root->right->data) return false;

    counter += 1;
    return true;
}

void serial(Node *root, vector<int>&ser)
{
    if(root == NULL)
    {
        ser.push_back(MARKER);
        return;
    }
    ser.push_back(root->data);
    serial(root->left,ser);
    serial(root->right,ser);
}

int main()
{
    Node *head = createNode(5);
    pusher(head,1);
    pusher(head,5);
    pusher(head,5);
    pusher(head,5);
    pusher(head,5);
    //pusher(head->right->left,7);
    //pusher(head->right->left,8);


    //inorder(head);

    //print2d(head);

    vector<int>ser;

    serial(head,ser);

    cout << endl;
   // for(int k: ser)
    //{
     //   cout << k <<  " ";
    //}

    //cout << endl;

    int counter = 0;
    bool ans = nunival(head,counter);
    cout << counter;


}
