#include<bits/stdc++.h>
using namespace std;
int n,a[100000005],p,q,s,ans;
bool b[100000005];
int main()
{
    int i,j;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int m=n;
    for(i=1;i<=n;i++)
    {
        a[i]=i;
    }
    p=1;
    q=n+1;
    s=1;
    int x;
    while(p!=q)
    {
        x=a[p];
        b[x]=true;
        //cout<<x<<" "<<s<<endl;
        if(x==n)
        {
            //cout<<x<<" "<<s<<endl;
            if(x==m) ans=s;
            s++;
            p=(p+1)%100000005;
            for(j=n-1;j>=1;j--)
            {
                if(!b[j])
                {
                    n=j;
                    break;
                }
            }
        }
        else
        {
            p=(p+1)%100000005;
            a[q]=a[p];
            q=(q+1)%100000005;
            if(a[p]==n)
            {
                s++;
                p=(p+1)%100000005;
            }
            else
            {
                p=(p+1)%100000005;
                a[q]=a[p];
                if(a[p]==n) s++;
                p=(p+1)%100000005;
                q=(q+1)%100000005;
            }

        }

    }
    cout<<s-1<<" "<<ans;
    return 0;
}