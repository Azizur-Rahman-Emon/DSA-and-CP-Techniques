#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 9;
long long a[mx], tree[mx * 4], lazy[mx * 4];
void push(int n, int b, int e)
{
    if (lazy[n] == 0)
        return;
    tree[n] += (e - b + 1) * lazy[n];
    if (b != e)
    {
        int l = 2 * n, r = 2 * n + 1;
        lazy[l] += lazy[n];
        lazy[r] += lazy[n];
    }
    lazy[n] = 0;
}
void build(int n, int b, int e)
{
    if (b == e)
    {
        tree[n] = a[b];
        return;
    }
    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
}
void update(int n, int b, int e, int i, int j, int v)
{
    push(n, b, e);
    if (e < i || j < b)
        return;
    if (b >= i && e <= j)
    {
        lazy[n] = v;
        push(n, b, e);
        return;
    }
    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    update(l, b, mid, i, j, v);
    update(r, mid + 1, e, i, j, v);
    tree[n] = tree[l] + tree[r];
}
long long query(int n, int b, int e, int i, int j)
{
    push(n, b, e);
    if (e < i || b > j)
        return 0;
    if (b >= i && e <= j)
    {
        return tree[n];
    }
    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l,r,v;
            cin>>l>>r>>v;
            l++;
            update(1,1,n,l,r,v);
        }
        else
        {
            int l;
            cin>>l;
            l++;
            cout<<query(1,1,n,l,l)<<endl;
        }
    }
}
