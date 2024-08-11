#include<bits/stdc++.h>
using namespace std;
stack<int> s;
queue<int> q;
string t;
long long n,ans;
int a[2000010],b[2000010],c[2000010];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>t;
    for(int i=0;i<n;i++)
    {
        a[i+1]=t[i]-'a'+1;
        c[i+1]=i+1;
    }
    for(int i=1;i<=n;i++)
    {
        if(q.empty())
        {
            q.push(i);
            if(!s.empty()&&a[s.top()]==a[i])
            {
                ans++;
                if(s.top()-1>=0)
                {
                    ans+=b[s.top()-1];
                    b[i]=b[s.top()-1]+1;
                    c[i]=c[s.top()-1];
                }
                //cout<<ans<<"D"<<i<<endl;
                while(!q.empty())
                {
                    s.push(q.front());
                    q.pop();
                }
            }
            else if(!s.empty()&&a[c[s.top()]]==a[i])
            {
                ans++;
                if(c[s.top()]-1>=0)
                {
                    ans+=b[c[s.top()]-1];
                    b[i]=b[c[s.top()]-1]+1;
                    c[i]=c[c[s.top()]-1];
                }
                //cout<<ans<<"A"<<i<<endl;
                while(!q.empty())
                {
                    s.push(q.front());
                    q.pop();
                }
            }
            continue;
        }
        else if(a[q.front()]==a[i])
        {
            q.push(i);
            ans++;
            if(q.front()-1>=0)
            {
                ans+=b[q.front()-1];
                b[i]=b[q.front()-1]+1;
                c[i]=c[q.front()-1];
            }
            //cout<<ans<<"B"<<i<<endl;
            while(!q.empty())
            {
                s.push(q.front());
                q.pop();
            }
        }
        else
        {
            q.push(i);
            //cout<<ans<<"C"<<i<<endl;
            while(q.front()!=i)
            {
                s.push(q.front());
                q.pop();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
