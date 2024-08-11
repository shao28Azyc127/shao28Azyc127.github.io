#include<bits/stdc++.h>
#ifdef BJC
#define dlog(...) fprintf(stderr,__VA_ARGS__)
#else
#define dlog(...) (void)0
#endif
typedef int int32;
#define int long long
using namespace std;
int f1(int n){
    int i=0;
    while(n>0){
        i++;
        n-=n/3+(n%3==0?0:1);
    }
    return i;
}
int f2(int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    int i=0,m=n;
    while(q.size()){
        i++;
        dlog("part:%lld\n",i);
        for(int j=0;j<n;j++){
            if(j%3==0){
                if(q.front()==n){
                    return i;
                }
                m--;
                q.pop();
            }else{
                q.push(q.front());
                q.pop();
            }
            dlog("%lld ",q.front());
        }
    }
    return 0;
}
int32 main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    cout<<f1(n)<<" "<<f2(n)<<endl;
    return 0;
}