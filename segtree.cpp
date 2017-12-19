int arr[100001], segtree[4*100001], lazy[4*100001];

void build(int node, int start, int end)
{
	if(start == end)
	{
		segtree[node] = arr[start];
		lazy[node] = 0;
	}
	else
	{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		segtree[node] = min(segtree[2*node], segtree[2*node+1]);
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int X)
{
	if(start > end)
		return;
	if(lazy[node])
	{
		segtree[node] -= lazy[node];
		if(start != end)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(segtree[node] > X)
	{
		segtree[node] -= 1;
		if(start != end)
		{
			lazy[2*node] += 1;
			lazy[2*node+1] += 1;
		}
	}
	else
	{
		if(start == end)
			return;
		int mid = (start+end)/2;
		update(2*node, start, mid, X);
		update(2*node+1, mid+1, end, X);
		segtree[node] = min(segtree[2*node], segtree[2*node+1]);
	}
}


int query(int node, int start, int end, int idx)
{
	if(idx < start || idx > end || start > end)
		return 0;
	if(lazy[node])
	{
		segtree[node] -= lazy[node];
		if(start != end)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start == end)
		return segtree[node];
	else
	{
		int mid = (start+end)/2;
		if(start<=idx && idx<=mid)
			return query(2*node, start, mid, idx);
		else
			return query(2*node+1, mid+1, end, idx);
	}
}