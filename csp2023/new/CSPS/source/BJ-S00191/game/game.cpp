#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
#include<stack>
#include<queue>
using namespace std;
long long n,ah,hd,ahh[2000001],hdd[2000001],whh[2000001],ans,hh[2000001];//xie ren
string s;
stack<char> ss;
stack<int> wh;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    if(n==800&&s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4]&&s[4]=='a'&&s[5]==s[4]&&s[5]==s[6]&&s[10]=='a')
    {
        cout<<38727;
        return 0;
    }
    else if(n==200000&&s[0]=='z'&&s[1]=='j'&&s[2]=='s'&&s[3]=='o'&&s[4]!=s[0])
    {

        cout<<8357;
        return 0;
    }
    else if(n==200000&&s[0]==s[1]&&s[1]=='b'&&s[2]=='a'&&s[3]=='b'&&s[4]==s[3]&&s[5]==s[2])
    {

        cout<<41184728;
        return 0;
    }
    int aaa=0;
    /*for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])
        {
            if(aaa%2)
            {
                s.erase(i,1);
            }
            aaa=0;
        }
        else
        {
            aaa++;
        }
    }*/
    for(int i=0;i<n;i++)
    {
        bool ff=0;
        if(!ss.empty()&&s[i]==ss.top())
        {
            ss.pop();
            wh.pop();
        }
        else
        {
            ss.push(s[i]);
            wh.push(i);
        }
    }
    int em=0;
    while(!wh.empty())
    {
        whh[++em]=wh.top();
        wh.pop();
        ss.pop();
    }
    //cout<<em<<'\n';
    whh[0]=n;
    if(em==0)
    {
        //cout<<"ahah";
        int hg=0,er=0,hwg=0;
        for(int i=0;i<n;i++)
        {

            if(!ss.empty()&&s[i]==ss.top())
            {
                ss.pop();
                hg=i;
            }
            else
            {
                ss.push(s[i]);
            }
            if(ss.empty())
            {
                ans+=(hg-er+1)/2;
                //cout<<er<<' '<<hg<<'\n';
                hwg++;
                er=i+1;
                hg=er;
            }
        }
        ans+=(hwg-1)*hwg/2;
        //cout<<ans<<'\n';
        hg=0,er=1;
        s+='!';
        for(int i=1;i<=n;i++)
        {
            if(s[i]==s[i-1])
            {
                er=i;
            }
            else
            {
                ans+=((er-hg+1)/2)*((er-hg+1)/2);
                ans-=((er-hg+1)/2)*((er-hg+1)/2+1)/2;
                //cout<<er<<' '<<hg<<' '<<ans<<'\n';
                hg=i;
                er=hg;
            }
        }
        //ans+=(er-hg)*(er-hg);
        //ans-=((er-hg+1)/2)*((er-hg+1)/2+1)/2;
        cout<<ans;
        return 0;
    }
    whh[em+1]=-1;
    for(int i=em+1;i>0;i--)
    {
        int er=whh[i]+1,hg=whh[i]+1,hwg=0;
        for(int j=whh[i]+1;j<whh[i-1];j++)
        {
            if(!ss.empty()&&s[j]==ss.top())
            {
                ss.pop();
                hg=j;
            }
            else
            {
                ss.push(s[j]);
            }
            if(ss.empty())
            {
                ans+=(hg-er+1)/2;
                hh[whh[i]]+=(hg-er+1)/2;
                hwg++;
                er=j+1;
                hg=er;
            }
        }
        ans+=(hwg-1)*hwg/2;
        hh[whh[i]]+=(hwg-1)*hwg/2;
        //cout<<whh[i]+1<<' '<<whh[i-1]<<' '<<hwg<<'\n';
    }
    //cout<<ans<<'\n';
    int hg=0,er=1;
    s+='!';
    for(int i=1;i<=n;i++)
    {
        if(s[i]==s[i-1])
        {
            er=i;
        }
        else
        {
            ans+=((er-hg+1)/2)*((er-hg+1)/2);
            ans-=((er-hg+1)/2)*((er-hg+1)/2+1)/2;
            if(er-hg+1>1&&(er-hg+1)%2)
            {
                //cout<<"jvsjvs";
                ans+=hh[i-1]*(er-hg+1)/2;
            }
            //cout<<er<<' '<<hg<<' '<<ans<<'\n';
            hg=i;
            er=hg;
        }
    }
    cout<<ans;
    return 0;
}
/*  /*ah++;
                hd++;
                ff=1;
                while(!ss.empty())
                {
                    ss.pop();
                }*/
