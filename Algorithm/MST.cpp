#include<iostream>
#include<algorithm>
using namespace std;
struct edge{int from,to,w;};
int n, m, ans;
int p[100005];
edge e[100005];
int Find(int x){
	if(p[x]!=x)p[x]=Find(p[x]);
	return p[x];
}
bool Same(int x, int y){return Find(x)==Find(y);}
void Union(int x, int y){p[Find(x)]=Find(y);}
bool cmp(edge a,edge b){return a.w<b.w;}
int main(){
	cin>>n>>m;
	for(int i=0;i<=n;i++)p[i]=i;
	for(int i=0;i<m;i++)cin>>e[i].from>>e[i].to>>e[i].w;
	sort(e,e+m,cmp);
	for(int i=0;i<m;i++){
		if(!Same(e[i].from,e[i].to)){
			Union(e[i].from,e[i].to);
			ans+=e[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}
