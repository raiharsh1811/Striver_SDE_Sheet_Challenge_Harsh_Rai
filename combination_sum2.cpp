#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<list>
void findsum(int ind,vector<int> &arr, int n, int target,vector<vector<int>>&ans,vector<int>&ds){
	if(target==0){
		ans.push_back(ds);
		return;
	}
	for(int i=ind;i<n;i++){
		if(i>ind && arr[i]==arr[i-1]){
			continue;
		}
		if(arr[i]>target) break;
		ds.push_back(arr[i]);
		findsum(i+1,arr,n,target-arr[i],ans,ds);
		ds.pop_back();
	}
}



vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	vector<int>ds;
	findsum(0,arr, n,target,ans,ds);
	return ans;
}
