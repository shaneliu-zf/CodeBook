#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<string>
#include<sstream>
using namespace std;

#define int long long
#define endl '\n'
#define IO_optimization ios_base::sync_with_stdio(0),cin.tie(0)
template<typename T>ostream & operator<<(ostream &out,vector<T>&v){
    for(int i=0;i<v.size();i++){
        out<<v[i]<<" \0"[i==v.size()-1];
    }
    return out;
}
template<typename T>istream & operator>>(istream &in,vector<T> &v){
    for(T &i:v)in>>i;
    return in;
}
template<typename T>string toString(T x){
    stringstream ss;
    ss << x;
    return ss.str();
}
template<typename T>int toInt(T x){
    stringstream ss;
    int ans;
    ss<<x;
    ss>>ans;
    return ans;
}
inline int nextInt(){
	int x = 0;
    int c = getchar();
    bool neg = false;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = getchar();
	if(c == '-') neg = true, c = getchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = getchar();
	if(neg) x = -x;
	return x;
}
inline int mod(int a,int b){
    return (a%b+b)%b;
}

void init();
void task();
int32_t main(){
    IO_optimization;
    int t=1;
    //cin>>t;
    while(t--)task();
    return 0;
}

void init(){}


void task(){
    
}
