#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stack>
#include <stdlib.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a + (a % 8) + 2; i <= b; i+=8)
    {
        int div_count = 1;
        int sqrt_i = round(sqrt(i));
        for (int j = 2; j <= sqrt_i; j++)
        {
            if (i % j == 0)
            {
                if (j % 2 == 0)
                {
                    div_count++;
                }
                int m = i / j;
                if (m % 2 == 0)
                {
                    div_count++;
                    if (j == m)
                    {
                        div_count--;
                    }
                }
                if (div_count > 3)
                {
                    break;
                }
            }
        }
        if (div_count == 3)
        {
            cout << i << endl;
        }
    }
}
