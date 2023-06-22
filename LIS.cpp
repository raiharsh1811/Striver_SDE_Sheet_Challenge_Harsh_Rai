 #include <bits/stdc++.h>
// using namespace std;

// int longestIncreasingSubsequence(int arr[], int n){
    
//     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
//     for(int ind = n-1; ind>=0; ind --){
//         for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
//             int notTake = 0 + dp[ind+1][prev_index +1];
    
//             int take = 0;
    
//             if(prev_index == -1 || arr[ind] > arr[prev_index]){
                
//                 take = 1 + dp[ind+1][ind+1];
//             }
    
//             dp[ind][prev_index+1] = max(notTake,take);
            
//         }
//     }
    
//     return dp[0][0];
// }
// int getAns(int arr[], int n,  int ind, int prev_index, vector<vector<int>>& dp){
    
//     // base condition
//     if(ind == n)
//         return 0;
        
//     if(dp[ind][prev_index+1]!=-1)
//         return dp[ind][prev_index+1];
    
//     int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    
//     int take = 0;
    
//     if(prev_index == -1 || arr[ind] > arr[prev_index]){
//         take = 1 + getAns(arr,n,ind+1,ind,dp);
//     }
    
//     return dp[ind][prev_index+1] = max(notTake,take);
// }


// int longestIncreasingSubsequence(int arr[], int n){
    
//     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
//     return getAns(arr,n,0,-1,dp);
// }


// int longestIncreasingSubsequence(int arr[], int n){
    
//     vector<int> next(n+1,0);
    
//     vector<int> cur(n+1,0);
    
//     for(int ind = n-1; ind>=0; ind --){
//         for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
//             int notTake = 0 + next[prev_index +1];
    
//             int take = 0;
    
//             if(prev_index == -1 || arr[ind] > arr[prev_index]){
                
//                 take = 1 + next[ind+1];
//             }
    
//             cur[prev_index+1] = max(notTake,take);
//         }
//         next = cur;
//     }
    
//     return cur[0];
// }

#include<bits/stdc++.h>
int solve(int arr[],int n){
    if(n==0)
      return 0;
    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i=1;i<n;i++){
        if(arr[i]>ans.back()){
            ans.push_back(arr[i]);
        }
        else{
            int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[index]=arr[i];
        }
    }
    return ans.size();
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    return solve(arr,n);
}