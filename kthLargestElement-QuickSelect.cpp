class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(true){
            int p = partition(nums,left,right);
            if(p == k - 1){
                return nums[p];
            }
            else if(p > k - 1){
                right = p - 1;
            }
            else{
                left = p + 1;
            }
        }
        
    }
    
    int partition(vector<int>& nums,int left,int right){
        int pivot = nums[left];
        int lm = left + 1;
        int rm = right;
        
        
        while(lm <= rm){
            if(nums[lm] < pivot && nums[rm] > pivot){
                swap(nums[lm++],nums[rm--]);
            }
            
            if(nums[lm] >= pivot){
                lm++;
            }
            if(nums[rm] <= pivot){
                rm--;
            }
        }
        swap(nums[left],nums[rm]);
        return rm;
    }
    
};