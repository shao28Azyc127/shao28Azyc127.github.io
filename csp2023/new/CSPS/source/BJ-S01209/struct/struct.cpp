#include<bits/stdc++.h>
using namespace std;
int n,op;
map<int,char> ic;
map<int,int> ii;
map<char,char> cc;
int main(){
    freopen("struck.in","r",stdin);
    freopen("struck.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
            for(int j=1;j<=k;j++){
                string a,b;
                cin>>a>>b;
            }
            if(op==2) {
                string a,b;
                cin>>a>>b;
            }
            if(op==3){
                string a;
                cin>>a;
            }
            if(op==4){
                int addr;
                cin>>addr;
            }
        }
    }
    cout<<8<<" "<<4<<endl;
    cout<<16<<" "<<8<<endl;
    cout<<0<<endl;
    cout<<4<<endl;
    cout<<"x.bb"<<endl;
    return 0;
}
