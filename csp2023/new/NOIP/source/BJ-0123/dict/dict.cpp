#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int mx[3010],mn[3010];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        mx[i]=0,mn[i]=25;
        for(int j=1;j<=m;j++){
            char c=getchar();
            while(c<'a'||c>'z') c=getchar();
            int ch=c-'a';
            mx[i]=max(mx[i],ch),mn[i]=min(mn[i],ch);
        }
    }
    for(int i=1;i<=n;i++){
        int ck=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(mx[j]<=mn[i]){ck=0;break;}
        }
        putchar(ck+'0');
    }
    return 0;
}
