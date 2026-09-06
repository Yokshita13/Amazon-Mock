class Solution {
  public:
    int minOperation(string s) {
        int n = s.size();
        int best = 0;
        for(int k=1; 2*k<=n; k++){
            if(s.substr(0, k) == s.substr(k ,k))
                best = k;
        }
        if(best == 0) 
            return n;
        return n - best + 1;
    }
};
