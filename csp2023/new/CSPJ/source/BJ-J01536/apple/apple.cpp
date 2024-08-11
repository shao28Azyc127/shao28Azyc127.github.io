#include<bits/stdc++.h>
using namespace std;
long long n,a[100000005]={};
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    long long k=1,m=n,s=0,t=1000000005;
    while(m>0){
        for(long long i=1;i<=n;i++){
            if(a[i]==0 and k==1){
                a[i]=1;
                k+=1;
                m-=1;
            }
            else if(a[i]==0)k+=1;
            if(k==4)k=1;
        }
        s+=1;
        if(a[n]==1){
            if(s<t)t=s;
        }
        k=1;
    }
    cout << s << " " << t;
    return 0;
}
