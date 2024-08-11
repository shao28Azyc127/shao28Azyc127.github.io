#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<iomanip>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<cstring>
#include<climits>
#include<stack>
#include<queue>
using namespace std;
int n,op,k;
string s,t[101],na[101];
long long addr,ahah;
map<string,int> mp;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>s>>k;
            int aaa=0,bbb=0;
            for(int i=1;i<=k;i++)
            {
                cin>>t[i]>>na[i];
                if(t[i]=="short")
                {
                    aaa=max(aaa,2);
                    bbb+=2;
                }
                else if(t[i]=="int")
                {
                    bbb+=4;
                    aaa=max(aaa,4);
                }
                else if(t[i]=="long")
                {
                    bbb+=8;
                    aaa=max(aaa,8);
                }
                else if(t[i]=="byte")
                {
                    bbb++;
                    aaa=max(aaa,1);
                }
                else{
                    for(auto it=mp.begin();it!=mp.end();it++)
                    {
                        if(it->first==t[i])
                        {
                            aaa=max(aaa,it->second);
                            bbb+=it->second;
                        }
                    }
                }
            }
            cout<<((bbb+aaa-1)/aaa)*aaa<<' '<<aaa<<'\n';
            mp.insert(make_pair(s,((bbb+aaa-1)/aaa)*aaa));
        }
        if(op==2)
        {
            string tt,nn;
            cin>>tt>>nn;
            cout<<ahah<<'\n';
            ahah+=mp[tt];

        }
        if(op==3)
        {
            string sss;
            cin>>sss;
            cout<<0<<'\n';
        }
        if(op==4)
        {
            cout<<"ERR"<<'\n';
        }
    }
    return 0;
}
