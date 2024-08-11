#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
struct Struct_of_element {string type, name; LL rule; LL addr_begin, addr_end;};
vector<Struct_of_element> element;
LL last_addr_end=-1;

inline void Define_a_struct();

inline void Define_an_element()
{
    string t, n;
    cin>>t>>n;
    Struct_of_element temp_element;
    temp_element.type=t, temp_element.name=n;
    LL temp_rule;
    if (t=="byte") temp_element.rule=1;
    else if (t=="short") temp_element.rule=2;
    else if (t=="int") temp_element.rule=4;
    else if (t=="long") temp_element.rule=8;
    temp_element.addr_begin=(last_addr_end+temp_element.rule)/temp_element.rule*temp_element.rule;
    temp_element.addr_end=temp_element.addr_begin+temp_element.rule-1;
    last_addr_end=temp_element.addr_end;
    element.push_back(temp_element);
}

inline void Visit_an_element(string para_element_name)
{
    for (int i=1; i<element.size(); ++i) if (element[i].name==para_element_name) cout<<element[i].addr_begin<<endl;;
}

inline void Visit_an_addr(LL para_addr)
{
    for (int i=1; i<=element.size(); ++i) 
        if (element[i].addr_begin<=para_addr&&para_addr<=element[i].addr_end) {cout<<element[i].name<<endl; return;}
    cout<<"ERR"<<endl;
}

inline void Operate()
{
    cin>>n;
    Struct_of_element temp_element;
    element.push_back(temp_element);
    for (int i=1; i<=n; ++i)
    {
        int op;
        cin>>op;
        if (op==1) continue;
        else if (op==2) Define_an_element();
        else if (op==3)
        {
            string s;
            cin>>s;
            Visit_an_element(s);
        }
        else if (op==4)
        {
            LL addr;
            cin>>addr;
            Visit_an_addr(addr);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    Operate();
    return 0;
}