#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int i=m-1;
	int j=n-1;
	int li=m+n-1;
	while(j>=0){
		if(i>=0 && arr1[i]>arr2[j]){
			arr1[li]=arr1[i];
			i--;
		}
		else{
			arr1[li]=arr2[j];
			j--;
		}
		li--;
	}
	return arr1;
}