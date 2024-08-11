#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<unordered_map>

using namespace std;
typedef long long ll;

const int INF=0x3f3f3f3f;

struct Node1
{
    string s1, s2;
    ll siz, pos, real;
};

struct Node
{
    vector<Node1> a;
    unordered_map<string,string> mp1;
    ll siz, real;
};

vector<Node1> vec;
unordered_map<string,Node> mp;
int n;

int main()
{
    freopen("struct1.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    int last=0;
    while (n--)
    {
        int opt; cin>>opt;
        if (opt==1)
        {
            string s;
            int k;
            cin>>s>>k;
            ll start=0;
            ll maxn=0;
            while (k--)
            {
                string t1, t2;
                cin>>t1>>t2;
                int fby=0;
                if (t1=="byte")
                {
                    maxn=max(maxn,1ll);
                    fby=1;
                }
                else if (t1=="short")
                {
                    maxn=max(maxn,2ll);
                    start+=((2-start%2))%2;
                    fby=2;
                }
                else if (t1=="int")
                {
                    maxn=max(maxn,4ll);
                    start+=((4-start%4))%4;
                    fby=4;
                }
                else if (t1=="long")
                {
                    maxn=max(maxn,8ll);
                    start+=((8-start%8))%8;
                    fby=8;
                }
                else
                {
                    ll yu=mp[t1].siz;
                    maxn=max(maxn,yu);
                    start+=((yu-start%yu))%yu;
                    fby=mp[t1].real;
                }
                mp[s].a.push_back((Node1){t1,t2,maxn,start,fby});
                mp[s].mp1[t2]=t1;
                start+=fby;
            }
            mp[s].siz=maxn;
            cout<<start<<" "<<maxn<<endl;
            mp[s].real=start-1;
        }
        else if (opt==2)
        {
            string s1, s2;
            cin>>s1>>s2;
            ll t=0, real=0;
            if (s1=="byte") t=real=1;
            else if (s1=="short") t=real=2;
            else if (s1=="int") t=real=4;
            else if (s1=="long") t=real=8;
            else t=mp[s1].siz, real=mp[s1].real;
            last+=((t-last%t))%t;
            cout<<last<<endl;
            vec.push_back((Node1){s1,s2,t,last,real});
            last+=real;
        }
        else if (opt==3)
        {
            string s; cin>>s;
            string op; op.clear();
            ll ans=0;
            string fd="@";
            for (int i=0;i<(int)s.size();i++)
            {
                if (s[i]!='.') op+=s[i];
                else
                {
               //     cout<<"test "<<op<<endl;
                    if (fd=="@")
                    {
                        for (auto x:vec)
                        {
                            if (x.s2==op)
                            {
                                fd=x.s1;
                            //    cout<<"test "<<fd<<" "<<x.pos<<endl;
                                ans+=x.pos;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for (auto x:mp[fd].a)
                        {
                            if (x.s2==op)
                            {
                                fd=x.s1;
                             //   cout<<"test "<<fd<<" "<<x.pos<<endl;
                                break;
                            }
                        }
                    }
                    op.clear();
                }
            }
            //cout<<"fd "<<fd<<endl;
            for (auto x:mp[fd].a)
            {
                if (x.s2==op)
                {
                //    cout<<"test "<<x.pos<<endl;
                    ans+=x.pos;
                    break;
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            ll num; cin>>num;
            string res, op;
            int oppp=(int)vec.size();
            bool flag=true;
            for (int i=0;i<(int)vec.size()-1;i++)
            {
                if ((vec[i].pos<=num && vec[i+1].pos>num))
                {
                    cout<<"test "<<endl;
                    res+=vec[i].s2; res+='.';
                    num-=vec[i].pos;
                    op=vec[i].s1;
                    while (num)
                    {
                        for (int j=0;j<(int)mp[op].a.size();j++)
                        {
                            Node1 t=mp[op].a[j];
                            Node1 t1=mp[op].a[j+1];
                            if (t.pos<=num && t1.pos>num)
                            {
                                num-=t.pos;
                                op=t.s1;
                                res+=t.s2, res+='.';
                                break;
                            }
                        }
                    }
                    flag=false;
                    break;
                }
            }
            if (oppp==1)
            {
                int i=0;
                cout<<"test "<<endl;
                res+=vec[i].s2; res+='.';
                num-=vec[i].pos;
                op=vec[i].s1;
                while (num)
                {
                    for (int j=0;j<(int)mp[op].a.size()-1;j++)
                    {
                        Node1 t=mp[op].a[j];
                        Node1 t1=mp[op].a[j+1];
                        if (t.pos<=num && t1.pos>num)
                        {
                            num-=t.pos;
                            op=t.s1;
                            res+=t.s2, res+='.';
                            break;
                        }
                    }
                    if ((int)mp[op].a.size()==1)
                    {
                        Node1 t=mp[op].a[0];
                        num-=t.pos;
                            op=t.s1;
                            res+=t.s2, res+='.';
                    }
                }
                flag=false;
            }
            if ((int)mp[op].a.size()!=0) cout<<"EOF"<<endl;
            else cout<<res<<endl;
        }
    }
    return 0;
}
