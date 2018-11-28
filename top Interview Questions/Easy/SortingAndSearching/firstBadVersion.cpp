// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start = 1;
        int end = n;
        
        int result = -1;
        
        while(start <= end){
            int mid  = start + (end - start)/2;
            if(isBadVersion(mid) == true){
                result = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return result;
    }
};