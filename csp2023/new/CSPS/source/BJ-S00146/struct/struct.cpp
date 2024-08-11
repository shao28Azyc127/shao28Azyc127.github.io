#include <bits/stdc++.h>
using namespace std;
vector <string> vc;
map<string,int> mp;
string a,b;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,op,x;
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        scanf("%d",&op);
        if (op==2){
            cin>>a>>b;
            vc.push_back(b); mp[b]=vc.size()-1;
            cout<<vc.size()*8-8<<endl;
        }
        else  if (op==3){
            cin>>a;
            cout<<mp[a]*8<<endl;
        }
        else{
            cin>>x;
            if (x/8<vc.size()) cout<<vc[x/8]<<endl;
            else cout<<"ERR"<<endl;
        }
    }
    return 0;
}
