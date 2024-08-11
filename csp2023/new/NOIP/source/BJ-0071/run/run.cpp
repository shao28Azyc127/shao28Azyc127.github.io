#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin ("run.in");
ofstream cout ("run.out");
struct Chal
{
    int l,r,v;
}a[100010];
vector <int> gz[200010];
int tmp [200010];
long long int f[200010];
int main ()
{
    int C,T;
    cin>>C>>T;
    while (T--)
    {
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        for (int i=1;i<=m;i++)
        {
            int x,y,v;
            cin>>x>>y>>v;
            a[i].l=x-y+1,a[i].r=x,a[i].v=v;
            tmp[2*i-1]=a[i].l,tmp[2*i]=a[i].r;
        }
        sort (tmp+1,tmp+m+m+1);
        int cnt = unique(tmp+1,tmp+m+m+1)-tmp-1;
        for (int i=1;i<=m;i++)
        {
            a[i].l=lower_bound(tmp+1,tmp+cnt+1,a[i].l)-tmp;
            a[i].r=lower_bound(tmp+1,tmp+cnt+1,a[i].r)-tmp;
            gz[a[i].l].emplace_back(i);
        }
        for (int i=1;i<=cnt;i++)
        {
            f[i]=f[i-1];
            long long int sum=0;
            for(int j=i;j>=1;j--)
            {
                if (tmp[j]<=tmp[i]-k)
                {
                    break;
                }
                for (auto k:gz[j])
                {
                    if(a[k].r<=i)
                    {
                        sum+=a[k].v;
                    }
                }
                f[i]=max(f[i],f[(tmp[j]==tmp[j-1]+1 and tmp[j-1])?j-2:j-1]+sum-1ll*d*(tmp[i]-tmp[j]+1));
            }
            // cerr<<f[i]<<endl;
        }
        cout<<f[cnt]<<endl;
        for (int i=1;i<=cnt;i++)
        {
            gz[i].clear();
        }
    }
}