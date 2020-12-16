#include<iostream>
#include<algorithm>
using namespace std;

struct edge{
	int from;
	int to;
	int w;
};

int n, m, ans;		// n個節點, m 條邊, n, m < 100000
int p[100005];		// 節點的 parent
edge e[100005];		// 邊的資料

int Find(int x){
	if(p[x]!=x)p[x]=Find(p[x]);
	return p[x];
}

bool Same(int x, int y){return Find(x)==Find(y);}
void Union(int x, int y){p[Find(x)]=Find(y);}
bool cmp(edge a,edge b){return a.w<b.w;}
int main() {
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

/*
範例輸入1:

	6 6
	1 2 7
	1 3 1
	2 4 3
	2 5 5
	3 6 2
	4 6 4

範例輸出1:

	15

範例輸入2:

	7 7
	1 2 4
	1 3 2
	1 4 3
	2 5 7
	2 7 1
	2 6 6
	3 5 5

範例輸出2:

	21
*/
