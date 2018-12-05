class Solution {
public:
    
    static bool cmp(pair<string,int> a, pair<string,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        else{
            return a.second > b.second;
        }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        vector<string> result;
        
        if(words.size() == 0){
            return result;
        }
        
        unordered_map<string,int> m;
        
        for(string s : words){
            m[s]++;
        }
        
        priority_queue<pair<string,int>,vector<pair<string,int>>, decltype(&cmp)> pq(cmp);
        
        for(auto &i : m){
            pq.push(i);
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            result.push_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(),result.end());
        
        return result;
        
    }
};