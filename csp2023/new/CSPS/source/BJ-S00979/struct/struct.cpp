#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define _for1(i,a,b) for(int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
typedef pair<string,string> pii;
const int maxn=100;
int n,op;
string s;
vector<pii> m[maxn];
map<string,int> G,start;
int Mansiz=1,star=0;
int cnt=0;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    G["byte"]=1;
    G["short"]=2;
    G["int"]=4;
    G["long"]=8;
    int Maxsize=1;
    _for(i,1,n)
    {
        cin>>op;
        if(op==1)
        {
            int k;
            cin>>k;
            cin>>s;
            cnt++;
            int maxsize=1;
            _for(i,1,k)
            {
                string t,st;
                cin>>t>>st;
                m[cnt].push_back(make_pair(t,st));
                maxsize=max(maxsize,G[t]);
            }
            cout<<maxsize*k<<' '<<maxsize<<endl;
            G[s]=maxsize*k;
            Maxsize=max(Maxsize,maxsize);
        }
        if(op==2)
        {
            string st;
            cin>>s>>st;
            cout<<star;
            star+=Maxsize;
        }
        if(op==3)
        {
            cin>>s;
            int i=0;
            string s2="";
            while(s[i]!=".")
            {
                i++,s2+=s[i];
            }
            int x=G[s2];

        }
    }
    return 0;
}
