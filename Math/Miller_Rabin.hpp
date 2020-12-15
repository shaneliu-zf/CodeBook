//need: fastMulti、fastPower
bool millerRabin(num n,int times=20){
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
}
