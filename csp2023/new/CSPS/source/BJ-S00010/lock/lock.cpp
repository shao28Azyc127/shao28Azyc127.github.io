#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int> m;
string a[10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    getchar();
    for(int i=1;i<=n;i++) getline(cin,a[i]);
    for(int i=1;i<=n;i++) for(int j=0;j<a[i].size();j++) if(a[i][j]==' ') a[i].erase(j,1);
    //for(int i=1;i<=n;i++) cout<<a[i]<<endl;
    if(n==0) cout<<81;
    else
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=4;j++)
            {
                for(int k='0';k<='9';k++)
                {
                    int c=a[i][j];
                    if(k!=a[i][j]) a[i][j]=k,m[a[i]]++,a[i][j]=c;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=3;j++)
            {
                for(int k=1;k<=9;k++)
                {
                    int c[]={a[i][j],a[i][j+1]};
                    a[i][j]+=k,a[i][j+1]+=k;
                    if(a[i][j]>'9') a[i][j]-=10;
                    if(a[i][j+1]>'9') a[i][j+1]-=10;
                    m[a[i]]++;
                    a[i][j]=c[0];
                    a[i][j+1]=c[1];
                }
            }
        }
        for(auto i=m.begin();i!=m.end();i++) if(i->second==n) cnt++;
        cout<<cnt;
    }
    return 0;
}
