#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define p1(x) (x).f
#define p2(x) (x).s
#define endl "\n"
int f[300030];
struct node{
    int f,s,c;
};
node A[300300];
int n,m,k,d;
int l[300300];
int s[300300];
int v[300300];
int dp[1030][1030];
int w[1030][1030];
int b[300400];
inline bool cmp(node x,node y){
    return x.f<y.f;
}
inline bool cmp2(int x,int y){
    return A[x].f>A[y].f;
}
int g[2][210];
vector<int>T[300400];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c>=17&&c<=21){
        while(t--){
            memset(f,-0x3f,sizeof(f));
            memset(s,-0x3f,sizeof(s));
            memset(l,-0x3f,sizeof(l));
            cin>>n>>m>>k>>d;
            int p=1;
            int ct=0;
            for(int i=1;i<=m;i++){
                int x,y;
                cin>>x>>y>>v[i];
                A[i]=(node){x-y+1,x,v[i]};
                if(p1(A[i])>p2(A[i-1])+1)
                A[m+(++ct)]={p2(A[i-1])+1,p2(A[i-1])+1,0};
            }
            m=m+ct;
            sort(A+1,A+m+1,cmp);
            for(int i=1;i<=m;i++){
                s[i]=s[i-1]+A[i].c;
                while(p<=i&&p2(A[i])-p1(A[p])+1>k)p++;
                l[i]=p;
            }
            deque<int>q;
            f[0]=0;
            q.push_back(0);
            for(int i=1;i<=m+1;i++){
                while(!q.empty()&&q.front()<l[i-1]-1)q.pop_front();
                if(q.empty()||q.front()>=i-1)
                    f[i]=f[i-1];
                else {
                    int j=q.front();
                    assert(p2(A[i-1])-p1(A[j+1])+1<=k);
                    f[i]=max(f[i-1],f[j]+s[i-1]-s[j]-d*(p2(A[i-1])-p1(A[j+1])+1));
                }
                while(!q.empty()&&f[q.back()]-s[q.back()]+p1(A[q.back()+1])*d<=f[i]-s[i]+p1(A[i+1])*d)
                    q.pop_back();
                q.push_back(i);
            }
            cout<<f[m+1]<<"\n";

        }
    }
    else if(c<=9){
        while(t--){
            memset(dp,-0x3f,sizeof(dp));
            memset(w,0,sizeof(w));
            cin>>n>>m>>k>>d;
            for(int i=1;i<=m;i++){
                int x,y,c;
                cin>>x>>y>>c;
                w[x][x-y+1]+=c;
            }
            for(int i=1;i<=n;i++)
                for(int j=i-1;j>=1;j--)
                    w[i][j]+=w[i][j+1];

            dp[0][0]=0;
            for(int i=0;i<n;i++)
                for(int j=max(0ll,i-k);j<=i;j++){
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]-d+w[i+1][j+1]);
                    dp[i+1][i+1]=max(dp[i+1][i+1],dp[i][j]);
                }
            int res=0;
            for(int i=max(0ll,n-k);i<=n;i++)
                res=max(res,dp[n][i]);
            cout<<res<<endl;
        }
    }
    else {
        while(t--){
            memset(g,-0x3f,sizeof(g));
            cin>>n>>m>>k>>d;
            for(int i=1;i<=m;i++){
                int x,y,c;
                cin>>x>>y>>c;
                A[i]={x-y+1,x,c};
                b[i]=x,b[i+m]=x-y+1;
            }
            sort(b+1,b+2*m+1);
            auto  tmp=unique(b+1,b+2*m+1);
            n=tmp-b-1;
            for(int i=1;i<=m;i++){
                p1(A[i])=lower_bound(b+1,tmp,p1(A[i]))-b;
                p2(A[i])=lower_bound(b+1,tmp,p2(A[i]))-b;
                T[p2(A[i])].push_back(i);
            }
            for(int i=1;i<=n;i++)
                sort(T[i].begin(),T[i].end(),cmp2);
            g[0][0]=0;
            for(int i=0;i<n;i++){
                int now=0;
                auto it=T[i+1].begin();
                for(int j=0;j<k;j++){
                    int loc=i-j+1;

                    if(j!=0&&i-j+1<1||b[i]-b[loc]+1>=k)break;
                    while(it!=T[i+1].end()&&p1(A[*it])>=loc)
                        now+=A[*it].c,it++;
                    if(j)
                        g[1][j+1]=max(g[1][j+1],g[0][j]-d*(b[i+1]-b[i])+now);
                    else
                        g[1][1]=max(g[1][1],g[0][0]-d+now);
                    g[1][0]=max(g[1][0],g[0][j]);
                }
                swap(g[0],g[1]);
                memset(g[1],-0x3f,sizeof(g[1]));
            }
            int res=g[0][1];
            for(int j=0;j<k;j++){
                if(j!=0&&n-j+1<1||b[n]-b[n-j+1]+1>=k){break;}
                res=max(res,g[0][j]);
            }
            cout<<res<<endl;
        }
    }
    cout.flush();
    return 0;
}
