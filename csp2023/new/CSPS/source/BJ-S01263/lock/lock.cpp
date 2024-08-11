#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)

int n;

struct Node
{
    int a[5];
    const int&operator[](const int&x)const
    {
        return a[x];
    }
    int&operator[](const int&x)
    {
        return a[x];
    }
    Node(int a=0,int b=0,int c=0,int d=0,int e=0)
    {
        this->a[0]=a;
        this->a[1]=b;
        this->a[2]=c;
        this->a[3]=d;
        this->a[4]=e;
    }
};

vector<Node> st;

vector<Node> get(Node x)
{
    vector<Node> s;
    rep (i,0,4)
    {
        rep (j,1,9) 
        {
            s.push_back(x);
            s.back()[i]=(s.back()[i]+j)%10;
        }
    }
    rep (i,0,3)
    {
        rep (j,1,9) 
        {
            s.push_back(x);
            s.back()[i]=(s.back()[i]+j)%10;
            s.back()[i+1]=(s.back()[i+1]+j)%10;
        }
    }
    return s;
}
bool e(Node a,Node b)
{
    bool f=true;
    rep (i,0,4) f&=a[i]==b[i];
    return f;
}

void merge(vector<Node> b)
{
    vector<Node> res;
    for (auto&x:st)
    {
        bool f=false;
        for (auto&y:b) f|=e(x,y);
        if (f) res.push_back(x);
    }
    st=res;
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    rep (i,1,n)
    {
        Node x;
        rep (j,0,4) cin>>x[j];
        if (i==1) st=get(x);//,print(st);
        else merge(get(x));
    }
    cout<<st.size();
    return 0;
}