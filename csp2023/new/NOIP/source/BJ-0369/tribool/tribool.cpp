#include<bits/stdc++.h>
using namespace std;
char id[1005],tp[1005];
short adj[1005][1005];//0->no edge 1->same 2->diff
vector<int>adjt[1005],vec;
int ind[1005],lst[1005],n,m,c,t,a,b;
char op;
bool isd[1005],vis[1005];
bool bfs(int start){
   // cout<<endl<<id[start]<<endl;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
     //   for(int i=1;i<=n;i++) cout<<id[i]<<" ";
     //   cout<<endl;
        int t=q.front();
        q.pop();
      //  cout<<t<<endl;
        for(int i=0;i<adjt[t].size();i++){
            int v=adjt[t][i];
            if(adj[t][v]){
                char newid;
                if(adj[t][v]==2){
                    if(id[t]=='T') newid='F';
                    if(id[t]=='F') newid='T';
                    if(id[t]=='U') newid='U';
                }else newid=id[t];
            //    cout<<newid<<" "<<id[t]<<" "<<id[v]<<" "<<v<<" "<<t<<endl;
                if(id[v]!='P'&&id[v]!=newid){return false;}
                if(id[v]=='P'){
                    id[v]=newid;
                    vec.push_back(v);
                    q.push(v);
                }
            }
        }
    }
    return true;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
    //    cout<<n<<" "<<m<<endl;
        for(int i=1;i<=n;i++) id[i]=tp[i]='P';
        memset(adj,0,sizeof(adj));
        memset(isd,0,sizeof(isd));
        memset(lst,0,sizeof(lst));
        for(int i=1;i<=n;i++) adjt[i].clear();
        for(int i=1;i<=m;i++){
            cin>>op;
            if(op=='+'){
                cin>>a>>b;
                adj[lst[a]][a]=0;
                adj[a][lst[a]]=0;
                lst[a]=b;
                adj[b][a]=1,adjt[b].push_back(a);
                adj[a][b]=1,adjt[a].push_back(b);
                id[a]=tp[a]='P';
                isd[a]=0;
            }else if(op=='-'){
                cin>>a>>b;
                adj[lst[a]][a]=0;
                adj[a][lst[a]]=0;
                lst[a]=b;
                adj[b][a]=2,adjt[b].push_back(a);
                adj[a][b]=2,adjt[a].push_back(b);
                id[a]=tp[a]='P';
                isd[a]=0;
            }else{
                cin>>a;
                id[a]=tp[a]=op;
                isd[a]=1;
            }
        //    cout<<n<<" "<<m<<endl;
         //   for(int i=1;i<=n;i++){
         //       for(int j=1;j<=n;j++) cout<<adj[i][j]<<" ";
         //       cout<<endl;
         //   }
            for(int i=1;i<=n;i++)
                if(tp[i]=='P') id[i]='P';
         //   for(int i=1;i<=n;i++) cout<<id[i]<<" ";
          //  cout<<endl;
            for(int i=1;i<=n;i++)
                if(tp[i]!='P') bfs(i);
            for(int i=1;i<=n;i++)
                if(id[i]=='P'){
                    vec.clear();
                    id[i]='T';
                    if(!bfs(i)){
                        for(int j=0;j<vec.size();j++)
                            if(tp[vec[j]]=='P') id[vec[j]]='P';
                        id[i]='F';
                        vec.clear();
                      //  cout<<"1211111111111"<<endl;
                        if(!bfs(i)){
                            for(int j=0;j<vec.size();j++)
                                if(tp[vec[j]]=='P') id[vec[j]]='P';
                            id[i]='U',bfs(i);
                        }
                    }
                }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(id[i]=='U') ans++;
         //   cout<<id[i]<<" ";
        }
       // cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}