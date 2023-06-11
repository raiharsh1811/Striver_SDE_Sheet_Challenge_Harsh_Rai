#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> adj[vertex];
    for(auto it:edges){
        adj[it.first].emplace_back(it.second);
        adj[it.second].emplace_back(it.first);
    }
    for(int i=0;i<vertex;i++) sort(adj[i].begin(),adj[i].end());

    vector<int> vis(vertex,0);
    vector<int> dfs;
    queue<int> q;
    
    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            vis[0]=1;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();

                dfs.emplace_back(node);
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return dfs;
}