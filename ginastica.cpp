#include <iostream>

long long T, M, N;

unsigned int dp[55][100010];

long long ginastica(long long tempo, long long nivel) {
    if (nivel == M - 1 || nivel == N + 1)
        return 0;
    if (tempo == 1)
        return 1;
    if (dp[tempo][nivel] != -1)
        return dp[tempo][nivel];
    dp[tempo][nivel] = (ginastica(tempo - 1, nivel - 1) + ginastica(tempo - 1, nivel + 1)) % 1000000007;
    return dp[tempo][nivel];
}

int main() {
    long long total = 0;
    std::cin >> T >> M >> N;
    for (int i = 0; i < 55; ++i) {
        for (int j = 0; j < 100010; ++j) {
            dp[i][j] = -1;
        }
    }
    for (int i = M; i <= N; ++i) {
        total = (total + ginastica(T, i)) % 1000000007;
    }
    std::cout << total << std::endl;
    return 0;
}