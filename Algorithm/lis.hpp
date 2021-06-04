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
