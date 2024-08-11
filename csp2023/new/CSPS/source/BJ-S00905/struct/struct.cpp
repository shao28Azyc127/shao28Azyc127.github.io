#include<bits/stdc++.h>
using namespace std;
const int MXN=1e4+10;
map<string,int> mp1,mp2,mp3;
map<string,vector<string>> mp4;
int n,k,lst=0;
string add[MXN];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mp1["long"]=8;
    mp1["int"]=4;
    mp1["short"]=2;
    mp1["byte"]=1;
    cin>>n;
    int op,addr;
    string s,t,ln;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op==1){
            cin>>s>>k;
            int mx=0,sz=0,lsz;
            vector<string> lv;
            for(int j=1;j<=k;j++){
                cin>>t>>ln;
                lv.push_back(ln);
                lsz=mp1[t];
                sz+=lsz;
                mx=max(mx,lsz);
            }
            sz+=(mx-sz%mx)%mx;
            cout<<sz<<' '<<mx<<'\n';
            mp4[s]=lv;
            mp1[s]=sz;

        }else if(op==2){
            cin>>t>>ln;
            int sz=mp1[t];
            lst+=(sz-lst%sz)%sz;
            cout<<lst<<'\n';
            mp2[ln]=lst;
            for(int i=0;i<sz;i++){
                add[lst+i]=ln;
            }
            lst+=sz;
        }else if(op==3){
            cin>>s;
            cout<<mp2[s];
        }else{
            cin>>addr;
            if(add[addr]!=""){
                cout<<mp2[add[addr]]<<'\n';
            }else{
                cout<<"ERR"<<'\n';
            }
        }
    }
    return 0;
}