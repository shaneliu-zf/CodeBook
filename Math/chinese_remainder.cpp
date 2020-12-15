//need: gcdExtended
num chineseRemainder(num a[],num w[],int len){
	num d,x,y,m,n=1,ret=0;
		for (int i=0;i<len;i++)n*=w[i];
		for (int i=0;i<len;i++){
				m=n/w[i];
				d=gcdExtended(w[i],m,&x,&y);
				ret=(ret+y*m*a[i])%n;
		}
		return (n+ret%n)%n;
}
