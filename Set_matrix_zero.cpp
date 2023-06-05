#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<pair<int, int>> a;
    ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                a.push_back({i, j});
            }
        }
    }
    for (auto it : a)
    {
        int x = it.first;
        int y = it.second;
        for (int i = 0; i < m; i++)
        {
            matrix[x][i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            matrix[i][y] = 0;
        }
    }
}