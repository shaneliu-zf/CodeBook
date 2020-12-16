template<typename T>inline T input(){
    T sum=0,fl=1;
    int ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')fl=-1;
    for(;isdigit(ch);ch=getchar())sum=sum*10+ch-'0';
    return sum*fl;
}
int a=input<int>();
