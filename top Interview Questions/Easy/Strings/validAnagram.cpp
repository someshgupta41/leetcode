class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char,int> m;
        
        if(s.size() != t.size()){
            return false;
        }
        
        for(int i = 0; i < s.size();i++){
            m[s[i] - 'a']++;
            m[t[i] - 'a']--;
        }
        
        for(auto &item : m){
            if(item.second != 0){
                return false;
            }
        }
        return true;
        
    }
};