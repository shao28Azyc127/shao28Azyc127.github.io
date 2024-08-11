#include<bits/stdc++.h>
using namespace std;
struct state{
    int st;
    int pos;
};
vector<int> e[100007];
int n,m,k;
queue<int> q;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,a;
        cin>>u>>v>>a;
        e[u].push_back(v);
    }
    state fir={0,1};
    q.push(fir);
    while(!q.empty()){
        state f=q.front();
        q.pop();
        int cur=f.pos;
        int st=f.st;
        if(cur==n&&st%k==0){
            cout<<st<<endl;
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
        for(int i=0;i<e[cur].size();i++){
            q.push(st+1,e[u][i]);
        }
    }
    cout<<-1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
Zyctc AK IOI
F1amir3 AK IOI
Ranger_CW AK IOI
*/