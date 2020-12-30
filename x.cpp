
#include<iostream>
#include<sstream>
using namespace std;

int a[500005]={};
int b[500005]={};

void change(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int temp;
    for(int i=0;i<n;i++){
        temp=a[b[i]];
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int t;
    cin>>t;
    while(t--){
        change();
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" \n"[i==n-1];
    }
    return 0;
}
/*

5
2 5 1 3 4
1
5 1 3 4 5 2

*/
