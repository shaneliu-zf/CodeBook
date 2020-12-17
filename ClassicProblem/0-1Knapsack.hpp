int dp[100005];
int Knapsack(int weight[],int value[],int n,int m){
    for(int i=0;i<n;i++){
	    for(int j=m;j>=0;j--){
            if(j-weight[i]>=0){
                dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
            }
        }
    }
    return dp[m];
}
