#include<bits/stdc++.h>
using namespace std;
#define cout if(0)cout
const int Maxn=1e5+10;
int q,c;
namespace test34{ // only assign
    int nums[Maxn];
    void work()
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) nums[i]=-1;
        while(m--)
        {
            char opts;
            cin>>opts;
            int x;
            scanf("%d",&x);
            if(opts=='T') nums[x]=1;
            else if(opts=='F') nums[x]=0;
            else nums[x]=2;
        }

        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(nums[i]==2) cnt++;
        }
        printf("%d\n",cnt);
    }
    void mian()
    {
        while(q--)
        {
            work();
        }
    }
}
namespace test1579{
    const int Maxg=1e5+10;
    int n,m;
    int dep[Maxn];
    struct Edge{
        int to;
        int type;
        int tim;
        int vis;
    };
    struct Node{
        int opt;
        int tim;
    };
    vector<Edge> G[Maxg];
    Node ass[Maxg];

    int Last[Maxn];int Lasttime[Maxn];
    // 0,1,2: 赋值 F,T,U
    bool vis[Maxn];
    vector<int> path,op; // 经过的点与符号
    void dfs(int now)
    {
        vis[now]=1;
        int Ass=ass[now].opt;
        int to=-1,tp=-1,tim=-1;
        int id=-1;
        for(int i=G[now].size()-1;i>=0;i--)
        {
            Edge fr=G[now][i];
            int v=fr.to,vi=fr.vis,type=fr.type;
            if(vi==1) continue;
            to=v,tp=type;tim=fr.tim;id=i;
            break;
        }
        if(tim==-1) return ;
        if(ass[now].tim>=tim)
        {
            return ;
        }
        G[now][id].vis=1;
        Lasttime[to]=tim;
        path.push_back(to);
        op.push_back(tp);
        dfs(to);
    }
    void calc(int i)
    {
        cout<<"nxt dfs:"<<i<<endl;
        //while(1){
        path.clear(),op.clear();
        path.push_back(i);
        dfs(i);
        //if(path.size()==1) break;
        int now=ass[path[path.size()-1]].opt;
        cout<<"path=";
        for(auto j:path) cout<<j<<" ";
        cout<<endl;
        cout<<"op=";
        for(auto j:op) cout<<j<<" ";
        cout<<endl;

        cout<<"now="<<now<<endl;
        if(now!=-1)
        {
            Last[path[path.size()-1]]=now;
            for(int i=path.size()-1;i>=1;i--)
            {
                int nxt=now;
                if(op[i-1]==-1)
                {
                    if(now==0) nxt=1;
                    if(now==1) nxt=0;
                }
                Last[path[i-1]]=nxt;
                now=nxt;
            }
        }else{
            cout<<"-------begin calculation---------"<<endl;
            int now;
            if(Last[path[path.size()-1]]!=-1)
            {
                now=Last[path[path.size()-1]];;
                Last[path[path.size()-1]]=now;
                bool isdied=0;
                for(int i=path.size()-1;i>=1;i--)
                {
                    int nxt=now;
                    if(op[i-1]==-1)
                    {
                        if(now==0) nxt=1;
                        if(now==1) nxt=0;
                    }
                    if(Last[path[i-1]]!=-1 && Last[path[i-1]]!=nxt)
                    {
                        isdied=1;
                        break;
                    }
                    Last[path[i-1]]=nxt;
                    cout<<"nxt="<<nxt<<endl;
                    now=nxt;
                    isdied=0;
                }

                if(isdied==1) now=2;
            }else{
                now=1;
                Last[path[path.size()-1]]=now;
                bool isdied=0;
                for(int i=path.size()-1;i>=1;i--)
                {
                    int nxt=now;
                    if(op[i-1]==-1)
                    {
                        if(now==0) nxt=1;
                        if(now==1) nxt=0;
                    }
                    if(Last[path[i-1]]!=-1 && Last[path[i-1]]!=nxt)
                    {
                        isdied=1;
                        break;
                    }
                    Last[path[i-1]]=nxt;
                    cout<<"nxt="<<nxt<<endl;
                    now=nxt;
                    isdied=0;
                }

                now=1;
                Last[path[path.size()-1]]=now;
                for(int i=path.size()-1;i>=1;i--)
                {
                    int nxt=now;
                    if(op[i-1]==-1)
                    {
                        if(now==0) nxt=1;
                        if(now==1) nxt=0;
                    }
                    if(Last[path[i-1]]!=-1 && Last[path[i-1]]!=nxt)
                    {
                        isdied=1;
                        break;
                    }
                    Last[path[i-1]]=nxt;
                    cout<<"nxt="<<nxt<<endl;
                    now=nxt;
                    isdied=0;
                }

                if(isdied==1) now=2;

                cout<<"----------"<<endl;
            }

            cout<<"In the End,now="<<now<<endl;
            if(now==2)
            {
                for(int i=path.size()-1;i>=0;i--)
                {
                    Last[path[i]]=2;
                }
            }
        }//}
    }
    struct Miao{
        int dp;
        int id;
    };
    vector<Miao> qwq;
    bool cmp(Miao a,Miao b)
    {
        return a.dp>b.dp;
    }
    void work()
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            ass[i].opt=-1;
            ass[i].tim=-1;
            Last[i]=-1;Lasttime[i]=-1;
            vis[i]=0;
            dep[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            char opt;
            cin>>opt;
            if(opt=='+')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                G[x].push_back((Edge){y,1,i,0});
                dep[y]++;
                //cout<<x<<"->"<<y<<":"<<1<<endl;
            }else if(opt=='-'){
                int x,y;
                scanf("%d%d",&x,&y);
                G[x].push_back((Edge){y,-1,i,0});
                dep[y]++;
                //cout<<x<<"->"<<y<<":"<<-1<<endl;
            }else{
                int x,type;
                scanf("%d",&x);
                if(opt=='U') type=2;
                else if(opt=='F') type=0;
                else type=1;
                ass[x]=((Node){type,i});
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ass[i].opt<<" "<<ass[i].tim<<endl;
        }
        cout<<endl;cout<<endl;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) calc(i);
        }

        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(Last[i]==2)
            {
                //printf("%d ",i);
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    void mian()
    {
        while(q--)
        {
            work();
        }
    }
}
int main()
{
    // RP+=inf
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&q);
    if(c==3 || c==4)
    {
        test34::mian();
        return 0;
    }
    test1579::mian();
    return 0;
}
