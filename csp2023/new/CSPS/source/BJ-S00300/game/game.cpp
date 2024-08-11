#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n,m,i,j,k,ans;
string s;
bool vis[1000009];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    string ss=s;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            string t="";
            for(k=i;k<=j;k++) t+=s[k];
            while(1)
            {
                for(k=0;k<n;k++) vis[k]=0;
                int l=t.size();
                for(k=0;k<l-1;k++)
                    if(t[k]==t[k+1]) vis[k]=vis[k+1]=1;
                string tt=t;
                t="";
                for(k=0;k<l;k++)
                    if(!vis[k]) t+=tt[k];
                if(l==t.size()) break;
            }
            if(t.size()==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}
//ygg pls no mark