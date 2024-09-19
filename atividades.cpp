#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp_function(const pair<int, int>& a1, const pair<int, int>& a2) {
    if (a1.second == a2.second)  return a1.first < a2.first;
    else return a1.second < a2.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& at : a) cin >> at.first >> at.second;
    sort(a.begin(), a.end(), comp_function);
    int ans = 1, f = a[0].second;
    for (int i = 1; i < n; ++i) {
        if (a[i].first >= f) {
            ans++;
            f = a[i].second;
        }
    }
    cout << ans << "\n";
    return 0;
}