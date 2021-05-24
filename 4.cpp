#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

string to_string(int i)  // temporary implementation for testing in CB
{
    switch (i)
    {
        case 0: return "0";
        case 1: return "1";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
    }
}

void print_nums(int n, int max_base = -1, string base = "")
{
    if (max_base == -1)
        max_base = n;
    for (int i = 1; i < n; i++)
    {
        if (i <= max_base)
        {
            print_nums(n - i, min(i, max_base), base + to_string(i) + " ");
        }
    }
    if (n <= max_base)
    {
        cout << base + to_string(n) << endl;
    }
}

int main()
{
    int i;
    cin >> i;
    print_nums(i);
    return 0;
}
