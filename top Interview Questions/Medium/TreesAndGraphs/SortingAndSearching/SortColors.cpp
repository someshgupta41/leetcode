class Solution {
public:
    void sortColors(vector<int>& a) {
        
        int lo = 0;
        int mid = 0;
        
        int high = a.size() - 1;
        
        while(mid <= high){
            switch(a[mid]){
                case 0: swap(a[lo++],a[mid++]); break;
                case 1: mid++; break;
                case 2: swap(a[high--],a[mid]); break;
            }
        }
        
        
    }
};