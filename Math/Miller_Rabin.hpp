//need: fastMulti、fastPower
/*bool millerRabin(num n,int times=20){
	if(n==2)return true;
	if(n<2||n%2==0)return false;
	for(int i=1;i<=times;){
        num tem=n-1;
        int j=0;
        while(tem%2==0){tem/=2;j++;}
        num a=((double)rand()/RAND_MAX*(n-2)+0.5)+1;
        num x=fastPower(a,tem,n);
        if(x!=1 && x!=n-1){
            while(j--){
                x=fastMulti(x,x,n);
                if(x==n-1)goto next;
            }
            return false;
        }
        next:i++;
	}
	return true;
}*/
bool miillerRabin(int n,int k=20){
	if(n<=1||n==4)return false;
	if(n<=3)return true;
	int d=n-1;
	while(d%2==0)d/=2;
	for(int i=0;i<k;i++)
		if(![](int d, int n){
        	int a=2+rand()%(n-4);
        	int x=fastPower(a,d,n);
        	if (x==1||x==n-1)return true;
        	while (d!=n-1){
        		x=(x*x)%n;
        		d*=2;
        		if(x==1)return false;
        		if(x==n-1)return true;
        	}
        	return false;
        }(d,n))return false;
	return true;
}
