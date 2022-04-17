#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

// This code is inspired from the book "Guide to Scientific Computing in C++" by Fancis and Whiteley

using namespace std;
double CalculateMinimum (double a, double b);

int main (int argc, char* argv[])

{
    double x, y;
    cout << "Please enter the first number here: ";
    cin >> x;
    cout << "The first number you have entered is " << x << endl;
    cout << "Please enter the second number here: ";
    cin >> y;
    cout << "The second number you have entered is " << y << endl;
    double minimum_value = CalculateMinimum (x, y);
    std::cout << "The minimum value of " << x << " and " << y
              << " is " << minimum_value << "\n"<< "\a";

    return 0;
}

double CalculateMinimum(double a, double b)
{
    double minimum;
    if (a < b)
    {
        minimum = a;
    }
    else
    {
        //a >= b
        minimum = b;
    }
  return minimum;
}
