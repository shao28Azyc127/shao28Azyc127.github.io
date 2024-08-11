#include<bits/stdc++.h>
using namespace std;
int n;
string tp[101],id[101];
int a[101],b[101];
int s,addr;
int op;
int cnt;
int t;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>op;
        if (op==2)
        {
            ++cnt;
            cin>>tp[cnt]>>id[cnt];
            if (tp[cnt]=="short")
            {
                if (t%2!=0)
                {
                    t=2*(t/2+1);
                }
                a[cnt]=t;
                b[cnt]=t+1;
                ++t;
            }
            else if (tp[cnt]=="byte")
            {
                a[cnt]=t;
                b[cnt]=t;
                ++t;
            }
            else if (tp[cnt]=="int")
            {
                if (t%4!=0)
                {
                    t=4*(t/4+1);
                }
                a[cnt]=t;
                b[cnt]=t+3;
                ++t;
            }
            else if (tp[cnt]=="long")
            {
                if (t%8!=0)
                {
                    t=8*(t/8+1);
                }
                a[cnt]=t;
                b[cnt]=t+1;
                ++t;
            }
            cout<<a[cnt]<<endl;
        }
        else if (op==3)
        {
            string p;
            cin>>p;
            for (int j=1;j<=cnt;++j)
            {
                if (id[j]==p)
                {
                    cout<<a[j]<<endl;
                }
            }
        }
        else
        {
            int x;
            cin>>x;
            bool flag=false;
            for (int j=1;j<=cnt;++j)
            {
                if (a[j]<=x && b[j]>=x)
                {
                    flag=true;
                    cout<<a[j]<<endl;
                    break;
                }
            }
            if (!flag)
            {
                cout<<"ERR"<<endl;
            }
        }
    }
    return 0;
}
