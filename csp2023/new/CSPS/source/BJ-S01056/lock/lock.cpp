#include<bits/stdc++.h>

using namespace std;

const int N=10;
typedef long long LL;

int n;
LL ans;
map<string,int> mp;
string a[N];

char get(char c,int p){
    int f=c-'0';
    f+=p;
    f%=10;
    return f+'0';
}

void work(int x){
    for(int i=1;i<=5;++i){
        for(int p='0';p<='9';++p){
            if(p==a[x][i]) continue;
            string g=a[x];
            g[i]=p;
            mp[g]++;
            if(mp[g]==n) ans++;
        }
    }
    for(int i=1;i<5;++i){
        for(int p=1;p<=9;++p){
            string g=a[x];
            g[i]=get(g[i],p);
            g[i+1]=get(g[i+1],p);
            mp[g]++;
            if(mp[g]==n) ans++;
        }
    }
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        a[i]='%';
        for(int j=1,c;j<=5;++j){
            scanf("%d",&c);
            a[i]+=char(c+'0');
        }
    }
    for(int i=1;i<=n;++i){
        work(i);
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}