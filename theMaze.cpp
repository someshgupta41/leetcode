class Solution {
public:
    
    vector<vector<int>> directions = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        vector<vector<bool>> visited(maze.size() , vector<bool>(maze[0].size(),false));
        
        if(start[0] == destination[0] && start[1] == destination[1]) return true;
        
        queue<pair<int,int>> q;
        q.push(make_pair(start[0],start[1]));
        
        while(!q.empty()){
            
            auto t = q.front();
            
            q.pop();
            
            visited[t.first][t.second] = true;
            
            if(t.first == destination[0] && t.second == destination[1]){
                return true;
            }
            
            for(auto &dir : directions){
                int newX = t.first;
                int newY = t.second;
                
                while(isValid(maze, newX + dir[0], newY + dir[1])){
                    newX += dir[0];
                    newY += dir[1];
                }
                
                if(!visited[newX][newY]) q.push(make_pair(newX,newY));
            }
            
            
        }
        return false;
        
    }
    
    bool isValid(vector<vector<int>>& maze, int x, int y){
        if(x >= 0 && x < maze.size() &&  y >=0 && y < maze[0].size() && maze[x][y] == 0){
            return true;
        }
        else{
            return false;
        }
    }
};