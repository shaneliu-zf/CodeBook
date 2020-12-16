#include<iostream>
using namespace std;

int a[1005];
int find(int x){
    if(a[x]!=x)a[x]=find(a[x]);
    return a[x];
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=i;
    int x,y;
    while(m--){
        cin>>x>>y;
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy)a[fy]=fx;
    }
    //for(int i=1;i<=n;i++)a[i]=find(a[i]);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==i)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
