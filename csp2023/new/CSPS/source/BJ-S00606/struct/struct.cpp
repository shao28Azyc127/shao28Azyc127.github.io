#include<bits/stdc++.h>
using namespace std;
const long long RP=1e18+7,rp=1e18+7,Rp=1e18+7,rP=1e18+7;
struct node{
    string s;
    int meme;
};
int n,cur,cnt;
node s[101];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==2){
            string t,T;
            cin>>t>>T;
            cnt++;
            s[cnt].s=T;
            s[cnt].meme=cur;
            cout<<cur<<endl;
            cur+=8;
        }if(op==3){
            string q;
            cin>>q;
            for(int i=1;i<=cnt;i++){
                if(s[i].s==q){
                    cout<<s[i].meme<<endl;
                    break;
                }
            }
        }if(op==4){
            int tmp;
            cin>>tmp;
            for(int i=1;i<=cnt;i++){
                if(((tmp)-(s[i].meme/8)*8)<8){
                    cout<<s[i].s<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}//All hail the great god of the sky Zeus!
//IAKIOI
//GREAT RDFZ YYDS
//GREAT XXX YYDS