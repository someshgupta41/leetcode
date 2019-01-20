class Solution {
public:
    
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        else{
            return a.second > b.second;
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> result;
        
        if(nums.size() == 0){
            return result;
        }
        
        unordered_map<int,int> m;
        
        for(int k : nums){
            m[k]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(&cmp)> pq(cmp);
        
        for(auto &item : m){
            pq.push(item);
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