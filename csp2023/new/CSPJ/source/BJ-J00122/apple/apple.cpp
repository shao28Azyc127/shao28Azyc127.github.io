#include<iostream>
#include<cstdio>
using namespace std;
bool a[100000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,p=1,ans;
    cin>>n;
    if(n<=1000){
        p=0;
        int k=1;
        int cou;
        while(p<n){
            cou=2;
            for(int i=0;i<n;i++){
                if(a[i]!=1){
                    if(cou==2){
                        if(i==n-1) ans=k;
                        a[i]=1;
                        cou=0;
                        p++;
                        if(p==n) break;
                    }
                    else cou++;
                }
            }
            k++;
        }
        cout<<k-1<<' '<<ans;
    }
    else{
        int o=n-1;
        while(o>=p){
            o-=p;
            p++;
        }
        cout<<p<<' '<<1;
    }
    return 0;
}
