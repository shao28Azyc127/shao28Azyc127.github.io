#include<bits/stdc++.h>
#include<iostream>
#include<list>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<iomanip>
#include<deque>
using namespace std;
string a[1000000010];
int check(string s){
    switch(s[0]){
        case 'b':return 1;
        case 's':return 2;
        case 'i':return 4;
        case 'l':return 8;
    }
}
int n,e=0;
int main(){
    std::ios_base::sync_with_stdio(false);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            string s;
            int k;
            cin>>s>>k;
        }else if(op==2){
            string ti,ni;
            cin>>ti>>ni;
            cout<<e;
            int t1=check(ti)+e;
            for(;e<=t1;e++){
                a[e]=ni;
            }
        }else if(op==3){
            string s;
            for(int i=0;i<=e;i++){
                if(a[i]==s){
                    cout<<i;
                    break;
                }
            }
        }else{
            int addr;
            cin>>addr;
            if(a[addr]!=""){
                cout<<a[addr];
            }else{
                cout<<"ERR";
            }
        }
        cout<<endl;
    }
    return 0;
}
