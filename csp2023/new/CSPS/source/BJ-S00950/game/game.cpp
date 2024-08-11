// op required
#include <iostream>
#include <cstdio>
#include <string>
#pragma GCC optimize(3)
using namespace std;
const int N=2e6+5;
int n,ans;
char ord[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j+=2){
            // string tmp1=s.substr(i,(i+j)/2-i+1);
            // string tmp2=s.substr((i+j)/2+1,j-(i+j)/2);
            // string tmp3;
            // for(int k=tmp2.length()-1;k>=0;k--){
            //     tmp3.push_back(tmp2[k]);
            // }
            // // cout<<tmp3<<endl;
            // if(tmp1==tmp3) cout<<tmp1<<endl,ans++;
            int a=i,b=j;
            string tmp=s.substr(i,j-i+1);
            while(a<b){
                bool fl=0;
                for(int k=0;k<tmp.length();k++){
                    if(tmp[k]==tmp[k+1]) fl=1,tmp.erase(tmp.begin()+k),tmp.erase(tmp.begin()+k),b-=2;
                }
                if(!fl) break;
            }
            if(tmp.size()==0) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}