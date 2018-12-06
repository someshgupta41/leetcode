class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> m;
        
        for(auto i : strs){
            string word = i;
            sort(i.begin(),i.end());
            m[i].push_back(word);
        }
        
        vector<vector<string>> result;
        
        for(auto i : m){
            vector<string> m1(i.second.begin(),i.second.end());
            result.push_back(m1);
        }
        return result;
    }
};