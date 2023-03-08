//implementing a stack from scratch
#include<iostream>

using namespace std;

#define MAX 1000

class Stack
{
    int top;
public:
    int a[MAX];
    Stack(){top = -1;}
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if(top == MAX-1)
    {
        cout << "stack is full\n";
        return false;
    }

    a[top+1] = x;
    top ++;
    cout <<x<<" pushed into stack\n";
    return true;

}

int Stack::pop()
{
    if(top<0)
    {
        cout <<"stack empty()";
        return -1;
    }
    top --;
    return a[top+1];
}

int Stack::peek()
{
    if(top<-1)
    {
        cout  <<"stack empty";
        return -1;
    }
    return a[top];
}

bool Stack::isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    return false;
}

int main()
{
    Stack s;

   s.push(5);
   s.push(15);
   cout<<s.peek()<<endl;
   s.pop();
   cout <<s.peek()<<endl;
   cout <<s.isEmpty()<<endl;
   s.peek();
   cout << s.pop()<<endl;
   s.peek();
   cout<<s.isEmpty()<<endl;

}


