/*
The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.

pi = 4*ninside_circle/n_square;

*/

#include<iostream>
#include <random>
#include <cmath>
using namespace std;

int main()
{
    int iter = 0;
    double tol = 1e-6;

    //double pi_act = 3.14159265358979;
    double pi_act = 3.1415;
    double pi_calc = 3.14;
    int ntotal = 0;
    int ninside = 0;
    while(true)
    {
        iter++;

        double x =  (float)rand()/(float)RAND_MAX;
        double y = (float)rand()/(float)RAND_MAX;

        //cout << x <<" "<< y << endl;

        if(   sqrt(pow(x,2)+pow(y,2)) <= 1 ) ninside++;

        ntotal++;
        pi_calc = 4*(double)ninside/(double)ntotal;

        cout << iter<< " "<<pi_calc << endl;
        if(   (abs(pi_calc-pi_act)/pi_act) < tol) break;

    }

}
