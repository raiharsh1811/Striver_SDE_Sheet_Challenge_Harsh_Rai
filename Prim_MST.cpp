#include <bits/stdc++.h> 

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)

{

    // Write your code here.

 

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    unordered_map<int, list<pair<int, int>>> adj;

    for(int i =0;i<m;i++){

      int u = g[i].first.first;

      int v = g[i].first.second;

      int w = g[i].second;

 

      adj[u].push_back({v,w});

      adj[v].push_back({u,w});

    }

 

    vector<int> key(n+1, INT_MAX);

    vector<int> parent(n+1, -1);

    vector<bool> mst(n+1, false);

 

    key[1] = 0;

    parent[1] = -1;

    pq.push({0,1});

 

    

    //for(int i= 1;i<n;i++ ){

      while(!pq.empty()){

        int mini = INT_MAX;

        int u;

        /*for(int v =1;v<=n;v++){

            if(mst[v] == false &&  key[v] < mini){

                mini = key[v];

                u =v;

            }

        }*/

        u = pq.top().second;

        mini = pq.top().first;

        pq.pop();

    

    if(mst[u]){

      continue;

    }

    mst[u] = true;

 

    for(auto n: adj[u]){

        int v = n.first;

        int w = n.second;

 

        if (mst[v] == false && w < key[v]) {

          key[v] = w;

          pq.push({w,v});

          parent[v] = u;

        }

    }

    }

 

    vector<pair<pair<int, int>, int>> result;

    for(int i =2;i<=n;i++){

      result.push_back({{parent[i], i}, key[i]});

    }

    return result;

}