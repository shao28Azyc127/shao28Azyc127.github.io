#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans;
struct node{
    int id;
    char c;
    bool operator <(const node&x)const
    {
        return id<x.id;
    }
};
priority_queue<node> q;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
           
            for(int k=i;k<=j;k++)
            {
                if(q.empty())
                {
                    q.push((node){k,s[k]});
                }
                else
                if(s[k]==q.top().c)
                {
                    q.pop();
                }
                else
                q.push((node){k,s[k]});
            }
            if(q.empty())
            ans++;
            while(!q.empty())
            {
                q.pop();
            }
        }
    }
    cout<<ans;
    
    
    return 0;
}