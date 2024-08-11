#include <bits/stdc++.h>
using namespace std;
unordered_map<string,long long> make;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    make["type"]=1,make["short"]=2,make["int"]=4,make["long"]=8;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int opt;cin>>opt;
        if(opt==4)cout<<"ERR\n";
        else if(opt==1){
            int k,maxx=-1;string s;
            cin>>k>>s;
            for(int i=1;i<=k;i++){
                cin>>s>>s1;
                maxx=max(maxx,make[s]);
            }
            cout<<k*maxx<<" "<<maxx<<"\n";
            
        }
    }
    return 0;
}
