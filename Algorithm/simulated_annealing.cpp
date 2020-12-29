#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const int d[2]={1,-1};
int n,ans;
struct Point{
    double x,d;
    double getDis(){
        double ans=0;
        for(int i=0;i<n;i++)ans+=abs(x-p[i].x);
        return ans;
    }
}p[105];
void simulatedAnnealing(){
    double T=1e4;
    double T_min=1e-3;
    double r=0.83;
    Point now;
    now.x=rand()%10001;
    now.d=getdis(now);
    while(T>T_min){
        Point next;
        for(int i=0;i<2;i++){
            next.x=now.x+d[i]*T;
            next.d=next.getDis();
            if(next.d<now.d)now=next;
        }
        T*=r;
        if(now.d<ans)ans=now.d;
    }
}
int main(){
    srand(1e9+7);
    ans=1e20;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x;
    }
    for(int i=0;i<10;i++){
        simulatedAnnealing();
    }
    cout<<ans<<endl;
    return 0;
}
