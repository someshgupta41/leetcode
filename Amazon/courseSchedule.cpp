class Solution {
public:
    
    bool cycle(vector<unordered_set<int>>& graph, vector<bool>& visited, vector<bool>& onPath,int node){
        
        if(visited[node]){
            return false;
        }
        
        visited[node] = onPath[node] = true;
        
        for(auto i : graph[node]){
            if(onPath[i] || cycle( graph, visited,onPath, i)){
                return true;
            }
        }
        
        return onPath[node] = false;

    }
    
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites){
        
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }
    
    
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        if(numCourses == 0){
            return false;
        }
        
        vector<bool> visited(numCourses,false);
        vector<bool> onPath(numCourses,false);
        
        vector<unordered_set<int>> graph = make_graph(numCourses,prerequisites);
        
        for(int i = 0; i < numCourses;i++){
            if( !visited[i] && cycle(graph,visited,onPath, i)){
                return false;
            }
        }
        return true;
        
    }
};