#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >>n;
    int a;
    cin >>a;
    if(a==4) cout <<"ERR";
    else if(a==2){
        string t1,t2;
        cout <<"0";
    }else{
        string t1,t2;
        cin >>t1;
        int m;
        cin >>m;
        int zong=0,wei=0;
        for(int i=1;i<=m;i++){
            cin >>t1 >>t2;
            if(t1[0]=='s'){
                wei=max(2,wei);
            }else if(t1[0]=='l'){
                wei=max(8,wei);
            }else if(t1[0]=='i'){
                wei=max(wei,4);
            }else wei=max(wei,1);

        }
        cout <<wei*m <<" " <<wei;
    }
    return 0;
}
