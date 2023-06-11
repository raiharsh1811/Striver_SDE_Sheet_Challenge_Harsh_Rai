// #include <bits/stdc++.h>
// vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
// {
// 	// Write your code here.
//     priority_queue<int>q1;
//     priority_queue<int,vector<int>,greater<int>>q2;
//     for(int i=0;i<n;i++){
//         q1.push(arr[i]);
//         q2.push(arr[i]);
//     }
//     while(k>1){
//         q1.pop();
//         q2.pop();
//         k--;
//     }
//     vector<int>ans;
//     ans.push_back(q2.top());
//     ans.push_back(q1.top());
//     return ans;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k) {
  vector<int> ans;
  sort(arr.begin(), arr.end());
  ans.push_back(arr[k - 1]);
  ans.push_back(arr[n - k]);
  return ans;
}