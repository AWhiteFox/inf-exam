#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stack>
#include <stdlib.h>
using namespace std;

int true_div(int a, int b)
{
    if (a * b < 0)
    {
        return a / b - 1;
    }
    else
    {
        return a / b;
    }
}

int main()
{
    stack<int> nums;
    string s;
    bool error = false;
    while (cin >> s)
    {
        int a, b;
        if (s == "+")
        {
            if (nums.size() < 2)
            {
                error = true;
                break;
            }
            b = nums.top(); nums.pop();
            a = nums.top(); nums.pop();
            nums.push(a + b);
        }
        else if (s == "-")
        {
            if (nums.size() < 2)
            {
                error = true;
                break;
            }
            b = nums.top(); nums.pop();
            a = nums.top(); nums.pop();
            nums.push(a - b);
        }
        else if (s == "*")
        {
            if (nums.size() < 2)
            {
                error = true;
                break;
            }
            b = nums.top(); nums.pop();
            a = nums.top(); nums.pop();
            nums.push(a * b);
        }
        else if (s == "/")
        {
            if (nums.size() < 2)
            {
                error = true;
                break;
            }
            b = nums.top(); nums.pop();
            a = nums.top(); nums.pop();
            if (b == 0)
            {
                error = true;
                break;
            }
            nums.push(true_div(a, b));
        }
        else
        {
            nums.push(atoi(s.c_str()));
        }
    }
    if (error || nums.size() != 1)
    {
        cout << "ERROR";
    }
    else
    {
        cout << nums.top();
    }
    return 0;
}
