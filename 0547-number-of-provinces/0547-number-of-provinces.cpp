class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[node] = 1; // Mark the current node as visited
        for(int it = 0; it < isConnected.size(); it++) { // Iterate over all nodes
            if(!vis[it] && isConnected[node][it] == 1) { // If the node is not visited and connected
                dfs(it, isConnected, vis); // Recursively visit the connected node
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0); // Initialize visited array with size n and all elements set to 0
        int prov = 0; // Counter for provinces

        for(int i = 0; i < n; i++) {
            if(!vis[i]) { // If the node is not visited
                prov++; // Increment province count
                dfs(i, isConnected, vis); // Perform DFS to mark all connected nodes
            }
        }
        return prov; // Return the number of provinces
    }
};