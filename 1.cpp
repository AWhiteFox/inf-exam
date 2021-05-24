#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int n_count = 0;
    int n_max = a;
    for (int i = a; i <= b; i++)
    {
        if (abs(i) % 2 != 0)
            continue;
        if (abs(i) % 10 == 0)
            continue;
        int ii = abs(i);
        int j = 0;
        while (ii != 0)
        {
            j += ii % 2;
            ii /= 2;
        }
        if (j != 5)
            continue;
        n_count++;
        n_max = max(n_max, i);
    }
    if (n_count == 0)
        n_max = 0;
    cout << n_count << " " << n_max;
    return 0;
}
