bool isSquareNumber(long long n){
  	if(n<1)return false;
	for(long long i=1;n;i+=2)n-=i;
    return !n;
}
