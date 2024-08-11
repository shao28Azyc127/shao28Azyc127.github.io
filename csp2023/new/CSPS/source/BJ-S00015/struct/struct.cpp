#include<bits/stdc++.h>
using namespace std;
int n,o,t,q;
char s[105][15],k[5],ss[15];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>o;
        if(o==2){
            t++;
            cin>>k;
            cin>>s[t];
            if(k[0]=='l'&&k[1]=='o'&&k[2]=='n'&&k[3]=='g'){
                cout<<t*8-8<<endl;
            }

        }else if(o==3){
            cin>>ss;
            for(int j=1;j<=t;j++){
                if(strcmp(s[j],ss)==0){
                    cout<<t*8-8<<endl;
                    break;
                }
            }
        }else{
            cin>>q;
            cout<<s[q/8+1]<<endl;
        }
    }
    return 0;
}
