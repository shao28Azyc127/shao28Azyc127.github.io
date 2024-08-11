#include<bits/stdc++.h>
using namespace std;
int n,now;
string p[10000010];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int zhi;
        cin>>zhi;
        if(zhi==2){
            string a,b;
            cin>>a>>b;
            if(a=="byte"){
                cout<<now<<endl;
                p[now]=b;
                now+=1;
            }
            if(a=="short"){
                if(now%2)now=now-now%2+2;
                cout<<now<<endl;
                p[now]=b;
                p[now+1]=b;
                now+=2;
            }
            if(a=="int"){
                if(now%4)now=now-now%4+4;
                cout<<now<<endl;
                p[now]=b;
                p[now+1]=b;
                p[now+2]=b;
                p[now+3]=b;
                now+=4;
            }
            if(a=="long"){
                if(now%2)now=now-now%8+8;
                cout<<now<<endl;
                p[now]=b;
                p[now+1]=b;
                p[now+2]=b;
                p[now+3]=b;
                p[now+4]=b;
                p[now+5]=b;
                p[now+6]=b;
                p[now+7]=b;
                now+=8;
            }
        }else if(zhi==3){
            string m;
            cin>>m;
            for(int i=0;i<=now;i++){
                if(p[i]==m){
                    cout<<i<<endl;
                    break;
                }
            }
        }else if(zhi==4){
            int m;
            cin>>m;
            if(p[m]=="")cout<<"ERR"<<endl;
            else cout<<p[m]<<endl;
        }
    }
    return 0;
}
