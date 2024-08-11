#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cassert>
using namespace std;
ifstream cin ("struct.in");
ofstream cout ("struct.out");
typedef long long i64;
struct Type
{
    i64 len=0;
    int yq;
    vector <string> tps;
    vector <string> ss;
    vector <i64> pos;
};

map <string,Type>ls; 
void insert (Type& T,string s,string t, bool f, bool op)
{
    Type tmp = ls[s];
    if (f)
    {
        T.len=0;
    }
    else if (T.len%tmp.yq)
    {
        T.len=T.len+tmp.yq-T.len%tmp.yq;
    }
    T.tps.push_back(s);
    T.ss.push_back(t);
    T.pos.push_back(T.len);
    assert (T.len%tmp.yq==0);
    if (op)
    {
        cout<<T.len<<"\n";
    }
    T.len+=tmp.len;
    T.yq=max(T.yq,tmp.yq);
}

i64 qry_s (Type& T,string s)
{
    int n=T.tps.size();
    if (n==0)
    {
        return 0;
    }
    if (s.size()==0)
    {
        return 0;
    }
    int w = s.find_first_of('.');
    string tmp = s.substr(0,w);
    // cerr<<tmp.size()<<" "<<tmp<<" "<<w<<endl;
    if (tmp.size()==0)
    {
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        if (T.ss[i]==tmp)
        {
            if (w==-1)
            {
                return T.pos[i];
            }
            return T.pos[i]+qry_s(ls[T.tps[i]],s.substr(w+1));
        }
    }
}

string qry_p (Type& T,i64 p)
{
    int n=T.tps.size();
    if (n==0)
    {
        return "";
    }
    for (int i=0;i<n;i++)
    {
        if (i==n-1 or p<T.pos[i+1])
        {
            if (p<T.pos[i]+ls[T.tps[i]].len)
            {
                string res = qry_p(ls[T.tps[i]],p-T.pos[i]);
                if (res.size()==0)
                {
                    return T.ss[i];
                }
                else if (res[0]=='E')
                {
                    return res;
                }
                else
                {
                    return T.ss[i]+'.'+res;
                }
            }
            else
            {
                return "ERR";
            }
        }
    }
    return "ERR";
}


void Insert (void)
{
    string name;
    cin>>name;
    int k;
    cin>>k;
    Type tt;
    tt.yq=0;
    for (int i=1;i<=k;i++)
    {
        string s,t;
        cin>>s>>t;
        insert(tt,s,t,i==1,0);
    }
    // cerr<<tt.len<<endl;
    if ((tt.len)%tt.yq!=0)
    {
        tt.len+=tt.yq-(tt.len)%tt.yq;
    }
    ls[name]=tt;
    cout<<tt.len<<" "<<tt.yq<<"\n";
    // cerr<<tt.len<<endl;
}

int main ()
{
    int n;
    cin>>n;
    Type tmp;
    tmp.len=tmp.yq=1;
    ls["byte"]=tmp;
    tmp.len=tmp.yq=2;
    ls["short"]=tmp;
    tmp.len=tmp.yq=4;
    ls["int"]=tmp;
    tmp.len=tmp.yq=8;
    ls["long"]=tmp;
    Type B;
    int cnt=0;
    while (n--)
    {
        int op;
        cin>>op;
        if (op==1)
        {
            Insert();
        }
        if (op==2)
        {
            string s,t;
            cin>>s>>t;
            insert(B,s,t,cnt==0,1);
            cnt++;
        }
        if (op==3)
        {
            string s;
            cin>>s;
            cout<<qry_s(B,s)<<'\n';
        }
        if (op==4)
        {
            i64 p;
            cin>>p;
            if (B.ss.size()==0)
            {
                cout<<"ERR\n";
            }
            else
            cout<<qry_p(B,p)<<'\n';
        }
    }
}