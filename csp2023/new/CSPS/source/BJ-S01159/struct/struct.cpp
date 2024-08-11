#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

unordered_map<string,int> len,sz;//leixing
unordered_map<string,vector<string> > xia;
unordered_map<int,string> add;//address
unordered_map<string,string> lx;//bianliang
unordered_map<string,string> tylx;
// vector<string> v;
//
unordered_map<string,int> ans;
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int Q;
    cin>>Q;
    len["byte"]=sz["byte"]=1;
    xia["byte"].clear();
    len["short"]=sz["short"]=2;
    xia["short"].clear();
    len["int"]=sz["int"]=4;
    xia["int"].clear();
    len["long"]=sz["long"]=8;
    xia["long"].clear();
    int now=0;
    while(Q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string name;    
            int k;
            cin>>name>>k;
            int mx=0,sum=0;
            for(int i=1;i<=k;i++)
            {
                string s,n;
                cin>>s>>n;
                string tmp=name+"."+n;
                tylx[tmp]=s;
                xia[name].pb(n);
                mx=max(mx,sz[s]);
            }
            sz[name]=mx;
            for(auto n:xia[name])
            {
                string tmp=name+"."+n;
                // cout<<n<<' '<<len[lx[n]]<<'\n';
                if(len[tylx[tmp]]%mx==0)sum+=mx;
                else sum+=mx;
            }
            len[name]=sum;
            cout<<sum<<' '<<mx<<'\n';
        }
        else if(op==2)
        {
            string type,name;
            cin>>type>>name;
            int m=sz[type];
            if(now%m!=0)now=now/m*m+m;
            lx[name]=type;
            if((int)xia[type].size()==0)
            {
                // cout<<"AAA\n";
                for(int i=now;i<now+len[type];i++)
                {
                    // cout<<"? "<<i<<' '<<name<<endl;
                    add[i]=name;
                }
            }
            else
            {
                // cout<<"BBB\n";
                int tmp=now;
                for(auto n:xia[type])
                {
                    string nn=name+"."+n;
                    string tms=type+"."+n;
                    string t=tylx[tms];
                    ans[nn]=tmp;
                    for(int i=tmp;i<tmp+len[t];i++)
                    {
                        // cout<<"? "<<i<<' '<<nn<<endl;
                        add[i]=nn;
                    }
                    tmp+=sz[type];
                }
            }
            cout<<now<<'\n';
            ans[name]=now;
            now+=len[type];
        }
        else if(op==3)
        {
            string name;
            cin>>name;
            cout<<ans[name]<<'\n';
        }
        else if(op==4)
        {
            int x;
            cin>>x;
            // cout<<add[x]<<'\n';
            if(add[x].length())
            {
                cout<<add[x]<<'\n';
            }
            else
            {
                cout<<"ERR\n";
            }
        }
    }
    return 0;
}
/*
6
1 node 4
byte a
short b
int c
long d
2 node beg
2 node b
2 byte q
4 64
4 63
*/