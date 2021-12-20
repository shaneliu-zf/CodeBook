#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#pragma GCC optimize(2)
#define endl '\n'
#define int long long
#define IO_optimization ios_base::sync_with_stdio(0),cin.tie(0)

vector<int>cnt(1000005);
vector<int>a;
vector<int>belong;
int now = 0;

struct Query{
    int l;
    int r;
    int id;
};


int cmp(Query a, Query b) {
	return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.l] & 1) ? a.r < b.r : a.r > b.r);
}

int32_t main(){
    IO_optimization;

    int n,m;
    cin>>n;
    a = vector<int>(n+1);
    belong = vector<int>(n+1);
    int size = sqrt(n);
    int bnum = ceil((double)n/size);
    for(int i=1;i<=bnum;i++){
        for(int j=(i-1)*size+1;j<=i*size;j++) {
            belong[j] = i;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    cin>>m;
    vector<Query>q(m);
    vector<int>ans(m);

    for(int i=0;i<m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id = i;
    }

    sort(q.begin(),q.end(),cmp);

    int l=1,r=0;

    for(int i=0;i<m;i++){
        while(l < q[i].l) now -= !--cnt[a[l++]];
        while(l > q[i].l) now += !cnt[a[--l]]++;
        while(r < q[i].r) now += !cnt[a[++r]]++;
        while(r > q[i].r) now -= !--cnt[a[r--]];
        ans[q[i].id] = now;
    }

    for(int a:ans)cout<<a<<endl;
    return 0;
}
