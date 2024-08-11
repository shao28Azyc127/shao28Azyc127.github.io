#include<bits/stdc++.h>
using namespace std;
int a[2000006];
int n;
int lst[2000006][30];
long long f[2000006];
long long ans=0;
int main(){
    memset(lst,0,sizeof(lst));
    memset(f,0,sizeof(f));
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        a[i]=x-'a'+1;
    }
    a[0]=0;
    for(int i=2;i<=n;i++){
        int l=0;
        if(a[i]==a[i-1]){
            lst[i][a[i-2]]=i-1;
            l=i-1;
        }
        lst[i][a[lst[i-1][a[i]]-2]]=max(lst[i][a[lst[i-1][a[i]]-2]],lst[i-1][a[i]]-1);
        l=max(l,lst[i-1][a[i]]-1);
        for(int j=0;j<=26;j++){
            lst[i][j]=max(lst[i][j],lst[l-1][j]);
        }
    }
    for(int i=1;i<=n;i++){
            int l=0;
        for(int j=0;j<=26;j++){
            l=max(l,lst[i][j]);
        }
        if(l)f[i]=f[l-1]+1;
        ans+=f[i];
//        cout<<l<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
