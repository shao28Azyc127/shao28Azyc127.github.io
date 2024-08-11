#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[100005][3];

struct node{
    int now,str;
}vis[100005][3];
struct node2{
    int x,y,z;
}t[100005];

void init(){
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    for(int i=1;i<=100005;i++){
        vis[i][0].now=vis[i][0].str=vis[i][1].now=vis[i][1].str=0;
        t[i].x=t[i].y=t[i].z=0;
    }
}

bool cmp(node2 a,node2 b){
    return a.x<b.x;
}

signed main(){
    freopen("run2.in","r",stdin);
    freopen("run2.out","w",stdout);
    int c,g;
    cin>>c>>g;
    while(g--){
        int n,m,k,d;
        init();
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            cin>>t[i].x>>t[i].y>>t[i].z;
        }
        sort(t+1,t+m+1,cmp);
        dp[1][0]=0;
        dp[1][1]=0-(d*t[1].y)+t[1].z;
        vis[1][1].now=t[1].x;
        vis[1][1].str=t[1].y;
        for(int i=2;i<=m;i++){
            int num1=0,num0=0;
            bool flag1=0,flag2=0;
            if(dp[i-1][0]<dp[i-1][1]){
                dp[i][0]=dp[i-1][1];
                vis[i][0].now=vis[i-1][1].now;
                vis[i][0].str=vis[i-1][1].str;
            }
            else{
                dp[i][0]=dp[i-1][0];
                vis[i][0].now=vis[i-1][0].now;
                vis[i][0].str=vis[i-1][0].str;
            }
            if(t[i].y>k) num1=-0x3f3f3f3f;
            else if(t[i].x-vis[i-1][1].now>t[i].y){
                num1=dp[i-1][1]-d*t[i].y+t[i].z;
            }
            else{
                flag1=1;
                if(vis[i-1][1].str+t[i].x-vis[i-1][1].now>k) num1=-0x3f3f3f3f;
                else num1=dp[i-1][1]-d*(t[i].x-vis[i-1][1].now)+t[i].z;
            }
            if(t[i].y>k) num0=-0x3f3f3f3f;
            else if(t[i].x-vis[i-1][0].now>t[i].y){
                num0=dp[i-1][0]-d*t[i].y+t[i].z;
            }
            else{
                flag2=1;
                if(vis[i-1][0].str+t[i].x-vis[i-1][0].now>k) num0=-0x3f3f3f3f;
                else num0=dp[i-1][0]-d*(t[i].x-vis[i-1][0].now)+t[i].z;
            }
            if(num0==num1==-0x3f3f3f3f){
                continue;
            }
            if(num1>num0){
                dp[i][1]=num1;
                if(flag1==0){
                    vis[i][1].now=t[i].x;
                    vis[i][1].str=t[i].y;
                }
                else{
                    vis[i][1].now=t[i].x;
                    vis[i][1].str=t[i].x-vis[i-1][1].now+vis[i-1][1].str;
                }
            }
            else if(num1==num0){
                dp[i][1]=num1;
                vis[i][1].now=t[i].x;
                int s1=0x3f3f3f3f,s2=0x3f3f3f3f;
                if(flag1==0)s1=t[i].y;
                else s1=t[i].x-vis[i-1][1].now+vis[i-1][1].str;
                if(flag2==0)s2=t[i].y;
                else s2=t[i].x-vis[i-1][0].now+vis[i-1][0].str;
                vis[i][1].str=min(s1,s2);
            }
            else{
                dp[i][1]=num0;
                if(flag2==0){
                    vis[i][1].now=t[i].x;
                    vis[i][1].str=t[i].y;
                }
                else{
                    vis[i][1].now=t[i].x;
                    vis[i][1].str=t[i].x-vis[i-1][0].now+vis[i-1][0].str;
                }
            }
        }
        cout<<max(dp[m][0],dp[m][1])<<endl;
    }
    return 0;
}
