#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ns,op,k,tmp=0,addr,nowlen=0;
string s,t,n;
struct node
{
    ll id,need,space;
};
struct node2
{
    ll stlen,type;
};
struct node3
{
    string name;
    int space;
};
map<string,node> mp;
map<string,node2> lei;
vector<node3> v[110];
map<string,string> backs;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>ns;
    mp["byte"].need=1;
    mp["short"].need=2;
    mp["int"].need=4;
    mp["long"].need=8;
    while(ns--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>s>>k;
            tmp++;
            mp[s].id=tmp;
            for(int i=1;i<=k;i++)
            {
                cin>>t>>n;
                mp[s].need=max(mp[s].need,mp[t].need);
                v[tmp].push_back(node3{n,mp[t].need});
            }
            mp[s].space=mp[s].need*k;
            cout<<mp[s].space<<" "<<mp[s].need<<endl;
        }
        if(op==2)
        {
            cin>>t>>n;
            backs[n]=t;
            lei[n].type=mp[t].id;
            lei[n].stlen=nowlen;
            cout<<nowlen<<endl;
            nowlen+=mp[t].space;
        }
        if(op==3)
        {
            cin>>s;
            string t,frontt;int ans,flagf;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!='.') t+=s[i];
                else
                {
           //         cout<<t<<":";
                    if(flagf==false)
                    {
                        flagf=true;
                        ans=lei[t].stlen;
                        frontt=t;
                        t="";
                        continue;
                    }
             //       cout<<","<<v[2].size();
             //       cout<<mp[backs[frontt]].id<<endl;
                    for(int i=0;i<v[mp[backs[frontt]].id].size();i++)
                    {
             //           cout<<v[mp[backs[frontt]].id][i].name<<endl;
                        if(v[mp[backs[frontt]].id][i].name==t) break;
                        else ans+=mp[backs[frontt]].need;
               //         cout<<","<<ans<<endl;
                    }
             //       cout<<endl;
                    frontt=t;
                    t="";
                }
            }
//            cout<<frontt<<" "<<t<<endl;
                    for(int i=0;i<v[mp[backs[frontt]].id].size();i++)
                    {
     //                   cout<<v[mp[backs[frontt]].id][i].name<<endl;
                        if(v[mp[backs[frontt]].id][i].name==t)
                        {
  //                          cout<<"yes";
                            break;
                        }
                        else ans+=mp[backs[frontt]].need;
    //                    cout<<ans<<endl;
                    }
//            cout<<endl;
            cout<<ans<<endl;
        }
        if(op==4)
        {
            cout<<"ERR"<<endl;
        }
    }
    return 0;
}
