class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSoFar = 0;
        int maxEndingHere = 0;
        int maxNum = INT_MIN;
        
        for(int i : nums){
            maxEndingHere = max(0, maxEndingHere += i);
            maxSoFar = max(maxSoFar, maxEndingHere);
            maxNum = max(maxNum,i);
        }
        if(maxSoFar == 0){
            return maxNum;
        }
        else{
            return maxSoFar;
        }
    }
};