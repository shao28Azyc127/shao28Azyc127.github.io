#include<bits/stdc++.h>
using namespace std;
const int m=100000009;
int n,d=1,apple[m],i,j,l,f=0,b,k,a;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    for(i=0;i<m;i++){
        apple[i]=0;
    }
    cin>>n;
    for(i=1;i<=n;i++){
        apple[i]=i;
        f++;
    }
    for(i=1;i<=n-3;i++){
        if(f==0)break;

        if(apple[i]==0)continue;
        else{
            if(apple[i]==1){
                if(i==n) l=d;
                apple[i]--;
                f--;
                a=i;
                for(k=i+1;k<=n;k++){
                    b=0;
                    if(k==a){
                    for(j=k;j<=n;j++){
                        if(apple[j]==1){
                            b++;
                            if(b==3) {
                                f--;
                                if(j==n) l=d;
                                apple[j]--;
                                a=j;
                            }
                        }
                    }
                    }
                }
            }
        }
        d++;
    }
    cout<<d<<' '<<l;
    return 0;
}