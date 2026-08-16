class Solution {
    void dfs(int node, vector<vector<int>> &adjLs, vector<int> &visited){
        
        visited[node] = 1;
        for(auto neighbour : adjLs[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adjLs, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(n);
        for(int i = 0; i<n ; i++){
            for(int j = 0; j < n ; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    // adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        int cnt = 0;
        for(int i = 0 ; i< n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};