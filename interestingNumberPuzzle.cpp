class Solution {
  public:
    bool divisibleByEight(string &num) {
        if(num.find('0') != string::npos)
            return true;
        for(int x=8; x<1000; x+=8){
            string s = to_string(x);
            int j=0;
            for(char c : num)
                if(j < s.size() && c == s[j])
                    j++;
                if(j == s.size())
                    return true;
        }
        return false;
        
    }
};
