#include<bits/stdc++.h>
using namespace std;
int n,a[6],b,s,v[99999];
int p(int a){
    int s=1;
    for(int i=1;i<=a;++i){
        s*=10;
    }
    return s;
}
void f(){
    for(int i=1;i<=5;++i){
        for(int j=1;j<=9;++j){
            int x=(a[i]+j)%10;
            ++v[b-(a[i]*p(5-i))+(x*p(5-i))];
            if(i==5) continue;
            int x1=(a[i]+j)%10;
            int x2=(a[i+1]+j)%10;
            ++v[b-(a[i]*p(5-i))+(x1*p(5-i))  -(a[i+1]*p(4-i))+(x2*p(4-i))];
        }
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
        b=a[1]*10000+a[2]*1000+a[3]*100+a[4]*10+a[5];
        f();
    }
    for(int i=1;i<=99999;++i){
        if(v[i]==n) ++s;
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
