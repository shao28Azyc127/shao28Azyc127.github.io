#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
int n,cnt,tot;
long long addr=0;
map<string,long long> mp;
struct tp
{
    string pt,name;
};
struct node//cnt
{
    string name;
    int k,ma;
    vector<tp>v;
} no[105];
struct member//tot
{
    string ty_pe,na_me;
    long long stt,lst;
} me[105];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    mp["byte"]=1;
    mp["short"]=2;
    mp["int"]=4;
    mp["long"]=8;
    cin>>n;
    while(n--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            cnt++;
            cin>>no[cnt].name>>no[cnt].k;
            long long hole=0;
            for(int i=1;i<=no[cnt].k;i++)
            {
                string ti,ni;
                cin>>ti>>ni;
                hole=max(hole,mp[ti]);
                no[cnt].v.push_back(tp{ti,ni});
            }
            no[cnt].ma=hole;
            mp[no[cnt].name]=hole*no[cnt].k;
            cout<<hole*no[cnt].k<<" "<<hole<<endl;
        }
        else if(op==2)
        {
            cout<<addr<<endl;
            tot++;
            me[tot].stt=addr;
            string ti,ni;
            cin>>ti>>ni;
            mp[ni]=addr;
            addr+=mp[ti];
            me[tot].lst=addr-1;
            me[tot].ty_pe=ti;
            me[tot].na_me=ni;
            //cout<<addr<<endl;
        }
        else if(op==3)
        {
            //cout<<"IAKIOI!"<<endl;
            string s;
            cin>>s;
            string typ="",nam="",use;
            for(int i=0;i<=s.size()-1;i++)
            {
                if(s[i]=='.')
                {
                    typ=s.substr(0,i);
                    nam=s.substr(i+1);
                }
            }
            if(nam=="")
            {
                nam=s;
                cout<<mp[nam]<<endl;
            }
            else
            {
                bool flag=false;
                int ad=mp[typ];
                for(int i=1;i<=tot;i++)
                {
                    if(typ==me[i].na_me) use=me[i].ty_pe;
                }
                for(int i=1;i<=cnt;i++)
                {
                    if(no[i].name==use)
                    {
                        for(int j=0;j<no[i].k;j++)
                        {
                            if(nam!=no[i].v[j].name)
                            {
                                ad+=no[i].ma;
                            }
                            else
                            {
                                cout<<ad<<endl;
                                flag=true;
                                break;
                            }
                        }
                    }
                    if(flag) break;
                }
            }
        }
        else
        {
            bool flag=false;
            long long plc,cur;
            cin>>plc;
            for(int i=1;i<=tot;i++)
            {
                if(me[i].lst<plc) continue;
                if(me[i].ty_pe=="short"||me[i].ty_pe=="byte"||me[i].ty_pe=="int"||me[i].ty_pe=="long")
                {
                    cout<<me[i].na_me<<endl;
                    break;
                }
                cur=me[i].stt-1;
                for(int j=1;j<=cnt;j++)
                {
                    if(no[j].name==me[i].ty_pe)
                    {
                        for(int p=0;p<no[j].k;p++)
                        {
                            if(cur+no[j].ma<plc)
                            {
                                cur+=no[j].ma;
                                continue;
                            }
                            if(cur+mp[no[j].v[p].pt]<plc)
                            {
                                cout<<"ERR"<<endl;
                                flag=true;
                                break;
                            }
                            else
                            {
                                cout<<me[i].na_me<<"."<<no[j].v[p].name<<endl;
                                flag=true;
                                break;
                            }
                        }
                        if(flag) break;
                    }
                }
                if(flag) break;
            }
        }
    }
    return 0;
}
