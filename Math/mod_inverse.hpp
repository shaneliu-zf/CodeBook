//need: gcdExtended
num modInverse(num a,num m){
    num x,y;
    num g=gcdExtended(a,m,&x,&y);
    if(g!=1)return 0;
    else return (x%m+m)%m;
}
