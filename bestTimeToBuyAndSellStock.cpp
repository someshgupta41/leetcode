class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxEndingHere = 0;
        int maxSoFar = 0;
        
        for(int i = 1; i < prices.size(); i++){
            maxSoFar = max(0, maxSoFar += prices[i] - prices[i-1]);
            maxEndingHere = max(maxSoFar, maxEndingHere);
        }
        
        return maxEndingHere;
        
    }
};