#include <bits/stdc++.h>
using namespace std;

int n;
string addr[80004];
string saddr[802];
int sl,l;
int cnt;
int len;
int offset;
string name;
string namelist[102];
string tempt[102];
string tempn[102];

map <string,int> typelen;
int main(){
    cout<<"ok\n";
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cout<<"ok\n";
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cout<<"ok\n";
    typelen["byte"]=1;
    cout<<"ok\n";
    typelen["short"]=2;
    typelen["int"]=4;
    typelen["long"]=8;
    cout<<"ok\n";
    cin>>n;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            cin>>name;
            int k;
            cin>>k;
                cout<<"ok\n";
            for(int j=1;j<=k;j++){
                string tn,tt;
                cout<<"ok\n";
                cin>>tt>>tn;
                cout<<"ok\n";
                if(sl){
                    for(;sl%typelen[tempt[j]];sl++){
                        cout<<sl<<endl;
                    }
                }
                cout<<"ok\n";
                for(int m=1;m<=typelen[tempt[j]];sl++){
                        cout<<sl<<" "<<tn<<endl;
                    //saddr[sl]=tn;
                }
                cout<<"ok\n";
                offset=max(offset,typelen[tempt[j]]);
            }
                cout<<"ok\n";
            for(;sl%offset;sl++){
                    cout<<sl;
            }
            cout<<sl<<" "<<offset<<endl;
        }
        if(op==2){

        }
        if(op==3){

        }
        if(op==4){

        }
    }
    return 0;
}
