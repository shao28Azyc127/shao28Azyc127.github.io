#include<bits/stdc++.h>
using namespace std;
int n,lzp;
bool b[1000001];
int solve(){
    for(int i=1;i<=lzp;i++){
        int s=0;
        for(int j=1;j<=n;j++){
            if(b[j]==1)continue;
            else{
                if(s%3==0){
                    b[j]=1;
                    if(j==n)return i;
                }
            }
            ++s;
        }
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    int lzc=n;
    while(lzc){
        ++lzp;
        if(lzc%3!=0)lzc-=lzc/3+1;
        else lzc-=lzc/3;
    }
    if(n%3==1)printf("%d 1",lzp);
    else printf("%d %d",lzp,solve());
    return 0;
}

