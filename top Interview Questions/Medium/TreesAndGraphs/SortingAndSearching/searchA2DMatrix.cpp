class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size()  == 0 || matrix[0].size() == 0){
            return false;
        }
        
        int i = 0;
        int j = matrix[0].size() - 1;
        
        int m = matrix.size();
      
        
        while(i < m && j>=0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){
                j--;
            }
            else if(matrix[i][j] < target){
                i++;
            }
        }
        return false;
        
        
    }
};