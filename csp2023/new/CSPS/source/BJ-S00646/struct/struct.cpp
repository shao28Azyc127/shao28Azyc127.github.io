#include<bits/stdc++.h>
using namespace std;
long long N,opin,mmemory[10000000][8];
string name[100],aaa;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>N;
    while(N--){
        cin>>opin;
        if(opin==1){
            int p;
            cin>>aaa>>p;
            for(int i=1;i<=p;i++){
                cin>>name[i]>>name[i];
            }
            cout<<8*p<<" "<<8<<endl;
        }if(opin==2){
            int tmpp;
            string mmmm;
            cin>>mmmm;
            if(mmmm!="long") tmpp=32;
            for(int i=0;;i++){
                if(mmemory[i][3]!=2){
                        mmemory[i][3]=2;
                    if(tmpp==32){
                        
                        mmemory[i+1][3]=2;
                        mmemory[i+2][3]=2;
                        mmemory[i+3][3]=2;
                        cout<<i*8+4*8<<endl;
                    }else cout<<i*8<<endl;
                }
            }
        }
    }
}
