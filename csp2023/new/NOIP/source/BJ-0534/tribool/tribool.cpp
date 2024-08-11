#include <bits/stdc++.h>
using namespace std;
struct fuzhi
{
    int sym;
    int to;
}a[101000];
int isu[101000],q[101000],vis[101000],in[101000],out[101000];
vector<int> b[101000],c[101000];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,t;
    cin>>C>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(vis,0,sizeof(vis));
        memset(c,0,sizeof(c));
        memset(isu,0,sizeof(isu));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;i++){
            a[i].to=i;
            a[i].sym=1;
        }
        while (m--){
            char x;
            cin>>x;
            if (x=='T') {
                int i;
                cin>>i;
                a[i].to=0;
                a[i].sym=1;
            }
            if (x=='U') {
                int i;
                cin>>i;
                a[i].to=-1;
                a[i].sym=1;
            }
            if (x=='F') {
                int i;
                cin>>i;
                a[i].to=0;
                a[i].sym=-1;
            }
            if (x=='+'){
                int i,j;
                cin>>i>>j;
                a[i].to=a[j].to;
                a[i].sym=a[j].sym;
            }
            if (x=='-'){
                int i,j;
                cin>>i>>j;
                a[i].to=a[j].to;
                a[i].sym=-a[j].sym;
            }
        }
        for (int i=1;i<=n;i++){
            int T=a[i].to;
            if (i==T&&a[i].sym==1) continue;
            b[T].push_back(i);
            c[i].push_back(T);
            in[i]++;
            out[T]++;
        }
        for (int i=1;i<=n;i++){
            if (a[i].to==-1) {
                isu[i]=1;
            }
        }

        /*
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++){
            if ()
            int pos=a[i].to;
            int c=a[i].sym;
            while (a[pos]!=pos&&)
        }
        */
        //memset(vis,0,sizeof(vis));
        int l=0,r=-1;
        for (int i=1;i<=n;i++){
            if (in[i]==0) {
                r++;
                q[r]=i;
            }
        }
        for (;l<=r;l++){
            int u=q[l];
            for (int j=0;j<b[u].size();j++){
                int k=b[u][j];
                in[k]--;
                if (in[k]==0) {
                    r++;
                    q[r]=k;
                }
            }
        }
        l=0,r=-1;
        for (int i=1;i<=n;i++){
            if (out[i]==0) {
                r++;
                q[r]=i;
            }
        }
        for (;l<=r;l++){
            int u=q[l];
            for (int j=0;j<c[u].size();j++){
                int k=c[u][j];
                out[k]--;
                if (out[k]==0) {
                    r++;
                    q[r]=k;
                }
            }
        }
        for (int i=1;i<=n;i++){
            if (in[i]==1&&out[i]==1){
                //cout<<i<<'\n';
                int pos=a[i].to;
                int c=a[i].sym;
                while (pos!=i) {
                    c=c*a[pos].sym;
                    pos=a[pos].to;
                }
                if (c==-1){
                    isu[i]=1;
                    pos=a[i].to;
                    while (pos!=i) {
                        isu[pos]=1;
                        pos=a[pos].to;
                    }
                }
            }
        }
        l=0,r=-1;
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=n;i++){
            if (isu[i]==1){
                r++;
                q[r]=i;
                vis[i]=1;
            }
        }
        for (;l<=r;l++){
            int u=q[l];
            for (int j=0;j<b[u].size();j++){
                int k=b[u][j];
                if (vis[k]==0) {
                    vis[k]=1;
                    isu[k]=1;
                    r++;
                    q[r]=k;
                }
            }
            for (int j=0;j<c[u].size();j++){
                int k=c[u][j];
                if (vis[k]==0) {
                    vis[k]=1;
                    isu[k]=1;
                    r++;
                    q[r]=k;
                }
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++) if (isu[i]==1) ans++;
        cout<<ans<<'\n';
        /*
        for (int i=1;i<=n;i++){
            cout<<isu[i];
        }
        cout<<'\n';
        */
        /*
        for (int i=1;i<=n;i++){
            cout<<a[i].to<<" "<<a[i].sym<<'\n';
        }
        */
    }
    return 0;
}
