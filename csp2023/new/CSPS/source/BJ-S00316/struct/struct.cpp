#include <bits/stdc++.h>

using namespace std;
const int maxn=1e4+10;
int n;
struct node
{
    int d;
    vector<int> vec;
}a[maxn];
int tot;
map<int,string> vis;
map<string,int> pos;
int top;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    int op,x;
    string s;
    while(n--)
    {
        cin>>op;
        string t1,t2;
        if(op==2)
        {
            cin>>t1>>t2;
            if(t1=="byte")
            {
                vis[top]=t2;
                pos[t2]=top;
                top++;
            }
            if(t1=="int")
            {
                if(top%4!=0) top=(top/4+1)*4;
                vis[top]=vis[top+1]=vis[top+2]=vis[top+3]=t2;
                pos[t2]=top;
                top+=4;
            }
            if(t1=="short")
            {
                if(top%2!=0) top++;
                vis[top]=vis[top+1]=t2;
                pos[t2]=top;
                top+=2;
            }
            if(t1=="long")
            {
                if(top%8!=0) top=(top/8+1)*8;
                for(int j=0;j<=7;j++) vis[top+j]=t2;
                pos[t2]=top;
                top+=8;
            }
        }
        if(op==3)
        {
            cin>>t1;
            cout<<pos[t1]<<endl;
        }
        if(op==4)
        {
            cin>>x;
            if(vis[x]=="")
            {
                cout<<"ERR"<<endl;
                continue;
            }
            cout<<vis[x]<<endl;
        }
    }
	return 0;
}
