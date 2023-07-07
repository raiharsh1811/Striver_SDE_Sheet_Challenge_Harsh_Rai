#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	vector<int>v(n+1,0);
	for(int i=0;i<=n;i++){
		v[arr[i]]++;
	}
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			x=i;
		}
		if(v[i]==2){
			y=i;
		}
	}
	pair<int,int>res={x,y};
	return res;
}
