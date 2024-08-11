#include<bits/stdc++.h>
using namespace std;
int n,l,cnt=0;
string x;
const clock_t p=CLOCKS_PER_SEC*0.99;
inline bool Check(string y)
{
    if(clock()>=p)
    {
        cout<<cnt;
        exit(0);
    }
    //cout<<y<<endl;
    int ly=y.size();
    if(ly==0)
    {
        return true;
    }
    string z;
    int i=0;
    bool flag=false;
    while(i<ly)
    {
        /*
        if(y[i]==y[i+1])
        {
            string za=z;
            for(int j=i+2;j<ly;++j)
            {
                za+=y[j];
            }
            return Check(za);
        }
        */
        if(i<ly-1&&y[i]==y[i+1])
        {
            i+=2;
            flag=true;
        }
        else
        {
            z+=y[i];
            ++i;
        }
    }
    if(!flag)
    {
        return false;
    }
    return Check(z);
}
inline void f(int k)
{
    for(int i=0;i<=l-k;++i)
    {
        string y;
        for(int j=i;j<i+k;++j)
        {
            y+=x[j];
        }
        //cout<<y<<endl;
        if(Check(y))
        {
            ++cnt;
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    clock();
    cin>>n>>x;
    l=x.size();
    for(int i=2;i<=n;++i)
    {
        if(!(i&1))
        {
            f(i);
        }
    }
    cout<<cnt;
    return 0;
}
