#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    int op;
    string A[114514];
    int st = 0;
    string ty;
    for(int p=0;p<n;p++){
        cin>>op;
        if(op==2){
            cin>>ty>>A[st];
            st++;
        }
        if(op==3){
            string a;
            cin>>a;
            int i=0;
            for(i=0;i<n&&A[i]!=a;){
                i++;
            }
            cout<<i*4;
        }
        if(op==4){
            int num;
            cin>>num;
            cout<<A[(num+1)/4-1];
        }
    }
    return 0;
}