#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10;
// 45 36
ll n,ans,a[N][N],cnt[100];
vector <string> g;
string r,s,t;
void add(string r){
    ll k=lower_bound(g.begin(),g.end(),r)-g.begin();
    if(g[k]==r)cnt[k]++;
    return ;
}
void tell(){
    for(int i=0;i<g.size();i++)cout<<g[i]<<endl;
    return ;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    for(int i=0;i<100;i++){
        cnt[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%lld",&a[i][j]);
        }
        if(i==1){
            s=' ';
            for(int j=1;j<=5;j++)s+=(char)(a[1][j]+'0');
            for(int j=1;j<=5;j++){
                r=s;
                for(int k=1;k<10;k++){
                    r[j]++;
                    if(r[j]>'9')r[j]='0';
                    g.push_back(r);
                }
            }
            for(int j=1;j<5;j++){
                r=s;
                for(int k=1;k<10;k++){
                    r[j]++;
                    r[j+1]++;
                    if(r[j]>'9')r[j]='0';
                    if(r[j+1]>'9')r[j+1]='0';
                    g.push_back(r);
                }
            }
            sort(g.begin(),g.end());
        }else{
            s=' ';
            for(int j=1;j<=5;j++)s+=(char)(a[i][j]+'0');
            for(int j=1;j<=5;j++){
                r=s;
                for(int k=1;k<10;k++){
                    r[j]++;
                    if(r[j]>'9')r[j]='0';
                    add(r);
                }
            }
            for(int j=1;j<5;j++){
                r=s;
                for(int k=1;k<10;k++){
                    r[j]++;
                    r[j+1]++;
                    if(r[j]>'9')r[j]='0';
                    if(r[j+1]>'9')r[j+1]='0';
                    add(r);
                }
            }
        }
    }
    //tell();
    for(int i=0;i<g.size();i++){
        if(cnt[i]==n)ans++;
    }
    printf("%lld",ans);
    return 0;
}
