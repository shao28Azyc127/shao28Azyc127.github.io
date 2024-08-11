#include <bits/stdc++.h>
#define int long long
#define N 110
using namespace std;
int n;
int cnt,cnte;
int sz[40000],aln[40000];
map<string,int>typn,elen;
struct Ele
{
    string name;
    int l,r,no,typ;
};
vector<Ele>ele(40000);
struct Stc
{
    int cnt,no;
    map<string,int>nm;
    vector<Ele>ele;
    void add(string t,string name)
    {
        nm.emplace(make_pair(name,cnt));
        ele.push_back({name,(sz[no]+aln[typn[t]]-1)/aln[typn[t]]*aln[typn[t]],0,cnt,typn[t]});
        aln[no]=max(aln[no],aln[typn[t]]);
        sz[no]=ele.back().l+sz[typn[t]];
        ele.back().r=sz[no];
        cnt++;
    }
};
Stc stc[N];
int top;
string fin;
inline string get_name(string x)
{
    string ret="";
    for(int i=0;i<x.length();i++)
    {
        if(x[i]=='.')break;
        ret.push_back(x[i]);
    }
    return ret;
}
inline string next_name(string x)
{
    int i=0;
    string ret="";
    for(;i<x.length();i++)
    {
        if(x[i]=='.')break;
    }
    for(i++;i<x.length();i++)
        ret.push_back(x[i]);
    return ret;
}
bool bin(int addr,vector<Ele>arr,bool f)
{
    int l=1,r=cnte,ret=0,mid;
    if(!f)
    {
        l=0;r=arr.size()-1;
    }
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(arr[mid].l<=addr)
        {
            ret=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    if(arr[ret].l<=addr&&arr[ret].r>addr)
    {
        if(arr[ret].typ<=4)
        {
            fin=arr[ret].name+"."+fin;
            return true;
        }
        else
        {
            if(bin(addr-arr[ret].l,stc[arr[ret].typ].ele,false))
            {
                fin=arr[ret].name+"."+fin;
                return true;
            }
            else return false;
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    cnt=4;
    sz[1]=1;sz[2]=2;sz[3]=4;sz[4]=8;
    aln[1]=1;aln[2]=2;aln[3]=4;aln[4]=8;
    typn.emplace(make_pair("byte",1));
    typn.emplace(make_pair("short",2));
    typn.emplace(make_pair("int",3));
    typn.emplace(make_pair("long",4));
    int op;
    for(int i=1;i<=n;i++)
    {
        cin>>op;
        if(op==1)
        {
            string name,typ;int k;
            cin>>name>>k;
            cnt++;
            typn.emplace(make_pair(name,cnt));
            stc[cnt].no=cnt;
            while(k--)
            {
                cin>>typ>>name;
                stc[cnt].add(typ,name);
            }
            sz[cnt]=(sz[cnt]+aln[cnt]-1)/aln[cnt]*aln[cnt];

            cout<<sz[cnt]<<" "<<aln[cnt]<<"\n";
        }else if(op==2)
        {
            string name,typ;
            cin>>typ>>name;
            cnte++;
            elen.emplace(make_pair(name,cnte));
            ele[cnte].name=name;
            ele[cnte].no=cnte;
            ele[cnte].typ=typn[typ];
            ele[cnte].l=(top+aln[typn[typ]]-1)/aln[typn[typ]]*aln[typn[typ]];
            ele[cnte].r=ele[cnte].l+sz[typn[typ]];
            top=ele[cnte].r;
            cout<<ele[cnte].l<<"\n";
        }else if(op==3)
        {
            string addr;
            cin>>addr;
            Ele&curr=ele[elen[get_name(addr)]];
            int pos=curr.l;
            addr=next_name(addr);
            if(curr.typ>4)
            {
                int ty=curr.typ;
                while(stc[ty].ele[stc[ty].nm[get_name(addr)]].typ>4)
                {
                    pos+=stc[ty].ele[stc[ty].nm[get_name(addr)]].l;
                    ty=stc[ty].ele[stc[ty].nm[get_name(addr)]].typ;
                    addr=next_name(addr);
                }
                pos+=stc[ty].ele[stc[ty].nm[get_name(addr)]].l;
                cout<<pos<<"\n";
            }
            else
            {
                cout<<curr.l<<"\n";
            }
        }else
        {
            int addr;
            cin>>addr;
            fin="";
            if(!bin(addr,ele,true))
                cout<<"ERR\n";
            else
            {
                for(int i=0;i<fin.length()-1;i++)
                    cout<<fin[i];
                cout<<"\n";
            }
        }
    }
    return 0;
}
