#include <bits/stdc++.h> 
struct meeting {
    int s;
    int e;
    int p;
};
bool static comparator(struct meeting m1, meeting m2) {
         if (m1.e < m2.e) return true;
         else if (m1.e > m2.e) return false;
         else if (m1.p < m2.p) return true;
         return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].s=start[i];
        meet[i].e=end[i];
        meet[i].p=i+1;
    }sort(meet,meet+n,comparator);
    vector<int>ans;
    ans.push_back(meet[0].p);
    int limit=meet[0].e;
    for(int i=1;i<n;i++){
        if(meet[i].s>limit){
            ans.push_back(meet[i].p);
            limit=meet[i].e;
        }
    }
    return ans;
}
