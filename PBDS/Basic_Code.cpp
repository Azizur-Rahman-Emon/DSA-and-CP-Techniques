#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    pbds<int> s;

    s.insert(5);
    s.insert(2);
    s.insert(8);
    s.insert(1);

    cout << *s.find_by_order(0) << endl; // 0 index element
    cout << *s.find_by_order(2) << endl; // 2 index element

    cout << s.order_of_key(5) << endl; // 5 er cheye choto koyta

    s.erase(2);

    for (auto x : s)
        cout << x << " ";
}
