#include <bits/stdc++.h>

using namespace std;

struct node{
    int from,to,b;
};

int n,k;
vector<node> v[10005];
int ans=-1;
struct state{
    int now,step,last;
};
queue<state> q;
/*
void dfs(int now,int step,int last){
    if(now==n){
        last=(last/k+(last%k!=0))*k;
        if(step%k==0){
            if(ans==-1){
                ans=last+step;
            }
            else{
                ans=min(last+step,ans);
            }
        }
        return;
    }
    if(ans!=-1&&last>=ans){
        return ;
    }
    for(int i=0;i<v[now].size();i++){
        node x=v[now][i];
        dfs(x.to,step+1,max(last,x.b-step));
    }
}
*/
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int m;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
        node x;
        cin>>x.from>>x.to>>x.b;
        v[x.from].push_back(x);
	}
	state f;
	f.now=1;
	f.last=f.step=0;
    q.push(f);
    while(!q.empty()){
        f=q.front();
        q.pop();
        if(f.now==n){
            f.last=(f.last/k+(f.last%k!=0))*k;
            if(f.step%k==0){
                if(ans==-1){
                    ans=f.last+f.step;
                }
                else{
                    ans=min(f.last+f.step,ans);
                }
            }
            continue;
        }
        if(ans!=-1&&f.last+f.step>=ans){
            continue;
        }
        for(int i=0;i<v[f.now].size();i++){
            node x=v[f.now][i];
            state n;
            n.now=x.to;
            n.step=f.step+1;
            n.last=max(f.last,x.b-f.step);
            q.push(n);
        }
    }
	cout<<ans<<endl;
	return 0;
}
