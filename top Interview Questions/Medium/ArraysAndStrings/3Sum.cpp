class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        
        if(nums.size() ==0){
            return result;
        }
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        for(int i = 0; i < nums.size();i++){
            
            int start = i+1;
            int end = nums.size() - 1;
            
            while(start < end){
                
                int sum = nums[start] + nums[end] + nums[i] ;
                
                if(sum == 0){
                    vector<int> sol;
                    sol.push_back(nums[start]);
                    sol.push_back(nums[end]);
                    sol.push_back(nums[i]);
                    result.push_back(sol);
                    start++;
                    end--;
                    
                    while( start <= end && nums[start] == nums[start-1]) start++;
                    while(start <= end && nums[end] == nums[end + 1] ) end--;
                    
                }
                else if(sum < 0){
                    start++;
                }
                else if(sum > 0)
                {
                    end--;
                }
                
            }
            
            while( i < n -1 && nums[i] == nums[i+1]) i++;
            
        }
        return result;
        
    }
};