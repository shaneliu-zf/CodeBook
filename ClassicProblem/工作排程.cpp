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
