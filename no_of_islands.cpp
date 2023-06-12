#include <bits/stdc++.h>
void bfs(int row,int col,int** arr,vector<vector<int>>&vis,int n,int m){
   vis[row][col]=1;
   queue<pair<int,int>>q;
   q.push({row,col});
   while(!q.empty()){
      int x=q.front().first;
      int y=q.front().second;
      q.pop();
      for(int delrow=-1;delrow<=1;delrow++){
         for(int delcol=-1 ;delcol<=1;delcol++){
            int nrow=x+delrow;
            int ncol=y+delcol;
            if(nrow>=0 && ncol>=0 && ncol<m && nrow<n && arr[nrow][ncol]==1&& vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
               q.push({nrow,ncol});
            }
         }
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   vector<vector<int>>vis(n,vector<int>(m,0));
   int count=0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(!vis[i][j] && arr[i][j]==1){
            count++;
            bfs(i,j,arr,vis,n,m);
         }
      }
   }
   return count;
}
