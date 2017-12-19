// l = left index of the array, r = right index of the array,
// arr = main array for which to compute inversions
// tmp_vec = temporary vector to store intermediate result (should be of size N)
// NOTE: arr is modified in the process ! (sorted)
int count_inv(int l, int r,vector<int>& arr,vector<int>& tmp_vec){
	if (l==r) return 0;
	int mid = l + (r-l)/2;
	int inv_l = count_inv(l,mid,arr,tmp_vec);
	int inv_r = count_inv(mid+1,r,arr,tmp_vec);
	int p1 = l, p2 = mid+1;
	int extra_inv = 0;
	int idx = l;
	while(p1<=mid && p2 <= r)
	{
		if(arr[p1] <= arr[p2])
			tmp_vec[idx++]=arr[p1++];
		else
		{
			extra_inv += (mid-p1+1);
			tmp_vec[idx++]=arr[p2++];
		}
	}
	while(p1<=mid)
		tmp_vec[idx++]=arr[p1++];
	while(p2<=r)
		tmp_vec[idx++]=arr[p2++];
	for(int i=l;i<=r;i++)
		arr[i]=tmp_vec[i];
	return (extra_inv+inv_r+inv_l);
}
