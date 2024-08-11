#include<bits/stdc++.h>
using namespace std;
bool zc(int a,int b)
{
    if(a/b*b==a)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    for(int i=0;i<T;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int t=b*b-4*a*c;
        if(t<0)
        {
            cout<<"NO\n";
            i++;
            continue;
        }
        int x;
        int k=sqrt(t);
        if(t==0)
        {
            if(zc(b,2*a))
            {
                cout<<-b/2/a;
            }
            else if(zc(b,2))
            {
                cout<<-b/2<<"/"<<a;
            }
            else if(zc(b,a))
            {
                cout<<-b/a<<"/"<<2;
            }
            else
            {
                cout<<-b<<"/"<<2*a;
            }
            cout<<"\n";
            i++;
            continue;
        }
        if(t==k*k)
        {
            if(a>0)
            {
                if(zc(k-b,2*a))
                {
                    cout<<(k-b)/2/a;
                }
                else if(zc(k-b,2))
                {
                    cout<<(k-b)/2<<"/"<<a;
                }
                else if(zc(k-b,a))
                {
                    cout<<(k-b)/a<<"/"<<2;
                }
                else
                {
                    cout<<(k-b)<<"/"<<2*a;
                }
            }
            else
            {
                if(zc(-b-k,2*a))
                {
                    cout<<(-b-k)/2/a;
                }
                else if(zc(-k-b,2))
                {
                    cout<<(-k-b)/2<<"/"<<a;
                }
                else if(zc(-k-b,a))
                {
                    cout<<(-k-b)/a<<"/"<<2;
                }
                else
                {
                    cout<<(-k-b)<<"/"<<2*a;
                }
            }
        }
        else
        {
            if(b!=0)
            {
                if(zc(b,2*a))
                {
                    cout<<-b/2/a;
                }
                else if(zc(b,2))
                {
                    cout<<-b/2<<"/"<<a;
                }
                else if(zc(b,a))
                {
                    cout<<-b/a<<"/"<<2;
                }
                else
                {
                    cout<<-b<<"/"<<2*a;
                }
                cout<<"+";
            }
            else
            {
                queue<int> q;
                for(int j=2;j<=k;j++)
                {
                    if(j==2 || j==a)
                    {
                        j++;
                        continue;
                    }
                    if(zc(t,j*j))
                    {
                        q.push(j);
                    }
                }
                int cnt=1;
                while(!q.empty())
                {
                    cnt*=q.front();
                    q.pop();
                }
                else if(zc(t,4*a*a))
                {

                    if(cnt!=1)
                    {
                        cout<<cnt<<"*";
                    }
                    cout<<"sqrt("<<t/4/a/a/cnt<<")";
                }
                else if(zc(t,4))
                {
                    if(cnt!=1)
                    {
                        cout<<cnt<<"*";
                    }
                    cout<<"sqrt("<<t/4/cnt<<")/"<<a*a;
                }
                else if(zc(t,a*a))
                {
                    if(cnt!=1)
                    {
                        cout<<cnt<<"*";
                    }
                    cout<<"sqrt("<<t/a/a/cnt<<")/4";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
