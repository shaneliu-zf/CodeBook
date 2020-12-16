int LIS(vector<double>& s){
    if(s.empty())return 0;
    vector<double>v;
    v.push_back(s[0]);
    for (int i=1;i<s.size();i++){
        double n=s[i];
        if(n>v.back())
            v.push_back(n);
        else{
            *lower_bound(v.begin(),v.end(),n)=n;
        }
    }
    return v.size();
}
