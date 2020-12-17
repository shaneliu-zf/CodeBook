#include<iostream>
#include<iostream>
using namespace std;
double arr_x[1005],arr_y[1005];
double lagrangePolynomial(double x,int n){
    double ans=0;
    double t1,t2;
    for(int i=0;i<n;i++){
        t1=t2=1;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            t1*=x-arr_x[j];
            t2*=arr_x[i]-arr_x[j];
        }
        ans+=arr_y[i]*(t1/t2);
    }
    return ans;
}
int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr_x[i]>>arr_y[i];
    }
    cin>>x;
    cout<<lagrangePolynomial(x,n)<<endl;
    return 0;
}
