#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int ans = 999999999;
int opt[100005][4];
int sta[100005];
int tp[15];
char v;
int x,y;
int vis[100005];
int ck[100005];
int whose[100005];
int sum = 0;
int check()
{
    for(int k = 1; k <= n; k++){tp[k]=sta[k];}

    for(int j = 1; j <= m; j++){
            if(opt[j][1]==1){tp[opt[j][2]] = 1;}
            if(opt[j][1]==2){tp[opt[j][2]] = 2;}
            if(opt[j][1]==3){tp[opt[j][2]] = 3;}
            if(opt[j][1]==4){tp[opt[j][2]] = tp[opt[j][3]]; }
            if(opt[j][1]==5){if(opt[j][3]==3)tp[opt[j][2]] = 3;
            else tp[opt[j][2]] = 3-tp[opt[j][3]];
            }
    }
    for(int i = 1; i <= n; i++){
        if(tp[i]!=sta[i])return 0;
    }

    return 1;
}
void dfs(int t,int temp)
{
    if(t==n){if(check())ans = min(ans,temp);return;}
    for(int k = 1; k <= 3; k++){
        if(k==3){
            sta[t+1] = 3;dfs(t+1,temp+1);

        }
        else {
            sta[t+1] = k;
            dfs(t+1,temp);
        }
    }
    return;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    for(int i = 1; i <= t; i++){
        cin>>n>>m;
        memset(opt,0,sizeof(opt));
        memset(sta,0,sizeof(sta));
        memset(tp,0,sizeof(tp));
        memset(vis,0,sizeof(vis));
        memset(whose,0,sizeof(whose));
        memset(ck,0,sizeof(ck));
        for(int j = 1; j <= m; j++){
            cin>>v;
            if(v=='T'){scanf("%d",&x);opt[j][1] = 1;opt[j][2] = x;}
            if(v=='F'){scanf("%d",&x);opt[j][1] = 2;opt[j][2] = x;}
            if(v=='U'){scanf("%d",&x);opt[j][1] = 3;opt[j][2] = x;}
            if(v=='+'){scanf("%d %d",&x,&y);opt[j][1] = 4;opt[j][2] = x;opt[j][3] = y;}
            if(v=='-'){scanf("%d %d",&x,&y);opt[j][1] = 5;opt[j][2] = x;opt[j][3] = y;}
        }

        if(c==1||c==2){
            ans = n;
            dfs(0,0);
            printf("%d\n",ans);
        }
        if(c==3||c==4){
                sum = 0;
            for(int k = m; k >= 1; k--){
                if(opt[k][1]==3&&!vis[opt[k][2]]){
                    sum++;
                    vis[opt[k][2]] = 1;
                }
            }
            printf("%d\n",sum);
        }

        if(c==5||c==6){
            sum = 0;
            for(int k = 1; k <= n; k++)whose[k] = k;
            for(int j = 1; j <= m; j++){
                if(opt[j][1]==3){ck[opt[j][2]] = 1;}
                if(opt[j][1]==4){whose[opt[j][2]] = whose[opt[j][3]]; }
            }
            for(int k = 1; k <= n; k++){
                if(ck[whose[k]])sum++;
            }
            printf("%d\n",sum);

        }


    }
    return 0;
}
