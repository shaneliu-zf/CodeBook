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
