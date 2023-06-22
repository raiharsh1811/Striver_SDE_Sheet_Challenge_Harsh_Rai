#include <bits/stdc++.h>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
  // Write your code here
  vector<vector<int>> dp(n, vector<int>(w + 1, 0));
  // base
  for (int i = weights[0]; i <= w; i++) {
    dp[0][i] = values[0];
  }
  for (int ind = 1; ind < n; ind++) {
    for (int weight = 0; weight <= w; weight++) {
      int nottake = dp[ind - 1][weight];
      int take = INT_MIN;
      if (weights[ind] <= weight) {
        take = dp[ind - 1][weight - weights[ind]] + values[ind];
      }
      dp[ind][weight] = max(take, nottake);
    }
  }
  return dp[n-1][w];
}