#include <bits/stdc++.h>

using namespace std;
int n,res=0,cnt=0;
bool a[10000000];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int tg=0;
    int p=0;
    while(cnt<n){
        tg=2;
        res++;
        for(int i=1;i<=n;i++){
            if(a[i]==1) continue;
            if(a[i]==0&&tg==2){
                if(i==n)    p=res;
                a[i]=1;
                tg=0;
                cnt++;
                continue;
            }
            if(a[i]==0&&tg!=2)  tg++;
        }
    }
    cout<<res<<endl<<p;
    return 0;
}

