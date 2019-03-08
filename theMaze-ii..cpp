class Solution {
public:
    
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        vector<vector<int>> dist(maze.size(),vector<int>(maze[0].size(),-1));
        
        
        if(start[0] == destination[0] && start[1] == destination[1]) {
            return true;
        }
        
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        
        dist[start[0]][start[1]] = 0;
        
        while(!q.empty()){
            
            auto t = q.front();
            q.pop();
            
            
            for(auto &dir : directions){
                
                int count = dist[t.first][t.second];
            
                int newX =t.first;
                int newY = t.second;
                
                while(isValid(maze, newX + dir[0],newY + dir[1])){
                   
                    newX += dir[0];
                    newY += dir[1];
                     ++count;
                    
                }
                
                if(dist[newX][newY] == -1 || dist[newX][newY]  > count){
                    q.push(make_pair(newX, newY));
                    dist[newX][newY] = count;
                } 
                
            }
            
        }
        
        return dist[destination[0]][destination[1]];
    }
    
    bool isValid(vector<vector<int>>& maze, int x, int y){
        if(x >= 0 && x < maze.size() && y >= 0 && y< maze[0].size() && maze[x][y] == 0){
            return true;
        }
        else{
            return false;
        }
    }
};