#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int w[n][n];
    int p[n][n];

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> w[j][i];
            if (w[j][i] == 0)
            {
                p[j][i] = -1;
            }
            else
            {
                p[j][i] = j;
            }
        }
        p[j][j] = -1;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ik = w[i][k];
                int kj = w[k][j];
                int ij = w[i][j];
                if (ik * kj * ij != 0 && ik + kj < ij)
                {
                    w[i][j] = ik + kj;
                    p[i][j] = p[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "(" << i + 1 << "," << j + 1 << "): ";
            if (w[i][j] == 0)
            {
                cout << 0;
            }
            else
            {
                int current = j;
                stack<int> path;
                while (p[i][current] != -1)
                {
                    path.push(p[i][current]);
                    current = p[i][current];
                }
                while (!path.empty())
                {
                    cout << path.top() + 1 << " ";
                    path.pop();
                }
                cout << j + 1 << " ";
                cout << "(" << w[i][j] << ")";
            }
            cout << endl;
        }
    }

    return 0;
}
