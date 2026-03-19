// Pattern Macthing
// Time Complexity O(N+M)
#include <bits/stdc++.h>
using namespace std;
vector<int> temp_array(const string &pattern)
{
    vector<int> lps(pattern.length(), 0);
    int index = 0;
    for (int i = 1; i < pattern.length();)
    {
        if (pattern[i] == pattern[index])
        {
            lps[i] = index + 1;
            index++;
            i++;
        }
        else
        {
            if (index != 0)
            {
                index = lps[index - 1];
            }
            else
            {
                lps[i] = index;
                i++;
            }
        }
    }
    return lps;
}
int kmp(const string &text, const string &pattern)
{
    int cnt = 0;
    vector<int> lps = temp_array(pattern);
    int i = 0, j = 0;
    while (i < text.length())
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
            {
                i++;
            }
        }
        if (j == pattern.length())
        {
            cout<<i-pattern.length()<<" ";
            cnt++;
            j = lps[j - 1];
        }
    }
    return cnt;
}
int main()
{
    string text, pattern;
    cin >> text >> pattern;
    cout << kmp(text, pattern) << endl;
}
