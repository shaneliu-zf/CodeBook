#include<Thread>
thread t([](int i){cout<<i<<endl;},1);
t.join();
