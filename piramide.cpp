#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<vector<int>> p;
vector<vector<int>> dp;

int pir_dp(int n, int i, int f) {
    if (n == 1) return p[1][i];
    if (dp[n][i] != -1) return dp[n][i];
    int soma = accumulate(p[n].begin() + i, p[n].begin() + f, 0);
    return dp[n][i] = soma + min(pir_dp(n - 1, i, f - 1), pir_dp(n - 1, i + 1, f));
}

int main() {
    int t, j;
    cin >> t;
    p.resize(t + 1);
    dp.resize(t + 1);
    for (auto &x: dp) x.resize(t+2, -1);
    for_each(p.begin(), p.end(), [t](vector<int>& pp) { pp.resize(t + 1);});
    for (unsigned int i = 1; i < p.size(); ++i)
        for (j = 0; j < t; ++j)  cin >> p[i][j];
    cout << pir_dp(t, 0, t) << endl;
    return 0;
}