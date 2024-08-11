#include<bits/stdc++.h>
using namespace std;
int n,s8;string s[100001];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    for(int i=1,op;i<=n;i++){
        scanf("%d",&op);
        if(op==2){
            string s1,s2;
            cin>>s1>>s2;
            if(s1=="int"){
                for(int i=s8;i<=s8+3;i++)s[i]=s2;
                s8+=4;
            }if(s1=="long"){
                for(int i=s8;i<=s8+7;i++)s[i]=s2;
                s8+=8;
            }if(s1=="short"){
                for(int i=s8;i<=s8+3;i++)s[i]=s2;
                s8+=2;
            }if(s1=="byte"){
                for(int i=s8;i<=s8;i++)s[i]=s2;
                s8+=1;
            }
        }if(op==3){
            string s1;cin>>s1;
            for(int i=0;i<s8;i++){
                    if(s[i]==s1){
                        cout<<i<<endl;
                        break;
                    }
            }
        }if(op==4){
            int addr;cin>>addr;
            cout<<s[addr]<<endl;
        }
    }
    return 0;
}
