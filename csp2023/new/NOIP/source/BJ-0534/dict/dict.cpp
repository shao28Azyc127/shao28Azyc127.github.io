#include <bits/stdc++.h>
using namespace std;
int acc[3100];
struct word
{
    int id;
    int c[26];
}sx[3100],nx[3100];
bool cmpsx(word a,word b)
{
    for (int i=0;i<26;i++){
        if (a.c[i]==b.c[i]) continue;
        else return a.c[i]>b.c[i];
    }
}
bool cmpnx(word a,word b)
{
    for (int i=25;i>=0;i--){
        if (a.c[i]==b.c[i]) continue;
        else return a.c[i]<b.c[i];
    }
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if (n==1) {
        cout<<1;
        return 0;
    }
    for (int i=1;i<=n;i++){
        sx[i].id=nx[i].id=i;
        for (int j=1;j<=m;j++){
            char x;
            cin>>x;
            sx[i].c[x-'a']++;
            nx[i].c[x-'a']++;
        }
    }
    sort(sx+1,sx+n+1,cmpsx);
    sort(nx+1,nx+n+1,cmpnx);
    /*
    for (int i=1;i<=n;i++) cout<<sx[i].id<<" ";
    cout<<'\n';
    for (int i=1;i<=n;i++) cout<<nx[i].id<<" ";
    cout<<'\n';
    */
    int nxc,nxa;
    for (int j=25;j>=0;j--){
        if (nx[1].c[j]!=0) {
            nxc=j;
            nxa=nx[1].c[j];
            break;
        }
    }
    for (int i=n;i>=1;i--){
        if (sx[i].id==nx[1].id) break;
        int sxc,sxa;
        for (int j=0;j<26;j++){
            if (sx[i].c[j]!=0) {
                sxc=j;
                sxa=sx[i].c[j];
                break;
            }
        }
        if (sxc<nxc) break;
        else{
            acc[sx[i].id]=-1;
        }
    }
    for (int i=1;i<=n;i++){
        if (acc[i]==0) cout<<1;
        else cout<<0;
    }
    return 0;
}
