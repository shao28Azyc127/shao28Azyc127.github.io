#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
    int x[10];
    bool operator < (const node &n1) const
    {
        for(int i=1;i<=5;i++) if(x[i]!=n1.x[i]) return x[i]<n1.x[i];
        return false;
    }
    bool operator == (const node &n1) const
    {
        for(int i=1;i<=5;i++) if(x[i]!=n1.x[i]) return false;
        return true;
    }
};
int n,a[10],cnt,it;
node s[N];
int main()
{
    freopen("lock.in","r",stdin);freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<81;
        return 0;
    }
    while(n--)
    {
        for(int i=1;i<=5;i++) cin>>a[i];
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=9;j++)
            {
                a[i]+=j;
                node tmp;
                for(int k=1;k<=5;k++) tmp.x[k]=a[k]%10;
                s[++it]=tmp;
                a[i]-=j;
            }
        }
        for(int i=1;i<5;i++)
        {
            for(int j=1;j<=9;j++)
            {
                a[i]+=j;a[i+1]+=j;
                node tmp;
                for(int k=1;k<=5;k++) tmp.x[k]=a[k]%10;
                s[++it]=tmp;
                a[i]-=j;a[i+1]-=j;
            }
        }
    }
    sort(s+1,s+it+1);
    for(int i=1;i<it;i++) if(s[i]==s[i+1]) cnt++;cout<<cnt<<endl;
    return 0;
}
