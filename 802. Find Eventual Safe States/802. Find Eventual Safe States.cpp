class Solution {
public:
    bool dfs(int i, vector<int> g[], vector<int> &vis, vector<int> &pathVis, vector<int> &check)
    {
        vis[i]=1;
        pathVis[i]=1;
        check[i]=0;
        
        for(auto it: g[i])
        {
            if(vis[it]==0)
            {
                if(dfs(it, g, vis, pathVis, check))
                    return true;
            }
            else if(pathVis[it]==1)
            {
                return true;
            }
        }
        pathVis[i]=0;
        check[i]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        
        int n=graph.size();
        vector<int> g[n];
        for(int i=0; i<n; i++)
        {
            g[i]=graph[i];
        }
        
        vector<int> vis(n), pathVis(n), check(n);
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                dfs(i, g, vis, pathVis, check);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(check[i]==1)
                safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};