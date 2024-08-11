#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#define int long long
#define ull unsigned long long
using namespace std;
int n;
struct node{
    int st;
    int type;//1:byte 2:short 3:int 4:long
};
map<string,node>mp;
int last;
map<int,string>mp1;
signed main(){
    ios::sync_with_stdio(false);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int opt;
        cin>>opt;
        if(opt==2){
            string a,b;
            cin>>a>>b;
            if(a=="byte"){
                int pos=last;
                mp[b].st=pos,mp[b].type=1;
                mp1[pos]=b;
                last=pos+1;
            }else if(a=="short"){
                int pos=last;
                while(pos%2!=0)pos++;
                mp1[pos]=mp1[pos+1]=b;
                mp[b].st=pos,mp[b].type=2;
                last=pos+2;
            }else if(a=="int"){
                int pos=last;
                while(pos%4!=0)pos++;
                mp1[pos]=mp1[pos+1]=mp1[pos+2]=mp1[pos+3]=b;
                mp[b].st=pos,mp[b].type=3;
            }else{
                int pos=last;
                while(pos%8!=0)pos++;
                mp1[pos]=mp1[pos+1]=mp1[pos+2]=mp1[pos+3]=mp1[pos+4]=mp1[pos+5]=mp1[pos+6]=mp1[pos+7]=b;
                mp[b].st=pos,mp[b].type=4;
            }
            cout<<mp[b].st<<endl;
        }else if(opt==3){
            string s;
            cin>>s;
            cout<<mp[s].st<<endl;
        }else{
            int addr;
            cin>>addr;
            if(mp1[addr]=="")cout<<"ERR"<<endl;
            else cout<<mp[mp1[addr]].st<<endl;
        }
    }
    return 0;
}
