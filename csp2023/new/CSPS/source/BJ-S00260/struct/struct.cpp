#include <bits/stdc++.h>
using namespace std;
long long pos;
struct segment
{
    string names;
    int strc;
    long long l,r;
};
vector<segment> seg;
struct strct
{
    string name;
    long long len=0;
    long long dem=0;
    vector<int> st;
    //vector<long long> de;
    //vector<long long> le;
    vector<string> na;
};
vector<strct> str;
void init()
{
    strct x;
    x.name="byte";
    x.len=x.dem=1;
    str.push_back(x);
    x.name="short";
    x.len=x.dem=2;
    str.push_back(x);
    x.name="int";
    x.len=x.dem=4;
    str.push_back(x);
    x.name="long";
    x.len=x.dem=8;
    str.push_back(x);
}
int finds(int l,int r,long long addr)
{
    if (l==r) return l;
    int mid=(l+r)/2;
    if (seg[mid].l<=addr&&addr<=seg[mid].r) return mid;
    else {
        if (seg[mid].r<mid) return finds(mid+1,r,addr);
        else return finds(l,mid,addr);
    }
}
signed main()
{
    freopen("struct.in","r",stdin);
    //freopen("struct.out","w",stdout);
    init();
    /*
    for (int i=0;i<str.size();i++){
        cout<<str[i].dem<<" "<<str[i].len<<" "<<str[i].name<<'\n';
    }
    */
    int n;
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if (op==1){
            strct x;
            string s;
            int k;
            cin>>s>>k;
            x.name=s;
            while (k--){
                string a,b;
                cin>>a>>b;
                x.na.push_back(b);
                for (int i=0;i<str.size();i++){
                    if (str[i].name!=a) continue;
                    //cout<<str[i].name<<'\n';
                    x.st.push_back(i);
                    x.dem=max(x.dem,str[i].dem);
                    //cout<<i<<" "<<x.dem<<'\n';
                    while (x.len%str[i].dem!=0) x.len++;
                    x.len+=str[i].len-1;
                    break;
                }
            }
            x.len++;
            str.push_back(x);
            cout<<x.len<<" "<<x.dem<<'\n';
        }
        else if (op==2){
            string a,b;
            cin>>a>>b;
            segment x;
            x.names=b;
            for (int i=0;i<str.size();i++){
                if(str[i].name!=a) continue;
                x.strc=i;
                while(pos%str[i].dem!=0) pos++;
                x.l=pos;
                pos+=str[i].len;
                x.r=pos;
                break;
            }
            seg.push_back(x);
            cout<<x.l<<'\n';
        }
        else if(op==3){
            string s;
            cin>>s;
            vector<string> ql;
            string x=" ";
            cout<<s<<'\n';
            int l=0;
            for (int i=0;i<s.size();i++){
                if (s[i]=='.'){
                    string y=s.substr(l,i-l);
                    ql.push_back(y);
                    l=i+1;
                }
            }
            string y=s.substr(l,s.size()-l);
            ql.push_back(y);
            /*
            int lj=0;
            for (int i=0;i<s.size();i++){
                cout<<s[i]<<" "<<lj<<" ";
                if (s[i]!='.') {
                    x[lj]=s[i];
                    lj++;
                }
                else {
                    lj=0;
                    ql.push_back(x);

                    x=" ";
                }
                cout<<x<<'\n';
            }
            for (int j=0;j<ql.size();j++) cout<<ql[j]<<" ";
            cout<<endl;
            */
            string que=ql[0];
            int ans=0;
            int t;
            for (int j=0;j<seg.size();j++) {
                if (seg[j].names!=que) continue;
                ans+=seg[j].l;
                t=seg[j].strc;
                break;
            }
            for (int i=1;i<ql.size();i++){
                que=ql[i];
                for (int j=0;j<str[t].na.size();j++) {
                    int r=str[t].st[j];
                    if (str[t].na[j]!=que){
                        while(ans%str[r].dem!=0) ans++;
                        ans+=str[r].len-1;

                    }
                    else{
                        while(ans%str[r].dem!=0) ans++;
                        t=r;
                        break;
                    }
                }
                //cout<<ans<<'\n';
            }
            cout<<ans<<'\n';
        }
        else{
            long long addr;
            cin>>addr;
            if (addr>800000) cout<<"ERR"<<'\n';
            else{
                int x=finds(0,seg.size()-1,addr);
                if (addr>seg[x].r||addr<seg[x].l) cout<<"ERR"<<'\n';
                else{
                    cout<<seg[x].names<<'\n';
                }
            }
        }
    }
    return 0;
}

