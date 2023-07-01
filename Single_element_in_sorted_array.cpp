int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int l=0,h=arr.size()-1;
	while(l<=h){
		int mid=(l+h)>>1;
		if(mid%2==0){
			if(arr[mid]!=arr[mid+1]){
				h=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		else{
			if(arr[mid]!=arr[mid-1]){
				h=mid-1;
			}
			else{
				l=mid+1;
			}
		}
	}
	return arr[l];
}