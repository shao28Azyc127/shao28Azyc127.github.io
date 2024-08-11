#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> map1;
map<string,vector<string> >bian;
map<string,vector<string> >second;
map<string,string> first;
map<string,int> maxsize;
unsigned long long addr[100010];
int cnt=1;
vector<string> addre;
map<string,unsigned long long> addres;
void build()
{
    map1["byte"]=1;
    map1["short"]=2;
    map1["int"]=4;
    map1["long"]=8;
}
long long get1(string s)
{
    return map1[s];
}
long long get2(string s)
{
    return maxsize[s];
}
long long get3(string s)
{
    return addres[s];
}
int main()
{
    //freopen("struct.in","r",stdin);
    //freopen("struct.out","w",stdout);
    cin>>n;
    build();
    for(unsigned int sx=1;sx<=n;sx++)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int k,mxsize=0;
            string a;cin>>a;
            scanf("%d",&k);
            for(int i=1;i<=k;i++)
            {
                string l,r;
                cin>>l>>r;
                mxsize=max(get1(l),mxsize);
                bain[a].push_back(l);
                bian1[a].push_back(r);
            }
            map1[a]=mxsize*k;
            maxsize[a]=mxsize;
            printf("%d %d\n",mxsize*k,mxsize);
        }
        if(op==2)
        {
            string t,s;
            cin>>t>>s;
            second[t].push_back(s);
            addr[cnt+1]=addr[cnt]+get1(t);
            addre.push_back(s);
            addres[s]=addr[cnt-1];
            cnt++;
            printf("%llu\n",addr[cnt-1]);
        }
        if(op==3)
        {
            string s;
            cin>>s;
            int len1=s.length();
            unsigned long long ad;
            string sss;
            for(int i=0;i<len1;i++)
            {
                string ss;
                while(s[i]!='.' && i<n)
                {
                    ss.push_back(s[i]);
                    i++;
                }
                if(i>=n) break;
                sss=ss;
            }
            ad=get3(ss);
            for(int i=0;i<bian[sss].size() && bian1[sss][i]!=ss;i++) 
            {
                ad+=get2(bian[sss][i]);
            }
            printf("%llu",ad);
        }
        if(op==4)
        {
            string 
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}