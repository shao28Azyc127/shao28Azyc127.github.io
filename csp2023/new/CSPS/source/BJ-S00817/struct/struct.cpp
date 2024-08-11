#include <bits/stdc++.h>
using namespace std;

void add(string &a, const string &b, const string &t)
{
    // a.resize(b.size()+1)
    int A = a.size(), T = t.size();
    a = b;
    for (int i = A - 1, j = T - 1; i >= 0 && j >= 0; --i, --j)
    {
        a[i] += t[j] ^ '0';
        if (a[i] > '9')
        {
            a[i] -= 10;
            ++a[i - 1];
        }
    }
}

void add(string &a, const string &t)
{
    a = "0" + a;
    int A = a.size(), T = t.size();
    for (int i = A - 1, j = T - 1; i >= 0 && j >= 0; --i, --j)
    {
        a[i] -= t[j] ^ '0';
        if (a[i] < '0')
        {
            a[i] += 10;
            --a[i - 1];
        }
    }
    a.erase(0, ans.find_first_not_of('0'));
}

void minus(string &a, const string &t)
{
    int A = a.size(), T = t.size();
    for (int i = A - 1, j = T - 1; i >= 0 && j >= 0; --i, --j)
    {
        a[i] -= t[j] ^ '0';
        if (a[i] < '0')
        {
            a[i] += 10;
            --a[i - 1];
        }
    }
    a.erase(0, a.find_first_not_of('0'));
}

void multi(string &x, string &y)
{
    string &a = x, &b = y;
    if (a.size() < b.size() || a.size() == b.size() && a < b)
        swap(a, b);
    const int p = a.size(), q = b.size();
    string z[10];
    z[1] = "0" + a;
    // cout << z[1] << '\n' << z[1].size() << ' ' << z[1] << '\n';
    for (int i = 2; i < 10; ++i)
    {
        z[i].resize(p + 1, '0');
        add(z[i], z[i - 1], a); 
        // cout << z[i] << '\n';
    }
    string ans(p + q, '0');
    for (int i = q - 1; i >= 0; --i)
    {
        // cout << ans << '\n';
        int k = b[i] ^ '0';
        if (k == 0)
            continue;
        for (int j = i + p; j >= i; --j)
        {
            ans[j] += z[k][j - i] ^ '0';
            if (ans[j] > '9')
            {
                ans[j] -= 10;
                ++ans[j - 1];
            }
        }
    }
    ans.erase(0, ans.find_first_not_of('0'));
    swap(x, ans);
}

void div(string &x, string &y)
{
    const int p = x.size(), q = y.size();
    string z(x.begin(), x.begin() + q);
    string ans;
    for (int i = q; i <= p; ++i)
    {
        char k = '0';
        while(z.size() > q || z.size()==q&&z>=y){
	    mus(z, y); ++k;
		}
		if(k!='0' || ans.size()) 
			ans.push_back(k);
		if(i!=p) z.push_back(x[i]);
    }
    swap(ans, x);
}


void mod(string &x, string &y)
{
    const int p = x.size(), q = y.size();
    string z(x.begin(), x.begin() + q);
    string ans;
    for (int i = q; i <= p; ++i)
    {
        char k = '0';
        while(z.size() > q || z.size()==q&&z>=y){
	    mus(z, y); ++k;
		}
		if(k!='0' || ans.size()) 
			ans.push_back(k);
		if(i!=p) z.push_back(x[i]);
    }
    swap(z, x);
}

void gcd(string &x, string& y){
if(y=="") return;
string &a = x, &b = y;
    if (a.size() < b.size() || a.size() == b.size() && a < b)
        swap(a, b);
        mod(a, b);
gcd(b,a);
}

unordered_map<string, int> type;
unordered_map<string, int> nm; // name
string sz[128];
string addr[128]; // start ptr

bool cmp(string x, string y){
return x.size()==y.size()?x<y:x.size()<y.size();}

struct O{
string addr[104];
int ch[104]; // name of child
int t[104]; // type of childs
int cnt = 0;
string K;

void addch(string k, string x){
t[cnt]=type[k];
ch[cnt]=x;
++cnt;
}
void check(){
K=sz[type[t[0]]];
for(int i=1;i<cnt;++i){
string tmp=sz[type[t[i]]];
K=gcd(K,tmp);
if(ans=="")
swap(K,tmp);
}
}
void addr(){
for(int i=0;i<cnt;++i){
addr[i]+=}
}
void find(string ptr){
int k=lower_bound(addr,addr+cnt,ptr);
}

}




























