#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int maxn=1e5+10;
int c,t,n,m,col[maxn],sz[maxn],ans;
vector<pair<int,bool>> grp[maxn];

struct trace{
    int typ; // 0->Const 1->Input 2->!Input 
    int data;
    int value;
} val[maxn];
int boolstrasint(char b){
    if(b=='U')return 0;
    if(b=='F')return 1;
    return 2;
}
bool dfs(int cur,int pa){ // check if there a invalid
    bool flag=0;
    sz[cur]=1;
    for(pair<int,int> edge:grp[cur])if(edge.first!=pa){
        int target_color = col[cur]^edge.second;
        if(col[edge.first]!=-1){
            if(col[edge.first]!=target_color)flag=1;
            continue;
        }
        col[edge.first]=target_color;
        flag|=dfs(edge.first,cur);
        flag|=val[edge.first].typ==0&&val[edge.first].data==0;
        sz[cur]+=sz[edge.first];
    }
    return flag;
}


int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        // read, collect connects
        memset(col,-1,sizeof(col));
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)val[i]={1,i,-1},grp[i].clear();
        for(int i=1;i<=m;i++){
            char op;
            int fpos,tpos;
            cin>>op>>fpos;
            if(op=='+'||op=='-')cin>>tpos;
            
            if(op=='T'||op=='U'||op=='F')val[fpos]={0,boolstrasint(op),-1};
            if(op=='+')val[fpos]=val[tpos];
            if(op=='-'){
                val[fpos]=val[tpos];
                if(val[tpos].typ==1)val[fpos].typ=2;
                else if(val[tpos].typ==2)val[fpos].typ=1;
            }
        }
        // create graph
        for(int i=1;i<=n;i++)if(val[i].typ!=0){
            grp[i].push_back({val[i].data,val[i].typ-1});
            grp[val[i].data].push_back({i,val[i].typ-1});
        }
        // depth-last-search aka DLS
        for(int i=1;i<=n;i++)if(col[i]==-1){
            col[i]=0;
            int r=dfs(i,0);
            if(r||(val[i].typ==0&&val[i].data==0))ans+=sz[i];
        }
        cout<<ans<<endl;
        
    }
}