class Solution {
public:
    
    
    // use backtracking 
    
    // iterate over the entire the grid , to find the 1's 
    
    // once found , congrats you found an island,
    
    //explore the neighbours
    
    // all the adjacent 1's will constitute the same island
    
    // once a 0 encountered, stop exploring and return
    
    void explore(vector<vector<char>>& grid, int i , int j){
        
        
        
        // check the boundary conditions 
        
        if(i < 0 || i >= grid.size()  || j < 0 || j >= grid[0].size()){
            return ;
        }
        
        // return if encountered a 0
        if(grid[i][j] != '1'){
            return ;
        }
        
        
        // make the value 0 so that you don't visit it again
        // better than using a separate visited bool matrix
        grid[i][j] ='0';
        
        // explore in four possible directions
        explore(grid,i+1,j);
        explore(grid,i-1,j);
        explore(grid,i,j+1);
        explore(grid,i,j-1);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
   
        
         if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        
         //count will hold the result
        int count = 0;
        
         // explore the grid
        for(int i = 0 ; i < grid.size();i++){
            for(int j = 0; j < grid[0].size();j++){
                if(grid[i][j] == '1'){
                     // found an island , increment counter and explore the grid, to find if more 1's can be part of the same count
                    count++;
                    explore(grid,i,j);
                }
            }
        }
        
        // return the result
        return count;
    }
};