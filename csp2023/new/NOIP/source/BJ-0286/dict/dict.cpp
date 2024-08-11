#include <bits/stdc++.h>
#define maxn 3001
using namespace std;
bool res[maxn];
int n,m,cnt[26],ans[26],pos;
string s[maxn];
bool cmp()
{
    int last=25,rem=cnt[last];
    for(int i=25;i>=0;i--)
    {
        int tmp=ans[i];
        while(!rem) rem=cnt[--last];
        while(tmp>0)
        {
            if(last>i) return false;
            if(last<i) return true;
            if(tmp>=rem){
                tmp-=rem;
                rem=cnt[--last];
            }
            else{
                rem-=tmp;
                tmp=0;
            }
            if(last>i) return false;
            if(last<i) return true;
        }
    }
    return false;
}
bool cmp2()
{
    int last=0,rem=cnt[last];
    for(int i=25;i>=0;i--)
    {
        int tmp=ans[i];
        while(!rem) rem=cnt[++last];
        while(tmp>0)
        {
            if(last>i) return false;
            if(last<i) return true;
            if(tmp>=rem){
                tmp-=rem;
                rem=cnt[++last];
            }
            else{
                rem-=tmp;
                tmp=0;
            }
            if(last>i) return false;
            if(last<i) return true;
        }
    }
    return false;
}
int main()
{
    //cuole1ge
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    pos=1;
    for(int j=0;j<s[1].length();j++) ans[s[1][j]-'a']++;
    /*cout<<"ans: \n";
    for(int j=0;j<=25;j++) cout<<ans[j]<<' ';
    cout<<'\n';*/
    for(int i=2;i<=n;i++)
    {
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<s[i].length();j++)
        {
            cnt[s[i][j]-'a']++;
        }
        /*if(i==1149)
        {
            cout<<"cnt when i="<<i<<": \n";
            for(int j=0;j<=25;j++) cout<<cnt[j]<<' ';
            cout<<'\n';
        }*/

        if(cmp())//return true->less
        {
            //cout<<"i="<<i<<'\n';
            pos=i;
            memcpy(ans,cnt,sizeof(cnt));
        }
    }
    /*cout<<"pos: "<<pos<<'\n';
    cout<<"ans: \n";
    for(int i=0;i<=25;i++) cout<<ans[i]<<' ';
    cout<<'\n';*/
    for(int i=1;i<=n;i++)
    {
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<s[i].length();j++)
        {
            cnt[s[i][j]-'a']++;
        }
        if(i==pos) res[i]=1;
        else{
            if(cmp2()) res[i]=1;
            else res[i]=0;
        }
    }
    for(int i=1;i<=n;i++) cout<<res[i];
    cout<<'\n';
    return 0;
}
