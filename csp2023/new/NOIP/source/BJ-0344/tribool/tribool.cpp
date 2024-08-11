#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int ans;
vector<int> g[100002];
int ru[100002];
void topo(){
    queue<int> q;
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(ru[i]==0){
            q.push(n);
            cnt++;
        }
    }
    while(!q.empty()){
        int p=q.front();
        for(int i=0;i<g[p].size();++i){
            ru[g[p][i]]--;
            if(ru[g[p][i]]==0){
                q.push(g[p][i]);
                cnt++;
            }
        }
        q.pop();

    }
    ans=n-cnt;
    return ;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    char type;
    int a,b;
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i){
            type=getchar();
            while(type!='+'&&type!='-') type=getchar();
            scanf("%d%d",&a,&b);
            if(type=='-'){
                g[a].push_back(b);
                ru[b]++;
            }
            else if(type=='+'){
                g[b].push_back(a);
                ru[a]++;
            }
        }
        topo();
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
