vector<int> LIS(vector<int>& s){
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
