class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() == 0){
            return 0;
        }
        
        int left = 0;
        int right = height.size() - 1;
        
        int maxLeft = 0;
        int maxRight = 0;
        
        int sum = 0;
        
        while(left <= right){
            
            if(height[left] <= height[right]){
                
                if(maxLeft < height[left]){
                    maxLeft = height[left];
                }
                else{
                    sum += (maxLeft - height[left]);
                }
                left++;
            }
            else{
                
                if(maxRight < height[right]){
                    maxRight = height[right];
                }
                else{
                    sum += (maxRight - height[right]);
                }
            right--;
            }
            
        }
        return sum;
        
    }
};