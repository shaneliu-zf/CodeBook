double lagrangePolynomial(double arr_x[],double arr_y[],double x,int n){
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
