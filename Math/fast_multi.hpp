inline num fastMulti(num a,num b,num mod=0){
    num ans=0;
    while(b){
        if(b&1)ans=(mod)?(ans+a)%mod:ans+a;
      	a=(mod)?(a<<1)%mod:a<<1;
        b>>=1;
    }
    return ans;
}
