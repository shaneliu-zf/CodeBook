inline num max(num x, num y){
    num t=(x-y)>>31;
    return y&(t)|x&~(t);
}
