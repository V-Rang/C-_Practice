/*
Example:
creating an array of tuples.
*/

#include<iostream>

using namespace std;

struct tail
{
    int row;
    int col;
    float value;

    tail() {} //default constructor
    tail(int row_val, int col_val, float entry_val): row(row_val), col(col_val), value(entry_val) {} //parameterized constructor

};

struct head
{
    tail* example_tuples;
    //constructor
    head(): example_tuples(NULL) {}

};

int main()
{
    head head1;
    head1.example_tuples = new tail[4];
    for(int i=0;i<4;i++)
    {
        head1.example_tuples[i] = tail(i,i*2,i*3);
    }


    for(int i=0;i<4;i++)
    {
        cout << head1.example_tuples[i].row << " " << head1.example_tuples[i].col << " " << head1.example_tuples[i].value << endl;
    }

}