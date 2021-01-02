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
