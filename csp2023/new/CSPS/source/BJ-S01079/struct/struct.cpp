#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=300;
int n,k,op;
struct strc{
    int k,a[N],siz,mx;
    string ele[N];
};
map<string,strc> mp1;
ll ptr,addr;
string s,type,name;
map<string,ll> mp3;
map<ll,string> mp4;

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>op;
        if(op==1){
            cin>>s>>k;
            strc tmp;
            tmp.siz=tmp.mx=0;
            tmp.k=k;
            for(int i=1;i<=k;i++){
                cin>>type>>name;
                tmp.ele[i]=name;
                if(type=="byte"){
                    tmp.a[i]=1;
                    ++tmp.siz;
                }
                else if(type=="short"){
                    while(tmp.siz%2)++tmp.siz;
                    tmp.siz+=2;
                    tmp.a[i]=2;
                }
                else if(type=="int"){
                    while(tmp.siz%4)++tmp.siz;
                    tmp.siz+=4;
                    tmp.a[i]=4;
                }
                else{
                    while(tmp.siz%8)++tmp.siz;
                    tmp.siz+=8;
                    tmp.a[i]=8;
                }
                tmp.mx=max(tmp.mx,tmp.a[i]);
            }
            while(tmp.siz%tmp.mx)tmp.siz++;
            cout<<tmp.siz<<' '<<tmp.mx<<endl;
            mp1[s]=tmp;
//            for(int i=1;i<=k;i++)cout<<tmp.m[tmp.ele[i]]<<' ';
        }
        else if(op==2){
            cin>>type>>name;
            if(type=="byte"){
                cout<<ptr<<endl;
                mp3[name]=ptr;
                mp4[ptr++]=name;
            }
            else if(type=="short"){
                while(ptr%2)++ptr;
                cout<<ptr<<endl;
                mp3[name]=ptr;
                for(int i=0;i<2;i++)mp4[ptr+i]=name;
                ptr+=2;
            }
            else if(type=="int"){
                while(ptr%4)++ptr;
                cout<<ptr<<endl;
                mp3[name]=ptr;
                for(int i=0;i<4;i++)mp4[ptr+i]=name;
                ptr+=4;
            }
            else if(type=="long"){
                while(ptr%8)++ptr;
                cout<<ptr<<endl;
                mp3[name]=ptr;
                for(int i=0;i<8;i++)mp4[ptr+i]=name;
                ptr+=8;
            }
            else{
                strc tt=mp1[type];
                while(ptr%tt.mx)++ptr;
                cout<<ptr<<endl;
                int cpy=ptr;
                for(int i=1;i<=k;i++){
                    while(cpy%tt.a[i])++cpy;
                    mp3[name+"."+tt.ele[i]]=cpy;
                    for(int j=0;j<tt.a[i];j++)mp4[cpy+j]=name+"."+tt.ele[i];
                    cpy+=tt.a[i];
                }
                ptr+=tt.siz;
            }
        }
        else if(op==3){
            cin>>name;
            cout<<mp3[name]<<endl;
        }
        else{
            cin>>addr;
            if(mp4[addr]!="")cout<<mp4[addr]<<endl;
            else cout<<"ERR"<<endl;
        }
    }
//    for(int i=0;i<50;i++)if(mp4[i]!="")cout<<mp4[i]<<' ';
//    else cout<<"#";
    return 0;
}
