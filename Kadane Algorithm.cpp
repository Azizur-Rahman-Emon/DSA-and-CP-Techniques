//Maximum Subarray Sum
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll cur_sum = 0, mx = LLONG_MIN;

    for(int i = 0; i < n; i++) {
        cur_sum += v[i];
        mx = max(mx, cur_sum);
        if(cur_sum < 0) cur_sum = 0;
    }

    cout << mx << endl;
}
