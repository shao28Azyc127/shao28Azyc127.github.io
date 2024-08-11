#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
struct ty
{
    int siz,dq,sum=0;
    string cy_name[N],cy_ty[N];
};
map<string,ty> type;
map<string,int> c3;
map<int,string> c4;
int Nn,adrst=0;
void dfs(string t,string n)
{
    int xh=type[t].sum;
    int bq=type[t].dq;
    //ceil(1.0*tmp1/tmp3)*tmp3
    c3[n]=ceil(1.0*adrst/bq)*bq;
    if(xh==0)
    {
        int end1=ceil(1.0*adrst/bq)*bq+type[t].siz;
        for(int i=ceil(1.0*adrst/bq)*bq;i<end1;i++) c4[i]=n;
        //cout<<ceil(1.0*adrst/bq)*bq<<" "<<n<<endl;
        adrst=end1;
        adrst=ceil(1.0*adrst/bq)*bq;
        return ;
    }
    adrst=ceil(1.0*adrst/bq)*bq;
    for(int i=1;i<=xh;i++)
        dfs(type[t].cy_ty[i],n+"."+type[t].cy_name[i]);
    adrst=ceil(1.0*adrst/bq)*bq;
}
signed main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>Nn;
    type["byte"].siz=type["byte"].dq=1;
    type["short"].siz=type["short"].dq=2;
    type["int"].siz=type["int"].dq=4;
    type["long"].siz=type["long"].dq=8;
    while(Nn--)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            string s;
            int k;
            cin>>s;
            cin>>k;
            type[s].sum=k;
            int tmp1=0,tmp2=-1;
            for(int i=1;i<=k;i++)
            {
                string s1,s2;
                cin>>s1>>s2;
                type[s].cy_ty[i]=s1;
                type[s].cy_name[i]=s2;
                int tmp3=type[s1].dq;
                tmp1=ceil(1.0*tmp1/tmp3)*tmp3+type[s1].siz;
                tmp2=max(tmp2,type[s1].dq);
            }
            tmp1=ceil(1.0*tmp1/tmp2)*tmp2;
            type[s].siz=tmp1;
            type[s].dq=tmp2;
            cout<<tmp1<<" "<<tmp2<<"\n";
        }
        if(opt==2)
        {
            string t,n;
            cin>>t>>n;
            dfs(t,n);
            cout<<c3[n]<<"\n";
        }
        if(opt==3)
        {
            string s;
            cin>>s;
            cout<<c3[s]<<"\n";
        }
        if(opt==4)
        {
            int k;
            cin>>k;
            string s=c4[k];
            if(s=="") cout<<"ERR\n";
            else cout<<s<<"\n";
        }
    }
    return 0;
}
