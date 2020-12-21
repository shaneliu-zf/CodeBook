double simulatedAnnealing(){
    double ans=0;
    auto func=[](double x){return x;};
    double T=3000;
    double T_min=1e-12;
    double r=0.996;
    while(T>T_min){
        double next=now+(rand()*2-RAND_MAX)*T;
        double delta=func(now)-func(next);
        if(delta<0)now=next;
        else{
            if((-delta/T)*RAND_MAX>rand())now=next;
        }
        if(func(now)>ans)ans=func(now);
        T*=r;
    }
    return ans;
}
