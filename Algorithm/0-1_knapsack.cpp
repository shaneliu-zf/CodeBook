#include<iostream>
using namespace std;
struct item{
    int weight,value;
}items[1005];
int dp[100005];
int main(){
  	int n,m;
  	cin>>n>>m;
  	for(int i=0;i<n;i++)cin>>items[i].weight>>items[i].value;
		for(int i=0;i<n;i++){
		    for(int j=m;j>=0;j--){
            if(j-items[i].weight>=0){
                dp[j]=max(dp[j],dp[j-items[i].weight]+items[i].value);
            }
        }
    }
    cout<<dp[m]<<endl;
	return 0;
}
