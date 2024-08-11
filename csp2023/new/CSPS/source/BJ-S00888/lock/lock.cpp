#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10;
int n,d[N][N],tmp[N];
int f(int x,int y){
    if(x<y) return y-x;
    else return y+10-x;
}
bool fcheck(int id){
    int dif=0;
    //cerr<<"begin"<<endl;
    //for(int i=1;i<=5;i++) cerr<<tmp[i]<<" ";cerr<<endl;
    //for(int i=1;i<=5;i++) cerr<<d[id][i]<<" ";cerr<<endl;
    for(int i=1;i<=5;i++){
        if(tmp[i]!=d[id][i]) dif++;
    }
    //cerr<<dif<<endl;
    if(dif==0||dif>=3) return false;
    if(dif==1){
        for(int i=1;i<=5;i++){
            if(tmp[i]!=d[id][i]){
                if(f(tmp[i],d[id][i])!=0) return true;
                else return false;
            }
        }
    }
    for(int i=1;i<=4;i++){
        if(tmp[i]==d[id][i]||tmp[i+1]==d[id][i+1]) continue;
        if(f(tmp[i],d[id][i])==f(tmp[i+1],d[id][i+1])) return true;
    }
    return false;
}
bool check(){
    for(int i=2;i<=n;i++) if(!fcheck(i)) return false;
    return true;
}
void up(int& x){
    if(x!=9) x++;
    else x=0;
}
void down(int& x){
    if(x) x--;
    else x=9;
}
int solve(){
    int ans=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++) tmp[j]=d[1][j];
        for(int j=1;j<=9;j++){
            up(tmp[i]);
            ans+=check();
            //cerr<<ans<<endl;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=5;j++) tmp[j]=d[1][j];
        for(int j=1;j<=9;j++){
            up(tmp[i]);up(tmp[i+1]);
            ans+=check();
            //cerr<<ans<<endl;
        }
    }
    return ans;
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++) scanf("%lld",&d[i][j]);
    }
    printf("%lld\n",solve());
}
