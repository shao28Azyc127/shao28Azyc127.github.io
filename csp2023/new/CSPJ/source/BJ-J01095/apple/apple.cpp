#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,m=1;
    scanf("%ld",&n);
    long long s[1000009]={};
    for(long long i=1;i<=n;i++){
        if(s[i]==0){
            s[i]=m;
            int c1=3;
            for(long long j=i;j<=n;j++){
                if(s[j]==0){
                    c1--;
                    if(c1==0){
                        s[j]=m;
                        c1=3;
                    }
                }
            }
            m++;
        }
    }
    cout<<m-1<<" "<<s[n];
}
