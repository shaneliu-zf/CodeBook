
inline int fastPower(int x,unsigned int y,int p){
	int res = 1;
	x = x % p;
	while (y > 0){
        if (y & 1)res = (res*x) % p;
		y = y>>1;
		x = (x*x) % p;
	}
	return res;
}

/* 好像有問題

inline num fastPower(num a,num b,num mod=0){
	num ans=1;
	while(b){
		if(b&1)ans=fastMulti(ans,a,mod);
		a=fastMulti(a,a,mod);
		b>>=1;
	}
	return ans;
}*/
