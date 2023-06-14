#include <bits/stdc++.h> 
void solve(int ind,vector<int>&arr,int n,vector<int>&ds,vector<vector<int>>&ans){
    ans.push_back(ds);
    for(int i=ind;i<n;i++){
        if(i!=ind && arr[i]==arr[i-1]){
            continue;
        }
        ds.push_back(arr[i]);
        solve(i+1,arr,n,ds,ans);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<int>ds;
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    solve(0,arr,n,ds,ans);
    return ans;
}