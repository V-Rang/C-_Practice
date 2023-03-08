//code to create a linked list such that all values < come before and always > come after.

#include<iostream>
#include<map>
#include<set>
#include<stack>
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

bool isPalindrome(Node*root)
{
    //Method1 - reverse and compare original to reversed
/*
    if(root == NULL)
    {
        return NULL;
    }
    int counter = 1;
    Node*temp = root;
    Node*root2 = new Node;
    root2->data = temp->data;
    Node*temp2 = root2;
    temp = temp->next;

    while(temp != NULL)
    {
        temp2->next = new Node;
        temp2->next->data  = temp->data;
        temp2  = temp2->next;
        temp = temp->next;
        counter += 1;
    }

    //printlist(root2);
    //cout<<endl;
    //printlist(root);
    //cout<<endl;

    Node*prev = NULL;
    Node*curr = root2;
    Node*next;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //printlist(prev);
    int i = 0;
    while(i<counter/2)
    {
        if(prev->data != root->data)
            return false;
        prev = prev->next;
        root = root->next;
        i += 1;
    }

    return true;
*/

//Method 2 Slow runner and fast runner.
    stack<int>stackboi;
    Node*slowrunner = root;
    Node*fastrunner = root;

    while(fastrunner != NULL || fastrunner->next != NULL)
    {
        stackboi.push(slowrunner->data);
        slowrunner = slowrunner->next;
        fastrunner = fastrunner->next->next;
    }
    //stackboi.push(slowrunner->data);

    if(fastrunner != NULL)
    {
        slowrunner = slowrunner->next;
    }


/*
    while(!stackboi.empty())
    {
        cout << stackboi.top()<< " ";
        stackboi.pop();
    }
*/



/*
    while(slowrunner != NULL)
    {
        if(stackboi.top() != slowrunner->data)
        {
            return false;
        }
        slowrunner = slowrunner->next;
        stackboi.pop();
    }
*/
    return true;

}

Node* copyofnode(Node*root)
{
    if(root == NULL)
    {
        return NULL;
    }
    Node*newn = new Node;
    newn->data = root->data;
    Node*temp = newn;
    root = root->next;

    while(root != NULL)
    {
        temp->next = new Node;
        temp->next->data = root->data;
        temp = temp->next;
        root = root->next;
    }
    temp->next = NULL;
    return newn;

}


int main()
{
    Node*head = createNode(1);
    pusher(head,2);
    pusher(head,3);
    pusher(head,4);
    pusher(head,3);
    pusher(head,2);
    pusher(head,1);
    //printlist(head);
    //cout<<endl;
    cout << isPalindrome(head);
    //Node*copynode = copyofnode(head);
    //printlist(copynode);




//    cout << stackboi.top() << " ";
//    stackboi.pop();
//    cout << stackboi.top();



}
