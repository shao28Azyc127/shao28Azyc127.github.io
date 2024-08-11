#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
map<string,int> sz;
map<string,string> mp;
map<string,int> mpid;
map<int,string>idmp;
map<int,bool> idmp_;
int siz,dq;
string S;
int N,id;
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sz["int"]=4;
    sz["long"]=8;
    sz["short"]=2;
    sz["byte"]=1;
    cin>>N;
    while(N--){
        int op;
        cin>>op;
        if(op==2){
            string t,n;
            cin>>t>>n;
            //cerr<<t<<" "<<n<<" "<<sz[t];
            if(id%sz[t]){
                id=id-(id%sz[t])+sz[t];
            }
            
            mp[n]=t;
            mpid[n]=id;
            for(int i=0;i<sz[t];i++){
                idmp[id+i]=n;
                idmp_[id+i]=1;
            }
            id+=sz[t];
        }
        if(op==3){
            string s;
            cin>>s;
            cout<<mpid[s]<<endl;
        }
        if(op==4){
            ll addr;
            cin>>addr;
            if(idmp_[addr])cout<<idmp[addr];
            else cout<<"ERR";
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}