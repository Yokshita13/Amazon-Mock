class Solution {
  public:
    long long ans = 0;
    int n;
    int dfs(int u, int p, vector<vector<int>>& g){
        int sz = 1;
        long long pairs = 0;
        for(int v : g[u]){
            if(v == p)
                continue;
            int s = dfs(v, u, g);
            pairs += 1LL * s * (s - 1)/2;
            sz += s;
        }
        int s = n - sz;
        pairs += 1LL * s * (s - 1)/2;
        
        long long total = 1LL * (n - 1) * (n - 2)/2;
        ans = max(ans, total - pairs);
        return sz;
    }
    long long maxCities(vector<vector<int>> &roads, int n) {
        vector<vector<int>> g(n);
        for(auto e : roads){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1, g);
        return ans;
    }
};
