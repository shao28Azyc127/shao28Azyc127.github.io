#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
template<typename T>void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c-'0');
    x=x*f;
}

const int N=10;

int n,a[N][N];

int ans,cur[N];
bool check(int id){
    int s=0,p1=0,p2=0;
    for(int i=1;i<=5;i++)
        if(cur[i]!=a[id][i]){
            s++;
            if(!p1) p1=i;
            else p2=i;
        }
    if(s>2||s==0) return 0;
    else if(s==1) return 1;
    else{
        if(p2-p1!=1) return 0;
        else return (a[id][p2]-cur[p2]+10)%10==(a[id][p1]-cur[p1]+10)%10;
    }
}
void dfs(int s){
    if(s==6){
        bool flag=1;
        for(int i=1;i<=n;i++)
            flag&=check(i);
        if(flag) ans++;
        return ;
    }
    for(int i=0;i<=9;i++)
        cur[s]=i,dfs(s+1);
}

signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            read(a[i][j]);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}

// g++ 1.cpp -o 1 -O2 -std=c++14
