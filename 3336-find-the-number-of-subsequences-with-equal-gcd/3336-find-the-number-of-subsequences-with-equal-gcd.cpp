class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        const int MAX = 200;

        vector<vector<long long>> dp(MAX + 1,
                                     vector<long long>(MAX + 1, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<long long>> dp1 = dp;

            for (int i = 0; i <= MAX; i++) {
                for (int j = 0; j <= MAX; j++) {
                    long long curr = dp[i][j];
                    if (!curr) continue;

                    // Put into seq1
                    int i1 = (i == 0) ? x : gcd(i, x);
                    dp1[i1][j] = (dp1[i1][j] + curr) % MOD;

                    // Put into seq2
                    int j1 = (j == 0) ? x : gcd(j, x);
                    dp1[i][j1] = (dp1[i][j1] + curr) % MOD;
                }
            }

            dp.swap(dp1);
        }

        long long ans = 0;
        for (int g = 1; g <= MAX; g++) {
            ans = (ans + dp[g][g]) % MOD;
        }

        return (int)ans;
    }
};