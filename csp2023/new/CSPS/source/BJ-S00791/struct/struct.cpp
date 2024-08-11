#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll si(string s){
    switch(s[0]){
    case 'b':
        return 1;
    case 's':
        return 2;
    case 'i':
        return 4;
    case 'l':
        return 8;
    }
    return -114514;
}
int main()
{
    ll n,num=0,beg[105],siz[105];
    string name[105];
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll op;
        cin>>op;
        switch(op){
        case 2:{
            string t,n2;
            cin>>t>>n2;
            name[++num]=n2;
            siz[num]=si(t);
            if(i==1){
                beg[num]=0;
            }
            else{
                beg[num]=ceil((float)(beg[num-1]+siz[num-1])/(float)(siz[num]))*siz[num];
            }
            cout<<beg[num]<<endl;
            break;
        }
        case 3:{
            string s;
            cin>>s;
            for(ll i=1;i<=num;i++){
                if(name[i]==s){
                    cout<<beg[i]<<endl;
                }
            }
            break;
        }
        case 4:{
            ll addr;
            cin>>addr;
            if(addr>=beg[num]&&addr<beg[num]+siz[num]){
                cout<<name[num]<<endl;
            }
            if(addr>=beg[num]+siz[num]){
                cout<<"ERR"<<endl;
            }
            for(ll i=1;i<num;i++){
                if(addr>=beg[i]&&addr<beg[i]+siz[i]){
                    cout<<name[i]<<endl;
                }
                if(addr>=beg[i]+siz[i]&&addr<beg[i+1]){
                    cout<<"ERR"<<endl;
                }
            }
        }
        }
    }
    return 0;
}
