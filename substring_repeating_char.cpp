#include <bits/stdc++.h> 
int uniqueSubstrings(string a)
{
    //Write your code here
    int i=0,j=0;
        unordered_map<char,int>mp;
        int n=a.size();
        int res=0;
        while(j<n){
            mp[a[j]]++;
            if(mp[a[j]]==1){
                res=max(res,j-i+1);
                j++;
            }
            else{
                while(mp[a[j]]>1){
                    mp[a[i]]--;
                    if(mp[a[i]]==0){
                        mp.erase(a[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return res;
        
}