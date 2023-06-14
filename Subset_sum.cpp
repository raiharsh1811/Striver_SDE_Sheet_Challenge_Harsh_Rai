#include <bits/stdc++.h> 
void solve(int ind,vector<int>&num,vector<int>&ans,int sum,int n){
    if(ind==n){
        ans.push_back(sum);
        return ;
    }
    solve(ind+1,num,ans,sum+num[ind],n);
    solve(ind+1,num,ans,sum,n);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ans;
    int n=num.size();
    solve(0,num,ans,0,n);
    sort(ans.begin(),ans.end());
    return ans;
}