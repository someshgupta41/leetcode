class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        
        int k = 1;
        
        for(int i = 0; i < nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                 nums[k++] = nums[i+1];
            }
            
        }
        
        return k;
    }
};