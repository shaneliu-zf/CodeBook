# CodeBook by 櫛風
[toc]
## DarkCode
### rope
```c++
#include<ext/rope>
using namespace __gnu_cxx;
rope<char>str;
```
### thread
```c++
#include<Thread>
thread t([](int i){cout<<i<<endl;},1);
t.join();
```
### default code
```c++
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
```
## OOP
### function
```c++
#include<vector>
class func:std::vector<double>{
public:
    func(int n=0){resize(n);}
    func(std::vector<double>a){
        resize(a.size());
        for(int i=0;i<a.size();i++)at(i)=a[i];
    }
    void print(){
        bool first=true;
        for(int i=size()-1;i>=0;i--){
            if(at(i)){
                std::cout<<((first)?(first=false,""):"+")
                         <<at(i)<<((i>=1)?"x":"");
                if(i>1)std::cout<<"^"<<i;
            }
        }
        std::cout<<std::endl;
    }
    double setX(double x){
        double ans=0;
        double t=1;
        for(int i=0;i<size();i++){
            ans+=at(i)*t;
            t*=x;
        }
        return ans;
    }
    friend func prime(func a){
        func b;
        for(int i=1;i<a.size();i++){
            b.push_back(a[i]*i);
        }
        return b;
    }
};
```
### BigInteger
```c++
#include<algorithm>
#include<sstream>
#include<vector>
#include<cmath>
#include<iomanip>
class bigN:std::vector<long long>{
private:
    const static int base=1000000000,width=log10(base);
    bool negative;
    bigN convert_base(int old_width,int new_width)const{
        vector<long long>p(std::max(old_width,new_width)+1,1);
        for(size_t i=1;i<p.size();++i)p[i]=p[i-1]*10;
            bigN ans;
            long long cur=0;
            int cur_id=0;
            for(size_t i=0;i<size();++i){
                cur+=at(i)*p[cur_id];
                cur_id+=old_width;
                while(cur_id>=new_width){
                    ans.push_back(cur%p[new_width]);
                    cur/=p[new_width];
                    cur_id-=new_width;
                }
            }
            return ans.push_back(cur),ans.trim(),ans;
    }
    bigN karatsuba(const bigN &b)const{
        bigN res;
        res.resize(size()*2);
        if(size()<=32){
            for(size_t i=0;i<size();++i){
                for(size_t j=0;j<size();++j){
                    res[i+j]+=at(i)*b[j];
                }
            }
            return res;
        }
        size_t k=size()/2;
        bigN a1(begin(),begin()+k);
        bigN a2(begin()+k,end());
        bigN b1(b.begin(),b.begin()+k);
        bigN b2(b.begin()+k,b.end());
        bigN a1b1=a1.karatsuba(b1);
        bigN a2b2=a2.karatsuba(b2);
        for(size_t i=0;i<k;++i)a2[i]+=a1[i];
        for(size_t i=0;i<k;++i)b2[i]+=b1[i];
        bigN r=a2.karatsuba(b2);
        for(size_t i=0;i<a1b1.size();++i)r[i]-=a1b1[i];
        for(size_t i=0;i<a2b2.size();++i)r[i]-=a2b2[i];
        for(size_t i=0;i<r.size();++i)res[i+k]+=r[i];
        for(size_t i=0;i<a1b1.size();++i)res[i]+=a1b1[i];
        for(size_t i=0;i<a2b2.size();++i)res[i+size()]+=a2b2[i];
        return res;
    }
    void trim(){
        while(size()&&!back())pop_back();
        if(empty())negative=0;
    }
    void carry(int _base=base){
        for(size_t i=0;i<size();++i){
            if(at(i)>=0&&at(i)<_base)continue;
            if(i+1u==size())push_back(0);
            int r=at(i)%_base;
            if(r<0)r+=_base;
            at(i+1)+=(at(i)-r)/_base;
            at(i)=r;
        }
    }
    int abscmp(const bigN &b)const{
        if(size()>b.size())return 1;
        if(size()<b.size())return -1;
        for(int i=int(size())-1;i>=0;--i){
            if(at(i)>b[i])return 1;
            if(at(i)<b[i])return -1;
        }
        return 0;
    }
    int cmp(const bigN &b)const{
        if(negative!=b.negative)return negative?-1:1;
        return negative?-abscmp(b):abscmp(b);
    }
    bigN abs()const{
        bigN res=*this;
        return res.negative=0,res;
    }
public:
    bigN():negative(0){}
    bigN(const_iterator a,const_iterator b):vector<long long>(a,b){}
    bigN(std::string s){
        if(s.empty())return;
        if(s[0]=='-')negative=1,s=s.substr(1);
        else negative=0;
        for(int i=int(s.size())-1;i>=0;i-=width){
            long long t=0;
            for(int j=std::max(0,i-width+1);j<=i;++j)
                t=t*10+s[j]-'0';
            push_back(t);
        }
        trim();
    }
    template<typename T>bigN(const T &x){
        std::stringstream ss;
        ss<<x;
        *this=ss.str();
    }
    bool operator<(const bigN&b)const{return cmp(b)<0;}
    bool operator>(const bigN&b)const{return cmp(b)>0;}
    bool operator<=(const bigN&b)const{return cmp(b)<=0;}
    bool operator>=(const bigN&b)const{return cmp(b)>=0;}
    bool operator==(const bigN&b)const{return !cmp(b);}
    bool operator!=(const bigN&b)const{return cmp(b)!=0;}
    bigN operator-()const{bigN res=*this;return res.negative=!negative,res.trim(),res;}
    bigN operator+(const bigN &b)const{
        if(negative)return -(-(*this)+(-b));
        if(b.negative)return *this-(-b);
        bigN res=*this;
        if(b.size()>size())res.resize(b.size());
        for(size_t i=0;i<b.size();++i)res[i]+=b[i];
        return res.carry(),res.trim(),res;
    }
    bigN operator-(const bigN &b)const{
        if(negative)return -(-(*this)-(-b));
        if(b.negative)return *this+(-b);
        if(abscmp(b)<0)return -(b-(*this));
        bigN res=*this;
        if(b.size()>size())res.resize(b.size());
        for(size_t i=0;i<b.size();++i)res[i]-=b[i];
        return res.carry(),res.trim(),res;
    }
    bigN operator*(const bigN &b)const{
        const static int mul_base=1000000,mul_width=log10(mul_base);
        bigN A=convert_base(width,mul_width);
        bigN B=b.convert_base(width,mul_width);
        int n=std::max(A.size(),B.size());
        while(n&(n-1))++n;
        A.resize(n),B.resize(n);
        bigN res=A.karatsuba(B);
        res.negative=negative!=b.negative;
        res.carry(mul_base);
        res=res.convert_base(mul_width,width);
        return res.trim(),res;
    }
    bigN operator*(long long b)const{
        bigN res=*this;
        long long a;
        if(b<0)res.negative=!negative,b=-b;
        for(size_t i=0,is=0;i<res.size()||is;++i){
            if(i==res.size())res.push_back(0);
            a=res[i]*b+is;
            is=a/base;
            res[i]=a%base;
        }
        return res.trim(),res;
    }
    bigN operator/(const bigN &b)const{
        int norm=base/(b.back()+1);
        bigN x=abs()*norm;
        bigN y=b.abs()*norm;
        bigN q,r;
        q.resize(x.size());
        for(int i=int(x.size())-1;i>=0;--i){
            r=r*base+x[i];
            int s1=r.size()<=y.size()?0:r[y.size()];
            int s2=r.size()<y.size()?0:r[y.size()-1];
            int d=((long long)(base)*s1+s2)/y.back();
            r=r-y*d;
            while(r.negative)r=r+y,--d;
            q[i]=d;
        }
        q.negative=negative!=b.negative;
        return q.trim(),q;
    }
    bigN operator%(const bigN &b)const{return *this-(*this/b)*b;}
    bigN operator<<(const int &b)const{
        bigN res=*this;
        for(int i=0;i<b;i++)res*=2;
        return res.carry(),res.trim(),res;
    }
    bigN operator>>(const int &b)const{
        bigN res=*this;
        for(int i=0;i<b;i++)res/=2;
        return res.carry(),res.trim(),res;
    }
    friend std::istream& operator>>(std::istream &ss,bigN &b){
        std::string s;
        return ss>>s,b=s,ss;
    }
    friend std::ostream& operator<<(std::ostream &ss,const bigN &b){
        if(b.negative)ss<<'-';
        ss<<(b.empty()?0:b.back());
        for(int i=int(b.size())-2;i>=0;--i)
        ss<<std::setw(width)<<std::setfill('0')<<b[i];
        return ss;
    }
    template<typename T>operator T(){
        std::stringstream ss;
        ss<<*this;
        T res;
        return ss>>res,res;
    }
    friend bigN abs(bigN a){return a.abs();}
    bigN operator+=(const bigN &other){*this=(*this)+(other);return *this;}
    bigN operator-=(const bigN &other){*this=(*this)-(other);return *this;}
    bigN operator*=(const bigN &other){*this=(*this)*(other);return *this;}
    bigN operator/=(const bigN &other){*this=this->operator/(other);return *this;}
    bigN operator<<=(const bigN &other){*this=(*this)<<(other);return *this;}
    bigN operator>>=(const bigN &other){*this=(*this)>>(other);return *this;}
    bigN operator++(){(*this)+=1;return *this;}
    bigN operator++(int){*this+=1;return *this;}
    bigN operator--(){*this-=1;return *this;}
    bigN operator--(int){*this-=1;return *this;}
    bool operator!(){return (*this)==0;}
};
```
### Matrix
```c++
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <cassert>

class Matrix:std::vector<std::vector<double>>{
private:
	int maxL;
public:
	Matrix(int n,int m,double a=0){
		resize(n);
		maxL=1;
		for(int i=0;i<size();i++){
			at(i).resize(m);
			if(n<=m)at(i).at(i)=a;
		}
	}
	Matrix(std::vector<std::vector<double>>a){
		int t;
		resize(a.size());
		for(int i=0;i<size();i++){
			at(i).resize(a[i].size());
			for(int j=0;j<a[i].size();j++){
				at(i).at(j)=a[i][j];
				t=log10(abs(at(i).at(j)))+1;
				if(at(i).at(j)<0)t++;
				if(t>maxL)maxL=t;
			}
		}
	}
	int row()const{return size();}
	int column()const{return at(0).size();}
	bool isSqure(){return row()==column();}
	void operator+=(Matrix other){*this=*this+other;}
	void operator-=(Matrix other){*this=*this-other;}
	void operator*=(Matrix other){*this=*this*other;}
	void operator^=(int times){*this=*this^times;}
	void print(){
		for(int i=0;i<row();i++){
			if(i==0 && i==row()-1)std::cout<<"[";
			else if(i==0)std::cout<<"⎡";
			else if(i==row()-1)std::cout<<"⎣";
			else std::cout<<"⎢";
			for(int j=0;j<column();j++){
				std::cout<<std::setw(maxL)<<at(i).at(j);
				if(j==column()-1){
					if(i==0 && i==row()-1)std::cout<<"]";
					else if(i==0)std::cout<<"⎤";
					else if(i==row()-1)std::cout<<"⎦";
					else std::cout<<"⎥";
				}
				else std::cout<<" ";
			}
			std::cout<<std::endl;
		}
	}
	friend std::ostream & operator<<(std::ostream &out,const Matrix &a){
		for(int i=0;i<a.row();i++){
			for(int j=0;j<a.column();j++){
				out<<std::setw(a.maxL)<<a[i][j]<<" \n"[j==a.column()-1];
			}
		}
		return out;
	}
	friend std::istream & operator>>(std::istream &in,Matrix &a){
		int t;
		for(int i=0;i<a.row();i++){
			for(int j=0;j<a.column();j++){
				in>>a[i][j];
				t=log10(abs(a[i][j]))+1;
				if(a[i][j]<0)t++;
				if(t>a.maxL)a.maxL=t;
			}
		}
		return in;
	}
	friend int operator==(Matrix a,Matrix b){
		if(a.row()!=b.row() || a.column()!=b.column())return 0;
		for(int i=0;i<a.row();i++){
			for(int j=0;j<a.column();j++){
				if(a[i][j]!=b[i][j])return -1;
			}
		}
		return 1;
	}
	friend bool operator!=(Matrix a,Matrix b){return !(a==b);}
	friend Matrix operator+(Matrix a,Matrix b){
		assert(a==b);
		std::vector<std::vector<double>>c;
		c.resize(a.row());
		for(int i=0;i<a.row();i++){
			c[i].resize(a.column());
			for(int j=0;j<a.column();j++){
				c[i][j]=a[i][j]+b[i][j];
			}
		}
		return std::move(Matrix(c));
	}
	friend Matrix operator-(Matrix a,Matrix b){return move(a+(-1*b));}
	friend Matrix operator*(Matrix a,double t){
		Matrix b(a.row(),a.column(),t);
		return std::move(a*b);
	}
	friend Matrix operator*(double t,Matrix a){return a*t;}
	friend Matrix operator*(Matrix a,Matrix b){
		assert(a==b);
		std::vector<std::vector<double>>c;
		c.resize(a.row());
		for(int i=0;i<a.row();i++){
			c[i].resize(a.column());
			for(int j=0;j<a.column();j++){
				for(int z=0;z<a.column();z++){
					c[i][j]+=a[i][z]*b[z][j];
				}
			}
		}
		return std::move(Matrix(c));
	}
	friend Matrix operator^(Matrix a,int t){
        if(t==0)return a;
		if(t<0)a=inverse(a^(t*-1));
		Matrix b=a;
		while(--t)b=b*a;
		return std::move(b);
	}
	friend Matrix T(Matrix a){
		std::vector<std::vector<double>> c;
		c.resize(a.column());
		for(int i=0;i<a.column();i++){
			c[i].resize(a.row());
			for(int j=0;j<a.row();j++){
				c[i][j]=a[j][i];
			}
		}
		return std::move(Matrix(c));
	}
	friend Matrix inverse(Matrix a){
		assert(a.isSqure());
		double d=det(a);
		assert(d);
		return (1/d)*adj(a);
	}
	friend double det(Matrix a){
		assert(a.isSqure());
		double ans=0;
		if(a.row()==1)ans=a[0][0];
		else for(int i=0;i<a.column();i++){
			ans+=pow(-1,i)*a[0][i]*det(cof(a,0,i));
		}
		return std::move(ans);
	}
	friend Matrix cof(Matrix a,int x,int y){
		assert(a.isSqure());
		std::vector<std::vector<double>>c;
		c.resize(a.row()-1);
		int q=0,w=0;
		for(int i=0;i<a.row()-1;i++){
			c[i].resize(a.column()-1);
			w=0;
			if(q==x)q++;
			for(int j=0;j<a.column()-1;j++){
				if(w==y)w++;
				c[i][j]=a[q][w];
				w++;
			}
			q++;
		}
		return std::move(Matrix(c));
	}
	friend Matrix adj(Matrix a){
		assert(a.isSqure());
		std::vector<std::vector<double>>c;
		c.resize(a.row());
		for(int i=0;i<a.row();i++){
			c[i].resize(a.column());
			for(int j=0;j<a.column();j++){
				c[i][j]=pow(-1,i+j)*det(cof(a,i,j));
			}
		}
		return std::move(T(Matrix(c)));
	}
};
```
### fraction
```c++
#include<algorithm>
class Frac:std::pair<int,int>{
public:
	Frac(){first=0;second=1;}
	Frac(int a,int b=1){
		int g=std::__gcd(a,b);
        if(second<0){first*=-1;second*=-1;}
        first=a/g;second=b/g;
    }
    Frac operator=(Frac b){first=b.first;second=b.second;return *this;}
    friend Frac operator+(Frac a,Frac b){
    	return Frac(a.first*b.second+b.first*a.second,a.second*b.second);
    }
    friend Frac operator-(Frac a,Frac b){return a+(-1*b);}
    friend Frac operator*(Frac a,Frac b){ return Frac(a.first*b.first,a.second*b.second);}
    friend Frac operator/(Frac a,Frac b){return a*inverse(b);}
    friend void operator+=(Frac a,Frac b){a=a+b;return;}
    friend void operator-=(Frac a,Frac b){a=a-b;return;}
    friend void operator*=(Frac a,Frac b){a=a*b;return;}
    friend void operator/=(Frac a,Frac b){a=a/b;return;}
    friend bool operator==(Frac a,Frac b){return a.first==b.first && a.second==b.second;}
    friend bool operator!=(Frac a,Frac b){return !(a==b);}
    friend bool operator<(Frac a,Frac b){return a.first*b.second<b.first*a.second;}
    friend bool operator>(Frac a,Frac b){return b<a;}
	friend bool operator<=(Frac a,Frac b){return !(b<a);}
	friend bool operator>=(Frac a,Frac b){return !(a<b);}
    friend std::ostream & operator<<(std::ostream &out,const Frac &x){
      	out<<x.first;
    	if(x.second!=1)out<<"/"<<x.second;
        return out;
    }
    friend std::istream & operator>>(std::istream &in,Frac &x){
    	int a,b;
    	in>>a>>b;
        x=Frac(a,b);
		return in;
    }
    friend Frac inverse(Frac a){return Frac(a.second,a.first);}
};
```
## JAVA
### BigInteger
```java
import java.math.BigInteger;
BigInteger n1,n2,ans;
n1=new BigInteger(keyboard.next());
n2=new BigInteger(keyboard.next());
ans=n1.add(n2));
ans=n1.subtract(n2);
ans=n1.multiply(n2));
ans=n1.divide(n2));
ans=n1.mod(n2));
```
### default code
```java
import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner keyboard=new Scanner(System.in);
		String str;
		int num;
		while(keyboard.hasNext()){
			str=keyboard.next();
			System.out.println(str);
			num=keyboard.nextInt();
			System.out.println(num);
		}
	}
}
```
## Algorithm
### dijkstra
```c++
#include<iostream>
using namespace std;
int map[1005][1005];
int dis[1005];
bool vis[1005];
void dijkstra(int start,int end,int n){
    int pos;
    for(int i=0;i<n;i++)dis[i]=map[i][start];
    vis[start]=true;
    for(int i=0;i<n-1;i++){
        pos=s;
        int min=inf;
        for(int j=0;j<n;j++){
            if(!vis[j] && dis[j]<min){
                min=dis[j];
                pos=j;
            }
        }
        vis[pos]=true;
        for(int j=0;j<n;j++){
            if(!vis[j] && dis[j]>dis[pos]+map[j][pos]){
                dis[j]=dis[pos]+map[j][pos];
            }
        }
    }
    return;
}
int main(){
    int n,m;
    int a,b,x;
    int start,end;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]=1000000;
        }
        map[i][i]=0;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>x;
        map[a][b]=map[b][a]=x;
    }
    cin>>start>>end;
    dijkstra(start,end,n);
    cout<<(dis[end]!=1000000)?dis[end]:-1<<endl;
    return 0;
}
```
### LIS
```c++
template<class T>vector<T> LIS(vector<T> s){
    if(s.empty())return s;
    vector<int>v;
    v.push_back(s[0]);
    for(int i=1;i<s.size();i++){
        double n=s[i];
        if(n>v.back())v.push_back(n);
        else{
            *lower_bound(v.begin(),v.end(),n)=n;
        }
    }
    return v;
}

/*template<class T>int LIS(vector<T>& v){
    if(!v.size())return 0;
    vector<int>len(v.size(),1);
    for(int i=1;i<v.size();i++){
        for(int j=0;j<i;j++){
            if(v[j]<=v[i])
                len[i]=max(len[i],len[j]+1);
        }
	}
    int result=0;
    for(int l:len)if(result<l)result=l;
    return result;
}*/
```
### KMP
```c++
int KMP(string pat,string txt){
    vector<vector<int>>dp(pat.length(),vector<int>(256,0));
    dp[0][pat[0]]=1;
    int x=0;
    for(int j=1;j<pat.length();j++){
        for(int c=0;c<256;c++)dp[j][c]=dp[x][c];
        dp[j][pat[j]]=j+1;
        x=dp[x][pat[j]];
    }
    int j=0;
    for(int i=0;i<txt.length();i++){
        j=dp[j][txt[i]];
        if(j==pat.length())return i-pat.length()+1;
    }
    return -1;
}
```
### Union find
```c++
#include<iostream>
using namespace std;
int a[1005];
int find(int x){
    if(a[x]!=x)a[x]=find(a[x]);
    return a[x];
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=i;
    int x,y;
    while(m--){
        cin>>x>>y;
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy)a[fy]=fx;
    }
    for(int i=1;i<=n;i++)a[i]=find(a[i]);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==i)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
```
### MST
```c++
#include<iostream>
#include<algorithm>
using namespace std;
struct edge{int from,to,w;};
int n, m, ans;
int p[100005];
edge e[100005];
int Find(int x){
	if(p[x]!=x)p[x]=Find(p[x]);
	return p[x];
}
bool Same(int x, int y){return Find(x)==Find(y);}
void Union(int x, int y){p[Find(x)]=Find(y);}
bool cmp(edge a,edge b){return a.w<b.w;}
int main(){
	cin>>n>>m;
	for(int i=0;i<=n;i++)p[i]=i;
	for(int i=0;i<m;i++)cin>>e[i].from>>e[i].to>>e[i].w;
	sort(e,e+m,cmp);
	for(int i=0;i<m;i++){
		if(!Same(e[i].from,e[i].to)){
			Union(e[i].from,e[i].to);
			ans+=e[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}
```
## Math
### Newton Raphson Method
```c++
double Newton_Raphson_Method(func f,double x=1){
    while(abs(f.setX(x))>0.000001)
      	x-=(f.setX(x)/prime(f).setX(x));
    return x;
}
```
### square number
```c++
bool isSquareNumber(long long n){
  	if(n<1)return false;
	for(long long i=1;n;i+=2)n-=i;
    return !n;
}
```
### inverse sqrt
```c++
double invSqrt(double x){
    double xhalf=0.5f*x;
    int i=*(int*)&x;
    i=0x5f3759df-(i>>1);
    x=*(double*)&i;
    x=x*(1.5f-xhalf*x*x);
    return x;
}
```
### fast power
```c++

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
```
### langrange polynomial
```c++
double lagrangePolynomial(double arr_x[],double arr_y[],double x,int n){
    double ans=0;
    double t1,t2;
    for(int i=0;i<n;i++){
        t1=t2=1;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            t1*=x-arr_x[j];
            t2*=arr_x[i]-arr_x[j];
        }
        ans+=arr_y[i]*(t1/t2);
    }
    return ans;
}
```
### gcd extended
```c++
num gcdExtended(num a,num b,num *x,num *y){
    if(!a){*x=0,*y=1;return b;}
    num x1,y1;
    num gcd=gcdExtended(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}
```
### pollard rho
```c++
//need: gcd、fastMulti、fastPower、millerRabin
inline num pollardRho(num n){
    if(millerRabin(n)){cout<<n<<" ";return n;}
    num p=n;
    while(p==n)p=[](int n){
   	    num c=rand()%(n-1)+1;
    	num k=2,x=1ll*rand()%n+1,y=x;
    	for(num i=2;;i++){
        	x=(fastMulti(x,x,n)+c)%n;
    		num d=gcd(x-y,n);
    		if(d!=1 && d!=n)return d;
    		if(y==x)return n;
    		if(i==k)k<<=1,y=x;
   		}
	}(p);
    return max(pollardRho(p),pollardRho(n/p));
}
```
### abs
```c++
inline num abs(num x){
      num y=x>>31;
      return (x+y)^y;
}
```
### fast multi
```c++
inline num fastMulti(num a,num b,num mod=0){
    num ans=0;
    while(b){
        if(b&1)ans=(mod)?(ans+a)%mod:ans+a;
      	a=(mod)?(a<<1)%mod:a<<1;
        b>>=1;
    }
    return ans;
}

/*

inline num mulmod(num x,num y,num mod){
    num ret = 0;
    __asm__("movq %1,%%rax\n imulq %2\n idivq %3\n":"=d"(ret):"m"(x),"m"(y),"m"(mod):"%rax");
    return ret;
}

*/
```
### gcd
```c++
inline num gcd(num a,num b){
    return a<0?gcd(-a,b):(!a?1:(!b?a:gcd(b,a%b)));
}// lcm=a*b/gcd(a,b)
```
### Miller Rabin
```c++
//need: fastMulti、fastPower
/*bool millerRabin(num n,int times=20){
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
}*/
bool miillerRabin(int n,int k=20){
	if(n<=1||n==4)return false;
	if(n<=3)return true;
	int d=n-1;
	while(d%2==0)d/=2;
	for(int i=0;i<k;i++)
		if(![](int d, int n){
        	int a=2+rand()%(n-4);
        	int x=fastPower(a,d,n);
        	if (x==1||x==n-1)return true;
        	while (d!=n-1){
        		x=(x*x)%n;
        		d*=2;
        		if(x==1)return false;
        		if(x==n-1)return true;
        	}
        	return false;
        }(d,n))return false;
	return true;
}
```
### max
```c++
inline num max(num x, num y){
    num t=(x-y)>>31;
    return y&(t)|x&~(t);
}
```
### mod inverse
```c++
//need: gcdExtended
num modInverse(num a,num m){
    num x,y;
    num g=gcdExtended(a,m,&x,&y);
    if(g!=1)return 0;
    else return (x%m+m)%m;
}
```
### chinese remainder
```c++
//need: gcdExtended
num chineseRemainder(num a[],num w[],int len){
	num d,x,y,m,n=1,ret=0;
	for(int i=0;i<len;i++)n*=w[i];
	for(int i=0;i<len;i++){
		m=n/w[i];
		d=gcdExtended(w[i],m,&x,&y);
		ret=(ret+y*m*a[i])%n;
	}
	return (n+ret%n)%n;
}
```
## DataStructure
### segment tree
```c++
template<class T>struct Node{
private:
public:
    int l_segment;
    int r_segment;
    Node<T> *l_son;
    Node<T> *r_son;
    T data;
    void set(int l,int r){l_segment=l,r_segment=r;}
};

template<class T>class SegmentTree{
private:
    Node<T> *root;
    vector<T> vec;
    function<T(T,T)>func;
    void build(Node<T> *now,int l,int r){
        now->set(l,r);
        if(l==r-1)now->data=vec[l];
        else{
            now->l_son=new Node<T>();
            now->r_son=new Node<T>();
            build(now->l_son,l,(l+r)/2);
            build(now->r_son,(l+r)/2,r);
            now->data=func(now->l_son->data,now->r_son->data);
        }
    }
    T query(Node<T> *now,int l,int r){
        if(now->l_segment==l && now->r_segment==r)return now->data;
        else{
            int mid=(now->l_segment+now->r_segment)/2;
            if(r<=mid)return query(now->l_son,l,r);
            else if(l>=mid)return query(now->r_son,l,r);
            else return func(query(now->l_son,l,mid),query(now->r_son,mid,r));
        }
    }
    void modify(Node<T> *now,int x,T value){
        if(now->l_segment==now->r_segment-1)now->data=value;
        else{
            int mid=(now->l_segment+now->r_segment)/2;
            if(x<mid)modify(now->l_son,x,value);
            else modify(now->r_son,x,value);
            now->data=func(now->l_son->data,now->r_son->data);
        }
    }
public:
    SegmentTree(vector<T>&_vec,function<T(T,T)>_func):vec(_vec),func(_func){
        root = new Node<T>();
        build(root,0,vec.size());
    }
    T query(int l,int r){return query(root,l,r);}
    void modify(int x,T value){modify(root,x,value);}
};
```
## ClassicProblem
### reFibonacci
```c++
int reFibonacci(int n){
    union{
        double d;
        long long lld;
    }log2={0x23C6EF372FE951P-52*n};
    int result=((log2.lld>>52)-0x3FF)/0xB1B9D68A8E5338P-56;
    double power=0x727C9716FFB764P-56;
    int i=(result+3)/4;
    switch(result%4){
        case 0:do{ power*=0x19E3779B97F4A8P-52;
        case 3:    power*=0x19E3779B97F4A8P-52;
        case 2:    power*=0x19E3779B97F4A8P-52;
        case 1:    power*=0x19E3779B97F4A8P-52;
        }while(--i>0);
    }
    int ans=power+0x1P-1<n?power*0x19E3779B97F4A8P-52+0x1P-1<n?result+2:result+1:result;
    return ans;
}
```
### 0-1Knapsack
```c++
int knapsack(vector<int>weight,vector<int>value,int n,int m){
    for(int i=0;i<n;i++){
	    for(int j=m;j>=0;j--){
            if(j-weight[i]>=0){
                dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
            }
        }
    }
    return dp[m];
}
```
### 麻將
```c++
#include <iostream>
#include <sstream>
using namespace std;
string list[]={
    "","1W","2W","3W","4W","5W","6W","7W","8W","9W",
    "","1B","2B","3B","4B","5B","6B","7B","8B","9B",
    "","1S","2S","3S","4S","5S","6S","7S","8S","9S",
    "","D","","X","","N","","B","","Z","","F","","B"
};
int tiles[44]={};
bool win(int x,int n){
    if(x==n)return true;
    if(!x){
        for(int i=0;i<44;i++){
            if(tiles[i]>=2){
                tiles[i]-=2;
                if(win(0,n))return true;
                tiles[i]+=2;
            }
        }
    }
    else for(int m=0;m<44;m++){
        if(tiles[m]>=3){
            tiles[m]-=3;
            if(win(x+1,n))return true;
            tiles[m]+=3;
        }
        else if(tiles[m] && tiles[m+1] && tiles[m+2]){
            tiles[m]--;
            tiles[m+1]--;
            tiles[m+2]--;
            if(win(x+1,n))return true;
            tiles[m]++;
            tiles[m+1]++;
            tiles[m+2]++;
        }
    }
    return false;
}
int main(){
    string x;
    getline(cin,x);
    stringstream ss;
    ss<<x;
    int n=0;
    while(ss>>x){
        for(int i=0;i<44;i++){
            if(x==list[i])tiles[i]++;
        }
        n++;
    }
    if(win((n+1)/3))cout<<"Win!"<<endl;
    else cout<<"Nope"<<endl;
    return 0;
}
```
### 工作排程
```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define endl '\n'
#define IO_optimization cin.tie(0),ios_base::sync_with_stdio(false)

void task();
int main(){
	IO_optimization;
	int t=0;
	cin>>t;
	while(t--)task();
	return 0;
}

struct Work{
	int time;
	int deadline;
	void input(){
		cin>>time>>deadline;
	}
	bool operator<(Work other)const{
		return deadline<other.deadline;
	}
};

vector<Work>works;

void task(){
	int n;
	cin>>n;
	works.resize(n);

	for(int i=0;i<n;i++){
		works[i].input();
	}
	sort(works.begin(),works.end());

	priority_queue<int>scheule;
	int now=0;
	for(int i=0;i<n;i++){
		scheule.push(works[i].time);
		now+=works[i].time;
		if(now>works[i].deadline){
			now-=scheule.top();
			scheule.pop();
		}
	}
	cout<<scheule.size()<<endl;
}
```
### popcount
```c++
num popCount(num n){
    num count=0;
    while(n){
        ++count;
        n&=n-1;
    }
    return count;
}
```

