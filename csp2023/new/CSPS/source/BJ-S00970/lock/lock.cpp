#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <ctime>
using namespace std;
#define ll long long
ll read(){
    ll x=0,k=1;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';x=(x<<1)+(x<<3)+c-'0',c=getchar());
    return x*k;
}
int a[20][10],a0[20],pw[10]={1,10,100,1000,10000,100000,1000000};
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++) a[i][j]=read(),a0[i]+=a[i][j]*pw[j];
    }
    vector<int> vec;
    for(int i=0;i<5;i++){
        for(int d=1;d<10;d++) {
            vec.push_back(a0[1]-a[1][i]*pw[i]+(a[1][i]+d)%10*pw[i]);
        }
    }
    for(int i=0;i+1<5;i++){
        for(int d=1;d<10;d++){
            vec.push_back(a0[1]-a[1][i]*pw[i]-a[1][i+1]*pw[i+1]+(a[1][i]+d)%10*pw[i]+(a[1][i+1]+d)%10*pw[i+1]);
        }
    }
    // cout<<vec.size()<<endl;
    int ans=0;
    for(int now=0;now<vec.size();now++){
        int u=vec[now],ck=1;
        for(int i=1;i<=n;i++){
            vector<int> dif;
            for(int j=0;j<5;j++){
                if(u/pw[j]%10!=a[i][j]) dif.push_back(j);
            }
            if(dif.size()>2||!dif.size()){
                ck=0;
                break;
            }
            if(dif.size()<2) continue;
            int j1=dif[0],j2=dif[1];
            if((u/pw[j1]%10-a[i][j1]+10)%10!=(u/pw[j2]%10-a[i][j2]+10)%10||j2!=j1+1){
                ck=0;
                break;
            }
        }
        ans+=ck;
        // if(ck) cout<<u<<endl;
    }
    cout<<ans;
    return 0;
}