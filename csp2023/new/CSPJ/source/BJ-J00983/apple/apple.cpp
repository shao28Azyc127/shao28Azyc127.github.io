 #include <bits/stdc++.h>
using namespace std;
bool vis[10000005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    scanf("%d",&n);
    int d=0,cnt=0;
    int x=0;
    while(cnt<n){
        d++;
        int i=1;
        while(i<=n){
            while(vis[i]){i++;if(i>n)break;}
            if(i<=n)vis[i]=1;
            else break;
            if(i==n)x=d;
            i++;
            cnt++;
            if(i>n)break;
            while(vis[i]){i++;if(i>n)break;}
            i++;
            while(vis[i]){i++;if(i>n)break;}
            i++;
        }
    }printf("%d %d",d,x);
    return 0;
}
