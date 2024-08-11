#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,m,k,d;
struct node{
    int x,y,z;
}a[100001];
bool cmp(node xx,node yy){
    return (xx.z-abs(xx.y*d))>(xx.z-abs(yy.y*d));
}
bool vis[10000001];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin >>c >>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        int x,y,z;
        cin >>n >>m >>k >>d;
        int cnt=0;
        while(m--){
            cin >>x >>y >>z;
            if(x<=n && y<=k && abs(y*d)<z){
                cnt++;
                a[cnt].x=x;
                a[cnt].y=y;
                a[cnt].z=z;
            }
        }
        sort(a+1,a+1+cnt,cmp);
        long long ans=0;
        int ww=0;
        //cout <<"!";
        for(int i=1;i<=cnt;i++){
            bool flag=0;
            int kop=0;
            int l=a[i].y;
            for(int j=a[i].x;j>=a[i].x-a[i].y+1;j--){
                if(!vis[j]) ww++;
                else kop++;
            }
            int now=a[i].x+1;
            while(now<=n && vis[now]==1){
                l++;
                now++;
                if(l>k) break;
            }
            now=a[i].x-y;
            while(now>=1 && vis[now]==1){
                l++;
                now--;
                if(l>k) break;
            }
            if(l>k) flag=0;
            else flag=1;
            if(flag==1){
                ans+=a[i].z;
                ans-=(a[i].y-kop)*d;
                for(int j=a[i].x;j>=a[i].x-a[i].y+1;j--){
                    vis[j]=1;
                }
            }

        }
        cout <<ans <<'\n';
    }
    return 0;
}
