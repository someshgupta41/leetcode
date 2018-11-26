class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;
        
        if(nums1.size() == 0 || nums2.size() == 0){
            return result;
        }
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int m = 0;
        int n = 0;
        
        while(m < nums1.size() && n < nums2.size()){
            
            if(nums1[m] < nums2[n]){
                m++;
            }
            else if(nums1[m] > nums2[n]){
                n++;
            }
            else {
                result.push_back(nums1[m]);
                m++;
                n++;
            }
            
        }
        
        return result;
        
    }
};