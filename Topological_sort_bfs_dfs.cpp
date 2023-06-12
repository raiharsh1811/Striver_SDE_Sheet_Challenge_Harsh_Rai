// #include <bits/stdc++.h> 
// void dfs(int vis[],vector<int>adj[],stack<int>&s,int node){
//     vis[node]=1;
//     for(auto it:adj[node]){
//         if(!vis[it]){
//             dfs(vis,adj,s,it);
//         }
//     }
//     s.push(node);
// }
// vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
//      vector<int> adj[v];
//   for(auto it:edges){
//     int u=it[0];
//     int z=it[1];
//     adj[u].push_back(z);    
//   }
//   int vis[v]={0};
//   stack<int>s;
//   for(int i=0;i<v;i++){
//       if(!vis[i]){
//           dfs(vis,adj,s,i);
//       }
//   }
//   vector<int>ans;
//   while(!s.empty()){
//       int x=s.top();
//       s.pop();
//       ans.push_back(x);
//   }
//   return ans;

// }

//above was dfs


#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> adj[v];
    vector<int>bfs;
  for(auto it:edges){
    int u=it[0];
    int z=it[1];
    adj[u].push_back(z);    
  }
  int indefree[v]={0};
  for(int i=0;i<v;i++){
    for(auto it:adj[i]){
      indefree[it]++;
    }
  }
  queue<int>q;
  for(int i=0;i<v;i++){
    if(indefree[i]==0){
      q.push(i);
    }
  }
  int cnt=0;
  while(!q.empty()){
    int x=q.front();
    q.pop();
    bfs.push_back(x);
    cnt++;
    for(auto it:adj[x]){
      indefree[it]--;
      if(indefree[it]==0){
        q.push(it);
      }
    }
  }
  return bfs;
}