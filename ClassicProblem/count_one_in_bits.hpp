num countOneInBits(num n){
    num count=0;
    while(n){
        ++count;
        n&=n-1;
    }
    return count;
}
