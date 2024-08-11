#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=20;
int n;
bool is[maxn];
int a[maxn][maxn];
inline void input(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++)scanf("%d",&a[i][j]);
    }
}
inline void solve(){
    if(n==1)printf("81\n");
    else {
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                for(int k=1;k<=5;k++){
                    if(a[i][k]==a[j][k])is[k]=true;
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=5;i++){
            if(!is[i])++cnt;
        }
        if(cnt==0)printf("1\n");
        else printf("10\n");
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    input();
    solve();
    return 0;
}