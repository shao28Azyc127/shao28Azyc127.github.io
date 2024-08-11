#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int t;
map<string,int> le;
map<string,int> dq;
int l[109];
int r[109];
string na[109];
int inn;
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    le["int"]=4;
    dq["int"]=4;
    le["long"]=8;
    dq["long"]=8;
    le["short"]=2;
    dq["short"]=2;
    le["byte"]=1;
    dq["byte"]=1;
    cin>>n;
    l[0]=r[0]=-1;
    for(int i=1;i<=n;i++){
            cin>>t;
        if(t==1){
            int k;
        string s;
        cin>>s>>k;
        int dx,dd;
        dx=0;
        dd=0;
        for(int i=1;i<=k;i++){
            string a,b;
            cin>>a>>b;
            dx+=le[a];
            dd=max(dd,dq[a]);
        }
        dx=(dx/dd+(dx%dd?1:0))*dd;
        cout<<dx<<" "<<dd<<endl;
        le[s]=dx;
        dq[s]=dd;
        }else if(t==2){
            int rr;
            rr=r[inn]+1;
            inn++;
            string s;
            cin>>s;
            cin>>na[inn];
            l[inn]=(rr/dq[s]+(rr%dq[s]?1:0))*dq[s];
            r[inn]=l[inn]+le[s]-1;
            cout<<l[inn]<<endl;
        }else if(t==3){
            string s;
            cin>>s;
            for(int i=1;i<=inn;i++){
                if(na[i]==s){
                    cout<<l[i]<<endl;
                    break;
                }
            }
        }else{
            int ie;
            cin>>ie;
            bool fl;
            fl=0;
            for(int i=1;i<=inn;i++){
                if(l[i]<=ie&&ie<=r[i]){
                    cout<<na[i]<<endl;
                    fl=1;
                    break;
                }
            }
            if(!fl){
                cout<<"ERR"<<endl;
            }
        }
    }
    return 0;
}
