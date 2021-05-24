#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;

int priority(char c)
{
    switch (c)
    {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        default: return -1;
    }
}

string remove_brackets(string s)
{
    while (s[0] == '(' && s[s.size() - 1] == ')')
    {
        int bracket_depth = 1;
        for (int i = 1; i < s.size() - 1; i++)
        {
            char c = s[i];
            if (c == '(')
            {
                bracket_depth++;
            }
            else if (c == ')')
            {
                bracket_depth--;
                if (bracket_depth == 0)
                {
                    return s;
                }
            }
        }
        s = s.substr(1, s.size() - 2);
    }
    return s;
}

int solve(string s)
{
    s = remove_brackets(s);
    int bracket_depth = 0;
    int min_priority_opetator_index = -1;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        int p = priority(c);
        if (p != -1 && bracket_depth == 0 && (min_priority_opetator_index == -1 || p <= priority(s[min_priority_opetator_index])))
        {
            min_priority_opetator_index = i;
        }
        else if (c == '(')
        {
            bracket_depth++;
        }
        else if (c == ')')
        {
            bracket_depth--;
        }
    }

    if (min_priority_opetator_index == -1)
    {
        return atoi(s.c_str());
    }
    else
    {
        int a = solve(s.substr(0, min_priority_opetator_index));
        int b = solve(s.substr(min_priority_opetator_index + 1, s.size()));
        switch (s[min_priority_opetator_index])
        {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
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
        }
    }
}

int main()
{
    string s;
    getline(cin, s);
    cout << solve(s);
    return 0;
}
