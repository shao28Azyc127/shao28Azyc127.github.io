#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
int cnt;
const int n=5;
map<int,int> mp;
int ans=0;
int mark[maxn];

int jw(int x,int j){
    if (x+j>=10) return x+j-10;
    return x+j;
}

int tw(int x,int j){
    if (x-j<0) return 10+(x-j);
    return x-j;
}

bool check(){
    int pp=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<10;j++){
            mark[i]=jw(mark[i],j);
            int num=0;
            for (int k=1;k<=n;k++) num=num*10+mark[k];
            if (mp[num]==1) pp++;
            mark[i]=tw(mark[i],j);
        }
    }

    for (int i=1;i<n;i++){
        for (int j=1;j<10;j++){
            mark[i]=jw(mark[i],j); mark[i+1]=jw(mark[i+1],j);
            int num=0;
            for (int k=1;k<=n;k++) num=num*10+mark[k];
            if (mp[num]==1) pp++;
            mark[i]=tw(mark[i],j); mark[i+1]=tw(mark[i+1],j);
        }
    }
    return pp==cnt;
}

void dfs(int dep){
    if (dep==n+1){
        if (check()) ans++;
        return;
    }

    for (int i=0;i<=9;i++){
        mark[dep]=i;
        dfs(dep+1);
    }
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&cnt);
    for (int i=1;i<=cnt;i++){
        int num=0;
        for (int j=1;j<=5;j++){
            int x;
            scanf("%d",&x);
            num=num*10+x;
        }
        mp[num]=1;
    }

    dfs(1);
    printf("%d",ans);
    return 0;
}