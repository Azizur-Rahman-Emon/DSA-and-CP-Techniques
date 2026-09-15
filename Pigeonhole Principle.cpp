// jodi n > m hoi, tahole Pigeonhole Principle r mote 2 ta number er remainder same hobei
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> cnt(m, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int rem = x % m;

        cnt[rem]++;

        if (cnt[rem] >= 2)
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
