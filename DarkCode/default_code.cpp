#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

#define int long long
#define debug(x) cerr << "\e[1;31m" << #x << " = " << (x) << "\e[0m\n"

template<typename T>ostream & operator<<(ostream &out,vector<T> &v){
    for(T i:v)out<<i<< (next(&i)!=v.end())?:" ";
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

void init();
void task();
int32_t main(){
    init();
    int t=1;
    cin>>t;
    while(t--)task();
    return 0;
}

void init(){}


void task(){}
