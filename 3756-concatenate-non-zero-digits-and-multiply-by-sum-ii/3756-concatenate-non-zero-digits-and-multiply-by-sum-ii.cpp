class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos, dig;

        // Store non-zero digits and their positions
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                dig.push_back(s[i] - '0');
            }
        }

        int n = dig.size();

        // powers of 10
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // prefix concatenated value and prefix digit sum
        vector<long long> pref(n + 1, 0), sumPref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = (pref[i] * 10 + dig[i]) % MOD;
            sumPref[i + 1] = sumPref[i] + dig[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x = (pref[R + 1] - pref[L] * pow10[len]) % MOD;
            if (x < 0) x += MOD;

            long long sum = sumPref[R + 1] - sumPref[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};