#include<stdio>
#include<iostream>
using namespace std;

struct Tree
{
    long long a,b,c,h;
}t[100005];
int box[100005];

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].a>>t[i].b>>t[i].c;
        for(int j=1;j<=n;j++)
        {
            t[i].h=max(t[i].b+i?t[i].c,1);
            if(t[i].h>t[i].a)
            {
                ans++;
                box[i]++;
            }
        }
        bool flag=true;
        for(int j=1;j<=n;j++)
        {
            if(box[i]<=0)
            {
                flag=false;
            }
        }
        if(flag==true)
        {
            break;
        }
        
    }
    cout<<ans<<endl;
    return 0;
}
