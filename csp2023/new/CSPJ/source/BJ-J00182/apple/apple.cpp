#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
    long long n,d=0,t,jsq=0;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    t=n;
    while(t){
        long long c=1,w;
        for(long long i=1;i<=n;i++){
            if(!a[i]){
                w=i;
                break;
            }
        }
        if(w==n){
            d=jsq+1;
        }
        a[w]=1;
        t--;
        for(long long i=w;i<=n;i++){
            if(a[i]){
                continue;
            }
            if(c==3){
                a[i]=1;
                if(i==n){
                    d=jsq+1;
                }
                c=1;
                t--;
            }
            else{
                c++;
            }
        }
        jsq++;
    }
    cout<<jsq<<" "<<d<<endl;
    return 0;
}
