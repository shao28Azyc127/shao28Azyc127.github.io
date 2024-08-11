#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100+10;
struct elem
{
    string type;
    string name;
    ll pos,len,dq;
};
struct stct
{
    string name;
    ll num;
    vector<elem> member;
    ll len,dq;
};
vector<stct> jgt;
vector<elem> element;
ll newpos;
ll callen(string s)
{
    if(s=="byte")
        return 1;
    if(s=="short")
        return 2;
    if(s=="int")
        return 4;
    if(s=="long")
        return 8;
    for(ll i=0;i<jgt.size();i++)
    {
        if(s==jgt[i].name)
            return jgt[i].len;
    }
    return 0;
}
void test_callen()
{
    assert(callen("byte")==1);
    assert(callen("short")==2);
    assert(callen("int")==4);
    assert(callen("long")==8);
}
ll caldq(string s)
{
    if(s=="byte")
        return 1;
    if(s=="short")
        return 2;
    if(s=="int")
        return 4;
    if(s=="long")
        return 8;
    for(ll i=0;i<jgt.size();i++)
    {
        if(s==jgt[i].name)
            return jgt[i].dq;
    }
    return 0;
}
ll dodq(ll len,ll dq)
{
    //cout<<len<<" "<<dq<<endl;
    if(len%dq==0)
        return len;
    else
        return len/dq*dq+dq;
}
bool is_basic(string type)
{
    if(type=="byte" || type=="short" || type=="int" || type=="long")
        return 1;
    else
        return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ll n;
    cin>>n;
    while(n--)
    {
        ll op;
        cin>>op;
        if(op==1)
        {
            string s;
            ll k;
            cin>>s>>k;
            for(ll j=1;j<=k;j++)
            {
                string t,n;
                cin>>t>>n;
            }
        }
        else if(op==2)
        {
            string t,n;
            cin>>t>>n;
            ll tlen=callen(t),tdq=caldq(t);
            tlen=dodq(tlen,tdq);
            element.push_back({t,n,newpos,tlen,tdq});
            newpos=newpos+tlen;
            cout<<tlen<<" "<<tdq<<endl;
        }
        else if(op==3)
        {
            string s;
            cin>>s;
            ll nowpos=0;
            for(ll i=0;i<element.size();i++)
            {
                if(element[i].name==s)
                {
                    nowpos=element[i].pos;
                }
            }
            cout<<nowpos<<endl;
        }
        else
        {
            ll addr;
            cin>>addr;
            bool pd=0;
            for(ll i=0;i<element.size();i++)
            {
                if(element[i].pos>addr)
                {
                    pd=1;
                    cout<<element[i-1].name<<endl;
                    break;
                }
                else
                {
                    pd=1;
                }
            }
            if(element[(ll)element.size()-1].pos<=addr)
            {
                pd=1;
                cout<<element[(ll)element.size()-1].name<<endl;
            }
            if(!pd)
                cout<<"ERR"<<endl;
        }
    }
    return 0;
}
