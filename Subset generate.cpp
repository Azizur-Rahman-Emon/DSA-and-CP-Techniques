#include <bits/stdc++.h>
using namespace std;

vector<int> a, subset;

void generate(int idx)
{
    // Base case
    if (idx == a.size())
    {
        for (int x : subset)
            cout << x << " ";
        cout << '\n';
        return;
    }

    // Don't take a[idx]
    generate(idx + 1);

    // Take a[idx]
    subset.push_back(a[idx]);
    generate(idx + 1);
    subset.pop_back();
}

int main()
{
    int n;
    cin >> n;

    a.resize(n);

    for (int &x : a)
        cin >> x;

    generate(0);

    return 0;
}
