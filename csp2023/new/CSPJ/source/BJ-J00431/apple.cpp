#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","r",stdout);
    ios::sync_with_stdio(false);
    queue <long long> q;
    queue <long long> p;
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    long long c=0;
    long long b;
    while(q.empty()==false)
    {
        c++;
        while(q.empty()==false)
        {
            if(q.front()==n)
            {
                b=c;
            }
            q.pop();
            if(q.empty()==false){
                p.push(q.front());
                q.pop();
            }
            if(q.empty()==false){
                p.push(q.front());
                q.pop();
            }
        }
        while(p.empty()==false)
        {
            q.push(p.front());
            p.pop();
        }
    }
    cout<<c<<" "<<b;



    return 0;
}
