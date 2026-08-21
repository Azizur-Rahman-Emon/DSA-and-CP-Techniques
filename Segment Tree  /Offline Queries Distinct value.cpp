#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N];
int tree[4 * N];
int lazy[4 * N];
void push(int node, int b, int e)
{
    if (lazy[node] == 0)
        return;

    tree[node] += lazy[node] * (e - b + 1);

    if (b != e)
    {
        int left = 2 * node;
        int right = 2 * node + 1;

        lazy[left] += lazy[node];
        lazy[right] += lazy[node];
    }

    lazy[node] = 0;
}
void update(int node, int b, int e, int i, int val)
{
    push(node, b, e);
    if (i < b || i > e)
        return;

    if (b == e)
    {
        tree[node] += val;
        return;
    }

    int mid = (b + e) / 2;

    update(2 * node, b, mid, i, val);
    update(2 * node + 1, mid + 1, e, i, val);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int b, int e, int l, int r)
{
    push(node, b, e);
    if (e < l || b > r)
        return 0;
    if (l <= b && e <= r)
        return tree[node];

    int mid = (b + e) / 2;

    return query(2 * node, b, mid, l, r)
         + query(2 * node + 1, mid + 1, e, l, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int q;
    cin >> q;
    vector<pair<int, int>> Q[n + 1];

    for (int id = 1; id <= q; id++)
    {
        int l, r;
        cin >> l >> r;

        Q[r].push_back({l, id});
    }

    vector<int> ans(q + 1);

    map<int, int> last;

    for (int i = 1; i <= n; i++)
    {
        
        update(1, 1, n, i, 1);
        if (last.count(a[i]))
        {
            update(1, 1, n, last[a[i]], -1);
        }

        last[a[i]] = i;

        for (auto [l, id] : Q[i])
        {
            ans[id] = query(1, 1, n, l, i);
        }
    }

    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}
