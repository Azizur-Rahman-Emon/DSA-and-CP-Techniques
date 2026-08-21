 #include<bits/stdc++.h>
 using namespace std;

 int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // compress the array to numbers starting from 1
    // so that the smallest number in the array becomes 1
    // the second smallest number becomes 2 and so on
    vector<int> a({100, 9, 10, 9});
    set<int> se;
    for (auto x: a) se.insert(x);
    map<int, int> mp;
    int id = 0;
    for (auto x: se) {
        mp[x] = ++id;
    }
    for (int i = 0; i < a.size(); i++) {
        a[i] = mp[a[i]];
        cout << a[i] << ' ';
    }
    return 0;
 }
