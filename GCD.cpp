class Solution {
  public:
    vector<long long> solve(long long L, long long R) {
        if(L==R){
            if(L==1)
                return {1, 1};
            else
                return {-1, -1};
        }
        return {L, L+1};
    }
};
