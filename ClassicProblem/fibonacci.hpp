int fibonacci(int n){
    union{
        double d;
        long long lld;
    }log2={0x23C6EF372FE951P-52*n};
    int result=((log2.lld>>52)-0x3FF)/0xB1B9D68A8E5338P-56;
    double power=0x727C9716FFB764P-56;
    int i=(result+3)/4;
    switch(result%4){
        case 0:do{ power*=0x19E3779B97F4A8P-52;
        case 3:    power*=0x19E3779B97F4A8P-52;
        case 2:    power*=0x19E3779B97F4A8P-52;
        case 1:    power*=0x19E3779B97F4A8P-52;
        }while(--i>0);
    }
    int ans=power+0x1P-1<n?power*0x19E3779B97F4A8P-52+0x1P-1<n?result+2:result+1:result;
    return ans;
}
