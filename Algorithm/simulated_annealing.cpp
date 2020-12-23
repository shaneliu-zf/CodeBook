#include<iostream>
#include<cstdlib>
using namespace std;

int a[1000005];

double simulatedAnnealing(int n,int now){
    double T=3000;
    double T_min=1e-12;
    double r=0.996;
    while(T>T_min){
        val next=now+(rand()*2-RAND_MAX)*T;
        double delta=a[now]-a[next];
        if(delta<0)now=next;
        else{
            if( (-delta/T)*RAND_MAX > rand() ){
                now=next;
            }
        }
        if(a[now]>a[ans])ans=now;
        T*=r;
    }
    return ans;
}

int main(){
    srand(1000);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    double ans=n/2;
    for(int i=0;i<5;i++){
        ans=simulatedAnnealing(ans);
    }
    cout<<a[ans]<<endl;
    return 0;
}

/*

10
4 5 3 4 2 8 5 3 1 1

*/
