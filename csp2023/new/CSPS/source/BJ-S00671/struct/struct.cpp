#include <bits/stdc++.h>
#define MAXN 1000
#define ll long long
#define db double
#define P 1000000007

using namespace std;

int n;
struct Mem{
    string name;
    ll addr;

};
vector<Mem> a;
ll num=0;

int main(){

    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    int n;
    cin>>n;
    while(n>0){
        int op;
        string kind,name;
        ll addr;
        cin>>op;
        if(op==2){
            cin>>kind>>name;
            Mem t;
            t.name=name;
            t.addr=num;
            if(kind=="byte") num+=1;
            else if(kind=="short") num+=2;
            else if(kind=="int") num+=4;
            else if(kind=="long") num+=8;
            a.push_back(t);
        }
        if(op==3){
            cin>>name;
            for(ll i=0;i<a.size();i++){
                if(a[i].name==name) {cout<<a[i].addr<<endl;break;}
            }
        }
        if(op==4){
            cin>>addr;
            ll i=0;
            while(a[i].addr<=addr&&i<a.size()) i++;
            cout<<a[i-1].name<<endl;
        }
        n--;
    }
    return 0;
}

