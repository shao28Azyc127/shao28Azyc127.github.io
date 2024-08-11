#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> m;
long long cnt;
string a[1000000];
long long findspace(string type){
    if(type=="byte") return 1;
    else if(type=="short") return 2;
    else if(type=="int") return 4;
    else if(type=="long") return 8;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        switch(op){
            case 1:{
                int k;
                string s;
                string ty,na;
                cin>>k>>s;
                for(int i=1;i<=n;i++){
                    cin>>ty>>na;
                }

                break;
            }
            case 2:{
                string ty,na;
                cin>>ty>>na;
                int len=findspace(ty);
                while((cnt%len)!=0) cnt++;
                m[na]=cnt;
                for(int i=cnt;i<cnt+len;i++){
                    a[i]=na;
                }
                cout<<cnt<<endl;
                cnt+=len;
                break;
            }
            case 3:{
                string s;
                cin>>s;
                cout<<m[s]<<endl;
                break;
            }
            case 4:{
                long long addr;
                cin>>addr;
                if(a[addr]=="") cout<<"ERR"<<endl;
                else cout<<a[addr]<<endl;
                break;
            }

        }
    }
    return 0;
}
