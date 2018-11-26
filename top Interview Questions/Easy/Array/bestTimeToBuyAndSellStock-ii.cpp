class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
     
        
         int maxCur = 0;
        int maxSoFar = 0;
        
        for(int i = 1; i < prices.size();i++){
            int diff = prices[i] - prices[i-1];
            if(diff > 0){
                maxSoFar += diff;
            }
        }
        return maxSoFar;
        
        
    }
};