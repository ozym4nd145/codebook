int dp[MAXN][MAXLOGN];
int depth[MAXN]; //depth of nodes (root is 0)
int parent[MAXN]; //immediate parent of node (for root is -1)
void preprocess_lca(int N)
{
	//Initialize DP. DP[i][j] stores the parent of node i at height 2^i from node.
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; (1<<j) < N; j++)
			dp[i][j] = -1;
	//At height 2^0 = 1, DP[node][0] = parent[node]
	for(int i = 0; i < N ; i ++)
		dp[i][0] = parent[i];
	//Now start computing
	for(int j = 1; (1<<j) < N; j++)
		for(int i = 0 ; i < N ; i++)
			if(dp[i][j-1] != -1)
				dp[i][j] = dp[dp[i][j-1]][j-1];
}

int lca(int u, int v)
{
	u--, v--;
	if(depth[u] < depth[v])
		swap(u, v);
	int log = 0;
	//First, bring u to same level as that of v
	while((1 << log) <= depth[u]) //for "<", log will exceed unless 1<<log == depth[u], and needs to be decreased eventually
		log++;
	log--;
	for(int i = log; i>=0; i--)
		if(depth[u] - (1<<i) >= depth[v])
			u = dp[u][i];
	//now ensured same level
	if(u == v)
		return u;
	//now start going up
	for(int i = log; i>=0; i--)
		if (dp[u][i] != -1 && dp[u][i] != dp[v][i])
   	    	u = dp[u][i], v = dp[v][i];
	return parent[u];
}
