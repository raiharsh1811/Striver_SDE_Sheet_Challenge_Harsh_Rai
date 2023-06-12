#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<int> adj[n+1];
  for(auto it:edges){
    int u=it.first;
    int v=it.second;
    adj[u].push_back(v);    
  }
  int indefree[n+1]={0};
  for(int i=1;i<=n;i++){
    for(auto it:adj[i]){
      indefree[it]++;
    }
  }
  queue<int>q;
  for(int i=1;i<=n;i++){
    if(indefree[i]==0){
      q.push(i);
    }
  }
  int cnt=0;
  while(!q.empty()){
    int x=q.front();
    q.pop();
    cnt++;
    for(auto it:adj[x]){
      indefree[it]--;
      if(indefree[it]==0){
        q.push(it);
      }
    }
  }
  if(cnt==n){
    return false;
  }
  return true;

}