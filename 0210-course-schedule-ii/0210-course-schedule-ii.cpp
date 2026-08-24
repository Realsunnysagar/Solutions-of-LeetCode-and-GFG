class Solution {

    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>& ans){
        
        if(vis[node] == 1 ) return false;
        if(vis[node] == 2) return true;

        vis[node] = 1;

        for(auto neighbour : adj[node]){
            if(!dfs(neighbour, vis, adj, ans)) return false;
        }

        vis[node] = 2;
        
        ans.push_back(node);

        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            int course = it[1];
            int prerequired = it[0];
            adj[course].push_back(prerequired);
        }

        vector<int> vis(numCourses, 0);
        vector<int> ans;

        for(int i = 0; i<numCourses; i++){
            if(!vis[i]){
                if(!dfs(i, vis, adj, ans)) return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;

    }
};