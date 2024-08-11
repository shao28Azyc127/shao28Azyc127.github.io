#include<iostream>
#include<cstring>
using namespace std;
int n;
bool vis[1000000005];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    if(n<=10)
    {
        if(n==1)
        {
            cout<<"1 1";
        }
        else if(n==2)
        {
            cout<<"2 2";
        }
        else if(n==3)
        {
            cout<<"3 3";
        }
        else if(n==4)
        {
            cout<<"3 1";
        }
        else if(n==5)
        {
            cout<<"4 4";
        }
        else if(n==6)
        {
            cout<<"4 2";
        }
        else if(n==7)
        {
            cout<<"4 1";
        }
        else if(n==8)
        {
            cout<<"5 5";
        }
        else if(n==9)
        {
            cout<<"5 3";
        }
        else if(n==10)
        {
            cout<<"5 1";
        }
        return 0;
    }
    memset(vis,0,sizeof(vis));
    int m=n,i=0,cnt=0,LUN=1,ans,en=0;
    bool flag=true;
    vis[i]=true;
    --m;
    while(m>0)
    {
        ++i;
        if(i>=n)
        {
            if(en!=-1)
            {
                vis[en]=true;
                if(en==(n-1))
                {
                    ans=LUN;
                }
                --m;
                if(m==0)
                    break;
            }
            cnt=0;
            ++LUN;
            i%=n;
            flag=false;
        }
        if(vis[i]==false)
        {
            ++cnt;
            en=i;
            if(cnt==3)
            {

                vis[i]=true;
                if(i==(n-1))
                {
                    ans=LUN;
                }
                cnt=0;
                --m;
                en=-1;
            }
        }
    }
    cout<<LUN<<" "<<ans;
    return 0;
}
