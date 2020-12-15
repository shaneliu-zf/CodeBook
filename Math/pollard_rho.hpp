//need: gcd、fastMulti、fastPower、millerRabin
inline num pollardRho(num n){
    if(millerRabin(n)){cout<<n<<" ";return n;}
    num p=n;
    while(p==n)p=[](int n){
   	    num c=rand()%(n-1)+1;
    	num k=2,x=1ll*rand()%n+1,y=x;
    	for(num i=2;;i++){
        	x=(fastMulti(x,x,n)+c)%n;
    		num d=gcd(x-y,n);
    		if(d!=1 && d!=n)return d;
    		if(y==x)return n;
    		if(i==k)k<<=1,y=x;
   		}
	}(p);
    return max(pollardRho(p),pollardRho(n/p));
}
