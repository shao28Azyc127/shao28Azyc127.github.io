#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long a;
    cin>>a;
    long long c[a+1]={0},e=0,f=0,b,d;
    while(true){
        b=2;
        d=0;
        f++;
        for(long long i=1;i<=a;i++){
            if(c[i]==0&&b==2){
                c[i]=1;
                b=0;
                d++;
            }else if(c[i]==0){
                b++;
                d++;
            }if(i==a&&c[i]==1&&e==0){
                e=f;

            }
        }if(d==0){
            break;
        }

    }
    cout<<f-1<<' '<<e;

    return 0;
}
