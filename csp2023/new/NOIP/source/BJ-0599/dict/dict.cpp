#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,n,cnt[3005][30],xx[3005][30],dd[3006][30],mn[10000],cmn[10000],ns[10000],nt[10000],nc;
char c[3005];
bool ch(){
    for(int i=1;i<=m;i++){
        if(ns[i]<nt[i]) return 0;
        else return 1;
    }
    return 0;

}
signed main(){
       freopen("dict.in","r",stdin);
        freopen("dict.out","w",stdout);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            cin>>c;
            for(int j=1;j<=m;j++)   ++cnt[i][c[j-1]-'a'+1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=26;j++)  xx[i][j-1]=xx[i][j-1]+cnt[i][j];
            for(int j=26;j>=1;j--)  dd[i][j+1]=dd[i][j+1]+cnt[i][j];
        }
        mn[26]=m;
        cmn[26]=m;
        for(int i=1;i<=n;i++){
            bool flag=0;
            for(int j=26;j>=1;j--){
               if(dd[i][j]<mn[j]){
                    flag=1;break;
                }
                if(dd[i][j]>mn[j]){
                    flag=0;break;
                }
            }
            if(flag)    for(int j=26;j>=1;j--)  mn[j]=dd[i][j];
        }

        int cnt1=0;
        for(int i=26;i>=1;i--)   for(int j=1;j<=mn[i]-mn[i+1];j++)   nt[++cnt1]=i;
        for(int i=1;i<=n;i++){
            int nc=0;for(int j=1;j<=26;j++) for(int p=1;p<=xx[i][j]-xx[i][j-1];p++) ns[++nc]=j;
            if(ch[i])   cout<<"1";
            else cout<<"0";
        }
        cout<<endl;
}
