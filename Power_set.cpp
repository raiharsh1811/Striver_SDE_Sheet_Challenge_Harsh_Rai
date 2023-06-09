#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> res;
    for(int i=0;i<(1<<v.size());i++){
        vector<int>ans;
        for(int j=0;j<v.size();j++){
            if(i&(1<<j)){
                ans.push_back(v[j]);
            }
        }
        if(ans.size()>0){
            res.push_back(ans);
        }
    }
    sort(res.begin(),res.end());
    return res;
}