int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int plat=1,res=1;
    int i=1,j=0;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            i++;
            plat++;
        }
        else if(at[i]>dt[j]){
            j++;
            plat--;
        }
        if(plat>res){
            res=plat;
        }
    }
    return res;
}