class Solution {
public:
    
    vector<int> original;
    vector<int> shuffled;
    
    Solution(vector<int> nums) {
         srand(time(NULL));
        original.resize(nums.size());
        shuffled.resize(nums.size());
        for(int i = 0; i < nums.size();i++){
            original[i] = nums[i];
            shuffled[i] = nums[i];
        }
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        vector<int> result;
        
        if(original.size() == 0){
            return result;
        }
        
        shuffled = original;
        return shuffled;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
         vector<int> result;
        
        if(original.size() == 0){
            return result;
        }
        
        int j = 0;
        for(int i = shuffled.size() - 1; i>=0 ; --i){
             j = rand() % (i+1);
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */