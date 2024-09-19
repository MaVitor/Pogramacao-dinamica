#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct trilhas{
    int n, m;
    vector<vector<int>> d;
};

const int INF = 1e9;

trilhas dp;

int bt(trilhas &t, int linha, int coluna){
    if (coluna<0 or coluna>=t.m) return INF;
    if (linha==0) return t.d[linha][coluna];
    if (dp.d[linha][coluna] != -1) return dp.d[linha][coluna];
    int ans = INF;
    ans = min (ans, bt(t,linha-1,coluna-1));
    ans = min (ans, bt(t,linha-1,coluna));
    ans = min (ans, bt(t,linha-1,coluna+1));
    return dp.d[linha][coluna] = ans + t.d[linha][coluna];
}
int solve(trilhas &t, int inicio){
    return bt(t,t.n-1,inicio);
}

int solve(trilhas & t){
    int ans = solve(t,0);
    for (int i=1 ; i<t.m ; ++i)
        ans = min(ans, solve(t, i));
    return ans;
}

int main(){
    trilhas t;
    cin >> t.n >> t.m;
    t.d.resize(t.n);
    for (auto &x: t.d) x.resize(t.m);
    for (auto &l:t.d)
        for (auto &d:l) cin >> d;
    dp.n = t.n;
    dp.m = t.m;
    dp.d.resize(dp.n);
    for (auto &x: dp.d) x.resize(dp.m);
    for (auto &l:dp.d)
        for (auto &d:l) d = -1;
    cout << solve(t) << endl;
    return 0;
}