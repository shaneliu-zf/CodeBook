#include<iostream>
using namespace std;
int map[1005][1005];
int dis[1005];
bool vis[1005];
void dijkstra(int start,int end,int n){
    int pos;
    for(int i=0;i<n;i++)dis[i]=map[i][start];
    vis[start]=true;
    for(int i=0;i<n-1;i++){
        pos=s;
        int min=inf;
        for(int j=0;j<n;j++){
            if(!vis[j] && dis[j]<min){
                min=dis[j];
                pos=j;
            }
        }
        vis[pos]=true;
        for(int j=0;j<n;j++){
            if(!vis[j] && dis[j]>dis[pos]+map[j][pos]){
                dis[j]=dis[pos]+map[j][pos];
            }
        }
    }
    return;
}
int main(){
    int n,m;
    int a,b,x;
    int start,end;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]=1000000;
        }
        map[i][i]=0;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>x;
        map[a][b]=map[b][a]=x;
    }
    cin>>start>>end;
    dijkstra(start,end,n);
    cout<<(dis[end]!=1000000)?dis[end]:-1<<endl;
    return 0;
}
