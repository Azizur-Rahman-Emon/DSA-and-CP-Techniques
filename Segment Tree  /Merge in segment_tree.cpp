#include <bits/stdc++.h>
using namespace std;
const int s = 1e5 + 7 ,inf=1e9+7;
long long a[s];
struct node
{
    int mn, count;
};
node tree[4 * s];
node merge(node l, node r)
{
    node ans;
    ans.mn = min(l.mn, r.mn);
    ans.count = 0;
    if (l.mn == ans.mn)
    {
        ans.count += l.count;
    }
    if (r.mn == ans.mn)
    {
        ans.count += r.count;
    }
    return ans;
}
void build(int n, int b, int e)
{
    if (b == e)
    {
        tree[n].mn = a[b];
        tree[n].count = 1;
        return;
    }
    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
}
void update( int n, int b,int e,int i,int val)
{
    if(e<i || b>i)
    {
        return;
    }
    if(b==e)
    {
        tree[n].mn=val;
        tree[n].count=1;
        return;
    }
     int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    update(l, b, mid,i,val);
    update(r, mid + 1, e,i,val);
    tree[n] = merge(tree[l], tree[r]);
}
node query(int n,int b,int e,int i,int j)
{
    if(e<i || j<b)
    {
        return{inf,1};
    }
    if(b>=i  && e<=j)
    {
        return tree[n];
    }
    int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
    return merge(query(l,b,mid,i,j),query(r,mid+1,e,i,j));
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    while(m--)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int idx,val;
            cin>>idx>>val;
            idx++;
            update(1,1,n,idx,val);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            l++;
            node res=query(1,1,n,l,r);
            cout<<res.mn<<" "<<res.count<<endl;
        }
    }
}
