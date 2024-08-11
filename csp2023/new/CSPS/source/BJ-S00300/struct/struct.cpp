#include<iostream>
#include<map>
#include<cmath>
#include<unordered_map>
#include<algorithm>
using namespace std;
map<string,pair<int,int> > mp;
unordered_map<string,pair<string,int> > tp;
map<string,pair<int,int> > l;
map<string,int> dist,sz,st;
map<string,string> blg1,blg2;
string a[800009];
struct node
{
    int pos;
    string name1,name2;
}b[800009];
int n,m,i,j,k,cnt=1,addr;
bool cmp(node x,node y)
{
    return x.pos<y.pos;
}
int main()
{
    //freopen("struct.in","r",stdin);
    //freopen("struct.out","w",stdout);
    int t;
    cin>>t;
    st["byte"]=1;
    st["short"]=2;
    st["int"]=4;
    st["long"]=8;
    while(t--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string name;
            cin>>name>>n;
            int maxlen=0,len=0;
            for(i=cnt;i<=cnt+n-1;i++)
            {
                string type,nm;
                cin>>type>>nm;
                string allnm=name+"."+nm;
                tp[allnm]=make_pair(type,i-cnt+1);
                blg1[allnm]=nm;
                if(type=="byte") maxlen=max(maxlen,1),len++,dist[allnm]=len-1,sz[allnm]=len;
                if(type=="short") maxlen=max(maxlen,2),len=ceil(len*1.0/2)*2+2,dist[allnm]=len-2,sz[allnm]=len;
                if(type=="int") maxlen=max(maxlen,4),len=ceil(len*1.0/4)*4+4,dist[allnm]=len-4,sz[allnm]=len;
                if(type=="long") maxlen=max(maxlen,8),len=ceil(len*1.0/8)*8+8,dist[allnm]=len-8,sz[allnm]=len;
      //          cout<<dist[allnm]<<endl;
            }
            l[name]=make_pair(len,maxlen);
            cout<<len<<" "<<maxlen<<endl;
        }
        else if(op==2)
        {
            int tot=0;
            string type,name;
            cin>>type>>name;
            blg2[name]=type;
            addr=ceil(addr*1.0/l[type].second)*l[type].second;
            mp[name].first=addr;
            cout<<addr<<endl;
            for(auto &it:tp)
            {
                string t=it.first;
                int sz=t.size();
                string lnm="",fnm="";
                bool flg=1;
                for(i=0;i<sz;i++)
                    if(t[i]=='.') flg=0;
                    else if(flg) fnm+=t[i];
                    else if(!flg) lnm+=t[i];
                if(fnm==type) b[++tot]={it.second.second,name+"."+lnm,it.first};
            }
            sort(b+1,b+tot+1,cmp);
        //    cout<<addr<<endl;
            for(i=1;i<=tot;i++)
            {
                for(j=ceil(addr*1.0/st[tp[b[i].name2].first])*st[tp[b[i].name2].first];j<=addr+sz[b[i].name2]-sz[b[i-1].name2]-1;j++) a[j]=b[i].name1;
                addr+=dist[b[i].name2];
            }
          //  addr+=l[type].first;
            mp[name].second=addr;
        }
        else if(op==3)
        {
            string name;
            cin>>name;
            int l=name.size();
            string fnm="",lnm="";
            bool flg=1;
            for(i=0;i<l;i++)
                if(name[i]=='.') flg=0;
                else if(flg==1) fnm+=name[i];
                else lnm+=name[i];
            cout<<mp[blg1[blg2[fnm]]].first+sz[blg2[fnm]+"."+lnm]<<endl;
        }
        else
        {
            int pos;
            cin>>pos;
            if(a[pos]=="") puts("ERR");
            else cout<<a[pos]<<endl;
        }
    }
    return 0;
}
//hornex&Zert bless me AC