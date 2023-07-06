#include <bits/stdc++.h> 
bool comparator(pair<int,int>&it1,pair<int,int>&it2){
    double r1=(double)it1.second/(double)it1.first;
     double r2=(double)it2.second/(double)it2.first;
     return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comparator);
    int curr=0;
    double val=0;
    for(int i=0;i<n;i++){
        if(curr+items[i].first<=w){
            val+=items[i].second;
            curr+=items[i].first;
        }
        else{
            int remain=w-curr;
            val+=(items[i].second/(double)items[i].first)*(double)remain;
            break;
        }
    }
    return val;
}