//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node{
    int x;
    int y;
    int v;
};

char s[100005];
int ans=INT_MIN;
int k;
int n;
int m;
int d;
node chal[100005];

int checkchal(int combo,int day){
    for(int i=1;i<=m;i++){
        if(chal[i].x==day && chal[i].y<=combo){
            return chal[i].v;
        }

        if(chal[i].x>day){
            return 0;
        }
    }

    return 0;
}

void dfs(int combo,int nowener,int nowday){
    //cout<<combo<<" "<<nowener<<" "<<nowday<<endl;
    if(nowday==n+1){
        ans=max(ans,nowener);
        return;
    }

    if(combo==k){
        dfs(0,nowener+checkchal(0,nowday),nowday+1);
    }
    else{
        dfs(combo+1,nowener+checkchal(combo+1,nowday)-d,nowday+1);
        dfs(0,nowener+checkchal(0,nowday),nowday+1);
    }
}

signed main(){
    ios::sync_with_stdio(false);

    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);

    int c; cin>>c;
    int t; cin>>t;

    while(t--){
        memset(chal,0,sizeof chal);
        cin>>n;
        cin>>m;
        cin>>k;
        cin>>d;

        for(int i=1;i<=m;i++){
            cin>>chal[i].x>>chal[i].y>>chal[i].v;
        }

        dfs(0,0,1);

        cout<<ans<<endl;
    }
    return 0;
}
