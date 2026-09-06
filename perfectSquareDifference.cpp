class Solution {
  public:
    int countPairs(vector<int>& arr) {
        const int MAX = 10000;
        vector<int> freq(MAX+1 , 0);
        for(int x : arr){
            freq[x]++;
        }
        long long ans = 0;
        for(int x=1; x<=MAX; x++){
            if(freq[x] == 0)
                continue;
            for(int k=1; k*k<=MAX-x; k++){
                int y = x + k*k;
                if(freq[y]>0){
                    ans+= 1LL * freq[x] * freq[y];
                }
            }
        }
        return (int)ans;
    }
};
