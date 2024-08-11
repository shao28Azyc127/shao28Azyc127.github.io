#include<bits/stdc++.h>
using namespace std;
long long c, t, n, m;
char i, j;
char v;
char w[1000];
char cmd[1000][4];
char command[3] = {'T', 'F', 'U'};
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin>>c>>t;
    for(long long x=0;x<t;x++)
    {
        cin>>n>>m;
        long long q=99999999;
        for(long long y=0;y<m;y++)
        {
            cin>>v;
            cmd[y][0] = v;
            if(v=='-')
            {
                cin>>i>>j;
                cmd[y][1]=i;
                cmd[y][2]=j;
            }
            else if(v=='+')
            {
                cin>>i>>j;
                cmd[y][1] = i;
                cmd[y][2] = j;
            }
            else if(v=='T'||v=='F'||v=='U')
            {
                cin>>i;
                cmd[y][1] = i;
            }
        }
        char com;
        long long cnt=0;
        for(long long k=0;k<3;k++)
        {
            w[1] = command[k];
            for(long long e=0;e<m;e++)
            {
                com=w[1];
                if(cmd[e][0]=='+')
                {
                    w[cmd[e][1]-'0']=w[cmd[e][2]-'0'];
                }
                else if(cmd[e][0] == '-')
                {
                    if(w[cmd[e][2]-'0']=='T')
                    {
                        w[cmd[e][1]-'0']='F';
                    }
                    else if(w[cmd[e][2]-'0']=='F')
                    {
                        w[cmd[e][1]-'0']='T';
                    }
                    else
                    {
                        w[cmd[e][1]-'0']='U';
                    }
                }
                else if(cmd[e][0]=='T'||cmd[e][0]=='F'||cmd[e][0]=='U')
                {
                    w[cmd[e][1]-'0'] = cmd[e][0];
                }
                else continue;
                if(com!=w[1])
                {
                    for(long long i=1;i<=n;i++)
                    {
                        w[i]='U';
                    }
                }
            }
            for(long long i=1;i<=n;i++)
            {
                if(w[i]=='U')
                {
                    cnt++;
                }
            }
            if(q>cnt)
            {
                q=cnt;
            }
        }
        cout<<q<<endl;
    }
    return 0;
}
