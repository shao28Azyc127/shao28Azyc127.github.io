#include<bits/stdc++.h>
using namespace std;
long long n,cz,sl,cnt,cx;
char nc[1000005];
string s;
struct x{
    string lx2;
    string mc2;
};
x b[100005];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>cz;
        if(cz==2){
            cnt++;
            cin>>b[cnt].lx2>>b[cnt].mc2;
            if(b[cnt].lx2=="byte") char[1]='b';
            if(b[cnt].lx2=="short") char[2]='s';
            if(b[cnt].lx2=="int") char[4]='i';
            if(b[cnt].lx2=="long") char[8]='l';
        }
        else if(cz==3){
            cin>>s;
            for(int i=1;i<=cnt;i++){
                if(b[cnt].mc2==s){
                    if(b[cnt].lx2=="byte") cout<<1<<endl;
                    if(b[cnt].lx2=="short") cout<<2<<endl;
                    if(b[cnt].lx2=="int") cout<<4<<endl;
                    if(b[cnt].lx2=="long") cout<<8<<endl;
                }
            }
        }
        else if(cz==4){
            cin>>cx;
            if(cx>=1&&cx<2){
                for(int i=1;i<=cnt;i++){
                    if(b[cnt].lx2=="byte"){
                        cout<<b[cnt].mc2<<endl;
                    }
                }
            }else if(cx<4){
                for(int i=1;i<=cnt;i++){
                    if(b[cnt].lx2=="short"){
                        cout<<b[cnt].mc2<<endl;
                    }
                }
            }else if(cx<8){
                for(int i=1;i<=cnt;i++){
                    if(b[cnt].lx2=="int"){
                        cout<<b[cnt].mc2<<endl;
                    }
                }
            }
            else {
                for(int i=1;i<=cnt;i++){
                    if(b[cnt].lx2=="long"){
                        cout<<b[cnt].mc2<<endl;
                    }
                }
            }
        }
    }
    return 0;
}