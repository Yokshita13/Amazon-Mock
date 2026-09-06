class Solution {
public:
    int minOperations(vector<int> &front, vector<int> &back) {
        int n = front.size();
        int FULL = 1 << n;
        const int INF = INT_MAX / 2;
        vector<vector<int>> dp(FULL, vector<int>(31, INF));
        dp[0][0] = 0;
        
        for (int mask = 0; mask < FULL; mask++) {
            int k = __builtin_popcount(mask);
            if (k == n) continue;
            for (int lastVal = 0; lastVal <= 30; lastVal++) {
                if (dp[mask][lastVal] == INF) continue;
                int cost = dp[mask][lastVal];
                for (int c = 0; c < n; c++) {
                    if (mask & (1 << c)) continue;
                    int disp = k - c;
                    int parity = ((disp % 2) + 2) % 2;
                    int val = (parity == 0) ? front[c] : back[c];
                    if (val < lastVal) continue;
                    int addedInv = c - __builtin_popcount(mask & ((1 << c) - 1));
                    int newMask = mask | (1 << c);
                    int newCost = cost + addedInv;
                    dp[newMask][val] = min(dp[newMask][val], newCost);
                }
            }
        }
        
        int ans = INF;
        for (int v = 0; v <= 30; v++)
            ans = min(ans, dp[FULL - 1][v]);
        
        return ans >= INF ? -1 : ans;
    }
};
