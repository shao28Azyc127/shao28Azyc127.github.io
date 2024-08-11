#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=110;
string nms[N]; int ns;
struct S
{
    int id,a,tp[N],k,siz,p[N];
    string mem[N];
} s[N];
string nmf[N],ans;
int tp[N],pos[N],nf;
map<string,int> ids,idf;
int cal(int x,int &qwq,string y)
{
    // cout<<x<<" qwq "<<nms[x]<<" "<<y<<endl;//!!!
    for(int i=1;i<=s[x].k;i++)
    {
        if(s[x].mem[i]==y) 
        {
            // cout<<"!!"<<s[x].tp[i]<<" "<<s[x].p[i]<<endl; 
            qwq=s[x].tp[i]; return s[x].p[i];
        }
    }
    return -2434;
}
void ask(int x,int v)
{
    // cout<<x<<" qwq "<<v<<endl;//!!!
    if(x<=4)
    {
        if(v<=s[x].a) cout<<ans<<endl;
        else cout<<"ERR\n";
        return;
    }
    for(int i=s[x].k;i>=1;i--)
    {
        if(s[x].p[i]<=v) 
        {
            ans=ans+'.'+s[x].mem[i];
            ask(s[x].tp[i],v-s[x].p[i]); return;
        }
    }
    cout<<"ERR\n"; return;
}
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,op,k; cin>>n;
    string tmp,qry;
    nms[++ns]="byte",ids["byte"]=ns;
    s[ns].id=ns,s[ns].a=s[ns].siz=1;
    nms[++ns]="short",ids["short"]=ns;
    s[ns].id=ns,s[ns].a=s[ns].siz=2;
    nms[++ns]="int",ids["int"]=ns;
    s[ns].id=ns,s[ns].a=s[ns].siz=4;
    nms[++ns]="long",ids["long"]=ns;
    s[ns].id=ns,s[ns].a=s[ns].siz=8;
    while(n--)
    {
        cin>>op;
        if(op==1)
        {
            ns++,s[ns].id=ns,s[ns].a=s[ns].siz=0;
            cin>>nms[ns]>>s[ns].k; ids[nms[ns]]=ns;
            for(int j=1;j<=s[ns].k;j++)
            {
                cin>>tmp>>s[ns].mem[j];
                s[ns].tp[j]=ids[tmp],s[ns].a=max(s[ns].a,s[s[ns].tp[j]].a);
            }
            for(int j=1;j<=s[ns].k;j++)
            {
                if(s[ns].siz%s[s[ns].tp[j]].a)
                {
                    s[ns].siz+=s[s[ns].tp[j]].a-s[ns].siz%s[s[ns].tp[j]].a;
                    // cout<<s[ns].tp[j]<<" "<<s[ns].siz<<" "<<s[s[ns].tp[j]].a<<endl;
                }
                s[ns].p[j]=s[ns].siz,s[ns].siz+=s[s[ns].tp[j]].siz;
                // cout<<s[ns].tp[j]<<" qwq "<<s[s[ns].tp[j]].siz<<endl;
            }
            if(s[ns].siz%s[ns].a)
                s[ns].siz+=s[ns].a-s[ns].siz%s[ns].a;
            cout<<s[ns].siz<<" "<<s[ns].a<<endl;
        }
        if(op==2)
        {
            nf++; cin>>tmp>>nmf[nf];
            tp[nf]=ids[tmp],idf[nmf[nf]]=nf;
            pos[nf]=pos[nf-1]+s[tp[nf-1]].siz;
            // cout<<tp[nf-1]<<" qwq "<<nms[tp[nf-1]]<<endl;//!!!
            cout<<pos[nf]<<endl;
        }
        if(op==3)
        {
            cin>>qry; tmp.clear();
            k=qry.size(); 
            int res=-1,now=0;
            for(int i=0;i<k;i++)
            {
                if(qry[i]=='.') 
                {
                    if(res<0)
                    {
                        res=pos[idf[tmp]],now=tp[idf[tmp]];
                        // cout<<"qaq:"<<idf[tmp]<<" "<<tp[idf[tmp]]<<" "<<tmp<<endl;//
                    }
                    else res+=cal(now,now,tmp);
                    tmp.clear();
                }
                else tmp=tmp+qry[i];
            }
            if(res<0) res=pos[idf[tmp]],now=tp[idf[tmp]];
            else res+=cal(now,now,tmp);
            cout<<res<<endl;
        }   
        if(op==4)
        {
            int ad; cin>>ad;
            ans.clear();
            for(int i=nf;i>=1;i--)
            {
                if(ad>=pos[i]) 
                {
                    ans=nmf[i];
                    ask(tp[i],ad-pos[i]); break;
                }
            }
        }
    }
    return 0;
}