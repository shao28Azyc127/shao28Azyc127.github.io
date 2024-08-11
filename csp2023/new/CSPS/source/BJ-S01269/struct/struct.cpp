#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct node{
    char ch;
    int han=0;
}s[10010];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,i,l=0,cnt=0;
    cin>>n;
    for(i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            int k;
            cin>>s[l++].ch>>k;
            int cnt=0;
            for(int j=1;j<=n;j++){
                char ti;
                string ni;
                cin>>ti>>ni;
                if(ti==int){
                    s[l].han+=4;
                    cout<<4*ni.length()<<"4";
                }
                if(ti==byte){
                    s[l].han+=1;
                    cout<<ni.length()<<"1";
                }
                if(ti==short){
                    s[l].han+=2;
                    cout<<2*ni.length()<<"2";
                }else{
                    s[l].han+=8;
                    cout<<8*ni.length()<<"8";
                }
            }
        }
        if(op==2){
            int t,he;
            cin>>t>>he;
            cout<<cnt;
            if(t==int){
                cnt+=4;
            }
            if(t==byte){
                cnt+=1;
            }
            if(t==short){
                cnt+=2;
            }
            if(t==longlong){
                cnt+=8;
            }
            for(i=1;i<=s;i++){
                if(t==s[i].ch){
                    cnt+=s[i].han;
                }
            }
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
