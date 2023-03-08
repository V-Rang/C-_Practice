#include <iostream>
#include<queue>
#include <vector>

using namespace std;

#define COUNT 10
#define MARKER -1

struct Node
{
    int data;
    Node *left, *right;
};


Node *createNode(int val)
{
    Node *temp = new Node();
    temp->data = val;;
    temp->left = temp->right = NULL;
    return temp;
}

Node *InsertNode(Node*root, int val)
{
    if(root==NULL)
    {
        root = createNode(val);
        return root;
    }

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp->left == NULL)
        {
            temp->left = createNode(val);
            return root;
        }
        else
        {
            q.push(temp->left);
        }

        if(temp->right == NULL)
        {
            temp->right = createNode(val);
            return root;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

void inorder(Node *root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void print2dlist(Node*root,int space)
{
    if(root == NULL) return;


    space += COUNT;

    print2dlist(root->right,space);
    cout << endl;

    for(int i=COUNT;i<space;i++)
    {
        cout << " ";
    }

    cout << root->data << "\n";

    print2dlist(root->left,space);
}

void print2d(Node *root)
{
    print2dlist(root,0);
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


void deserial(Node* &root,vector<int>s, int &i)
{
    if(i >= s.size()) return;
    if(s[i]== -1)
    {   i ++;
        return;
    }
    root=createNode(s[i]);
    i++;
    deserial(root->left,s,i);
    deserial(root->right,s,i);
}

//using queues
void deserial2(Node *&root, queue<int>&s)
{
    if(s.empty()) return;

    if(s.front()==-1)
    {   s.pop();
        return;
    }

    root = createNode(s.front());
    s.pop();
    deserial2(root->left,s);
    deserial2(root->right,s);
}

int main()
{
    Node *head = createNode(1);
    InsertNode(head,2);
    InsertNode(head,3);
    InsertNode(head->left,4);
    InsertNode(head->left,5);
    InsertNode(head->right,6);
    InsertNode(head->right->left,7);
    InsertNode(head->right->left,8);

//    inorder(head);

//    print2d(head);
    vector<int> s;
    serial(head,s);

   // for(auto k: s)
    //{
     //   cout << k << " ";
    //}
    Node *root2 = NULL;
    int i = 0;
    deserial(root2,s,i);
    inorder(root2);
    //print2d(root2);
}
