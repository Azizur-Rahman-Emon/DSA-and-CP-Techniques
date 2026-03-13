#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// PBDS multiset template using pair<int,int> to handle duplicates
template<typename T>
using pbds_multiset = tree<
    pair<T,int>, // pair: {value, unique_id}
    null_type,
    less<pair<T,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// Example usage
int main() {
    pbds_multiset<int> ms;
    int id = 0; // unique counter for duplicates

    // Insert elements
    ms.insert({5, id++});
    ms.insert({3, id++});
    ms.insert({5, id++}); // duplicate 5 is allowed

    // Count of elements less than 5
    cout << "Elements < 5: " << ms.order_of_key({5,0}) << "\n";

    // Find k-th element (0-indexed)
    auto it = ms.find_by_order(1); // second smallest element
    if(it != ms.end())
        cout << "2nd smallest: " << it->first << "\n";

    // Erase a specific value (erase only one occurrence)
    auto it2 = ms.lower_bound({5,0});
    if(it2 != ms.end())
        ms.erase(it2);

    // Print all elements
    cout << "All elements: ";
    for(auto &p : ms) cout << p.first << " ";
    cout << "\n";

    return 0;
}
