#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    string s;
    ifstream in("input.txt");
    getline(in, s);
    in.close();

    int current_length;
    int max_length = -1;
    char max_char;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (i == 0 || c != s[i - 1])
        {
            current_length = 0;
        }
        current_length++;
        if (current_length > max_length)
        {
            max_length = current_length;
            max_char = c;
        }
    }
    cout << max_char << " " << max_length;
    return 0;
}
