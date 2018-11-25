class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLen = 0;
        int start = 0;
        
        unordered_map<int,int> m;
        
        for(int i = 0 ; i < s.size();i++){
            char c = s[i];
            
            if(m.find(c) != m.end() && m[c] >= start){
                start = m[c] +1;
            }
            
            m[c] = i;
            
            maxLen = max(maxLen, i - start + 1);
            
        }
        return maxLen;
        
    }
};