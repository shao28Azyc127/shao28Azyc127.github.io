#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int u[3005][27],n,m,ans[3005],mmin[3005],mmax[3005];
char a[3005];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        mmin[i]=30;
        char c;
        scanf("%c",&c);
        for(int j=1;j<=m;j++){
            scanf("%c",&a[j]);
            u[i][a[j]-'a'+1]++;
            mmin[i]=min(mmin[i],a[j]-'a'+1);
            mmax[i]=max(mmax[i],a[j]-'a'+1);
        }
    }
    for(int i=1;i<=n;i++){
        ans[i]=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(mmin[i]>=mmax[j]){
                ans[i]=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i];
    }
    return 0;
}
