#include <bits/stdc++.h>
using namespace std;
string s[110],c;
int a[810],now=-1,n,num,id[110];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==2)
        {
            cin>>c>>s[++num];
            if(c=="byte")
            {
                cout<<++now<<endl;
                id[num]=now;
                a[now]=num;
            }
            if(c=="short")
            {
                now++;
                while(now%2)
                    now++;
                cout<<now<<endl;
                id[num]=now;
                a[now]=a[now+1]=num;
                now+=1;
            }
            if(c=="int")
            {
                now++;
                while(now%4)
                    now++;
                cout<<now<<endl;
                id[num]=now;
                a[now]=a[now+1]=a[now+2]=a[now+3]=num;
                now+=3;
            }
            if(c=="long")
            {
                now++;
                while(now%8)
                    now++;
                cout<<now<<endl;
                id[num]=now;
                a[now]=a[now+1]=a[now+2]=a[now+3]=a[now+5]=a[now+6]=a[now+7]=a[now+4]=num;
                now+=7;
            }
        }
        if(x==3)
        {
            cin>>c;
            for(int i=1;i<=num;i++)
                if(s[i]==c)
                {
                    cout<<id[i]<<endl;
                    break;
                }
        }
        if(x==4)
        {
            int y;
            cin>>y;
            if(a[y]==-1)
                cout<<"ERR"<<endl;
            else
                cout<<s[a[y]]<<endl;
        }
    }
    return 0;
}