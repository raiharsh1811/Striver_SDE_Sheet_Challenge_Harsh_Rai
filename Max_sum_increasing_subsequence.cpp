#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	for(int ind=n-1;ind>=0;ind--){
		for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
			int len=0+dp[ind+1][prev_ind+1];
			if(prev_ind==-1||rack[ind]>rack[prev_ind]){
				len=max(len,rack[ind]+dp[ind+1][ind+1]);
			}
			dp[ind][prev_ind+1]=len;
		}
		

	}
	return dp[0][0];
}