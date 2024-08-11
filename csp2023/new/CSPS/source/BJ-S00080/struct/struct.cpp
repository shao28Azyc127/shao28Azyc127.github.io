#include<iostream>
#include<cmath>
#include<vector>
#define int long long
using namespace std;
const int MAXN=105;
struct Stt
{
    string name;
    int s,a;
    int v[MAXN];
    int o[MAXN];
    string nn[MAXN];
    int cnt;
    Stt(){}
    Stt(string _name,int _s,int _a,int cntn)
    {
        name=_name;
        s=_s,a=_a;
        v[1]=cntn;
        cnt=1;
    }
}stt[MAXN];
struct Stk
{
    string name;
    int v;
    int o;
}stk[MAXN];
int cntn,cnts;
void add(int goal,int tmp)
{
    stt[goal].cnt++;
    int cnt=stt[goal].cnt;
    stt[goal].v[cnt]=tmp;
    stt[goal].a=max(stt[goal].a,stt[tmp].a);
    stt[goal].o[cnt]=ceil(1.0*(stt[goal].o[cnt-1]+stt[stt[goal].v[cnt-1]].s)/stt[tmp].a)*stt[tmp].a;
}
int f3(vector<string>v)
{
    int res=0;
    int tmp;
    for(int i=1;i<=cnts;i++)
        if(stk[i].name==v[0])
        {
            tmp=i;
            //cout<<"OK"<<endl;
            break;
        }
    res+=stk[tmp].o;
    tmp=stk[tmp].v;
    //cout<<tmp<<endl;
    //cout<<stt[stk[tmp].v].nn[1]<<endl;
    //cout<<res<<endl;
    //cout<<stk[tmp].name<<endl;
    for(int i=1;i<v.size();i++)
    {
        int ttmp;
        for(int j=1;j<=stt[tmp].cnt;j++)
        {
            //cout<<v[i]<<' '<<tmp<<' '<<stt[tmp].nn[j]<<endl;
            if(stt[tmp].nn[j]==v[i])
            {
                ttmp=j;
                break;
            }
        }
        //cout<<ttmp<<' '<<stt[tmp].o[ttmp]<<endl;
        res+=stt[tmp].o[ttmp];
        //cout<<res<<endl;
        tmp=stt[tmp].v[ttmp];
        //cout<<stt[tmp].nn[ttmp]<<endl;
    }
    return res;
}
int binary_search(int goal,int sum,int addr)
{
    int l=1,r=stt[goal].cnt;
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(sum+stt[goal].o[mid]<=addr)
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
string f4(int addr)
{
    int l=1,r=cnts;
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(stk[mid].o<=addr)
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    if(stk[ans].o+stt[stk[ans].v].s<addr) return "ERR";
    int tmp=stk[ans].v;
    int sum=stk[ans].o;
    string s=stk[ans].name;
    //cout<<s<<endl;
    while(true)
    {
        //cout<<sum<<' '<<tmp<<endl;
        if(sum+stt[tmp].s<=addr) return "ERR";
        if(tmp<=4)
        {
            if(s.size()==0) return "ERR";
            return s;
        }
        int ttmp=binary_search(tmp,sum,addr);
        //cout<<ttmp<<endl;
        s+='.'+stt[tmp].nn[ttmp];
        //cout<<s<<endl;
        sum+=stt[tmp].o[ttmp];
        tmp=stt[tmp].v[ttmp];
    }
    return "ERR";
}
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    //freopen("/home/noip02/CSP-S/struct3.in","r",stdin);
    //freopen("/home/noip02/CSP-S/struct3.out","w",stdout);
    stt[1]=Stt("byte",1,1,1);
    stt[2]=Stt("short",2,2,2);
    stt[3]=Stt("int",4,4,3);
    stt[4]=Stt("long",8,8,4);
    int n;
    cin>>n;
    cntn=4;
    cnts=0;
    for(int i=1;i<=n;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string s;
            int m;
            cin>>s>>m;
            cntn++;
            stt[cntn].name=s;
            for(int j=1;j<=m;j++)
            {
                string t,nn;
                cin>>t>>nn;
                int tmp;
                for(int k=1;k<cntn;k++)
                    if(stt[k].name==t)
                    {
                        tmp=k;
                        //cout<<tmp<<endl;
                        break;
                    }
                //cout<<"OK"<<endl;
                if(j==1)
                {
                    stt[cntn].v[++stt[cntn].cnt]=tmp;
                    stt[cntn].a=stt[tmp].a;
                    stt[cntn].cnt=1;
                }
                else add(cntn,tmp);
                stt[cntn].nn[j]=nn;
            }
            int cnt=stt[cntn].cnt;
            stt[cntn].s=ceil(1.0*(stt[cntn].o[cnt]+stt[stt[cntn].v[cnt]].s)/stt[cntn].a)*stt[cntn].a;
            cout<<stt[cntn].s<<' '<<stt[cntn].a<<endl;
            //cout<<stt[5].cnt<<' '<<stt[5].o[2]<<' '<<stt[5].nn[1]<<endl;
            //for(int j=1;j<=stt[6].cnt;j++) cout<<stt[6].nn[j]<<endl;
        }
        else if(op==2)
        {
            string t,nn;
            cin>>t>>nn;
            cnts++;
            int tmp;
            for(int j=1;j<=cntn;j++)
                if(stt[j].name==t)
                {
                    tmp=j;
                    break;
                }
            stk[cnts].v=tmp;
            if(cnts==1) stk[cnts].o=0;
            else stk[cnts].o=ceil(1.0*(stk[cnts-1].o+stt[stk[cnts-1].v].s)/stt[tmp].a)*stt[tmp].a;
            stk[cnts].name=nn;
            cout<<stk[cnts].o<<endl;
            //for(int j=1;j<=stt[tmp].cnt;j++) cout<<stt[tmp].o[j]<<' ';
            //cout<<endl;
        }
        else if(op==3)
        {
            string s;
            cin>>s;
            vector<string>v;
            int j=0;
            while(j<s.size())
            {
                v.push_back("");
                while(j<s.size()&&s[j]!='.')
                {
                    v[v.size()-1]+=s[j];
                    j++;
                }
                if(s[j]=='.') j++;
            }
            //for(string tmp:v) cout<<tmp<<endl;
            cout<<f3(v)<<endl;
        }
        else if(op==4)
        {
            int addr;
            cin>>addr;
            cout<<f4(addr)<<endl;
        }
    }
    return 0;
}