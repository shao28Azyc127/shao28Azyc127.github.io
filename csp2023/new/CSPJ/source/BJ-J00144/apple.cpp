#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in",r,stdin);
    freopen("apple.out",r,stdout);
    long long a;
    cin>>a;
    if((a-1)%3==0){
        int n=0,q=a;
        while(q>=0){
            for(int i=2;i>=0;i--){
                if((n-i-1)%3==0){
                    q-=(i+1);
                    break;
                }
                n++;

            }
        }
        cout<<n<<' '<<1;
    }
    else{
        long long n=0,q=a;
        while(q>=0){
            for(int i=2;i>=0;i--){
                if((n-i-1)%3==0){
                    q-=(i+1);
                    break;
                }
                n++;

            }
        }
        long long f[a]={0};
        int x=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<a;j++){
                if(f[j]==0)x++;
                if(x==3){
                    f[j]=i;
                    x=0;
                }
            }
        }
        cout<<n<<' '<<f[a];
    }
}