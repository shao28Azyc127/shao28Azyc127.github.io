#include<iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
//#define ll long long
using namespace std;
struct Cy{
    int l;
    string mz;
    int mal;
};
struct qiantaodz{
    string jg,ys;
};
//1==byte 2=short 4=int 8=long
Cy v[105][105];
long long nn,jq[105];
map<string,long long> ys;
qiantaodz dz[10000005];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>nn;
    for(int i=1,cnt=0,cntj=0;i<=nn;i++){
        int op;
        cin>>op;
        //cout<<op<<' ';
        if(op==1){
            int maxdz=-1e9;
            cin>>v[cntj][0].mz>>v[cntj][0].l;
            for(int i=1;i<=v[cntj][0].l;i++){
                string t;
                cin>>t;
                if(t=="byte"){
                    v[cntj][i].l=1;
                    cin>>v[cntj][i].mz;
                    maxdz=max(maxdz,v[cntj][i].l);
                }
                if(t=="short"){
                    v[cntj][i].l=2;
                    cin>>v[cntj][i].mz;
                    maxdz=max(maxdz,v[cntj][i].l);
                }
                if(t=="int"){
                    v[cntj][i].l=4;
                    cin>>v[cntj][i].mz;
                    maxdz=max(maxdz,v[cntj][i].l);
                }
                if(t=="long"){
                    v[cntj][i].l=8;
                    cin>>v[cntj][i].mz;
                    maxdz=max(maxdz,v[cntj][i].l);
                }
            }
            v[cntj][0].mal=maxdz;
            //for(int i=1;i<=v[cntj][0].l;i++){
            //    v[cntj][i],l=maxdz;
            //}
            cout<<maxdz*v[cntj][0].l<<' '<<maxdz<<endl;
            cntj++;
        }
        if(op==2){
            string t,n;
            cin>>t>>n;
            cout<<cnt<<endl;
            for(int i=0;i<cntj;i++){
                if(t==v[i][0].mz){
                    for(int j=1;j<=v[i][0].l;j++){
                        int ma=v[i][0].mal;
                        if(cnt%ma!=0){
                            cnt=cnt+(ma-cnt%ma);
                        }
                        ys[v[i][j].mz]=cnt;
                        for(int i=cnt;i<=cnt+ma-1;i++){
                            dz[i].ys=v[i][j].mz;
                            dz[i].jg=v[i][0].mz;
                        }cnt+=ma;
                    }
                    break;
                }
            }
            if(t=="byte"){
                ys[n]=cnt;
                dz[cnt].ys=n;
                cnt++;
            }
            if(t=="short"){
                if(cnt%2!=0){
                    cnt=cnt+(2-cnt%2);
                }
                ys[n]=cnt;
                for(int i=cnt;i<=cnt+1;i++){
                    dz[i].ys=n;
                }cnt+=2;
            }
            if(t=="int"){
                if(cnt%4!=0){
                    cnt=cnt+(4-cnt%4);
                }
                ys[n]=cnt;
                for(int i=cnt;i<=cnt+3;i++){
                    dz[i].ys=n;
                }cnt+=4;
            }
            if(t=="long"){
                if(cnt%8!=0){
                    cnt=cnt+(8-cnt%8);
                }
                ys[n]=cnt;
                for(int i=cnt;i<=cnt+7;i++){
                    dz[i].ys=n;
                }cnt+=8;
            }
        }
        if(op==3){
            string s;
            cin>>s;
            long long d=-1;
            for(int i=0;i<s.size();i++){
                if(s[i]=='.'){
                    d=i;
                }
            }if(d==-1){
                cout<<ys[s]<<endl;
            }else{
                string s2="";
                for(int i=d;i<s.size();i++){
                    s2+=s[i];
                }
                cout<<ys[s2]<<endl;
            }
        }
        if(op==4){
            long long addr;
            cin>>addr;
            if(dz[addr].ys==""){
                cout<<"ERR"<<endl;
                continue;
            }
            for(int i=addr;;i--){
                if(dz[i].ys!=dz[i-1].ys){
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
