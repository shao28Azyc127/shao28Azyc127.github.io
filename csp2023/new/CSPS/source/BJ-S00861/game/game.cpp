#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    for (int i=0;i<=n-1;i++){
        for (int j=2;i+j<=n;j+=2){
            string sub=s.substr(i,j);
            string p_sub=sub;
            int len=j;
            bool flag=0;
            for (int k=1;k<=j/2;k++){
                char last='/';
                bool flagin=0;
                int lastid=-1;
                for (int l=0;l<=j-1;l++){
                    if (sub[l]!=' '){
                        if (sub[l]!=last){
                            last=sub[l];
                            lastid=l;
                        }
                        else{
                            flagin=1;
                            len-=2;
                            sub[l]=' ';
                            sub[lastid]=' ';
                            last='/';
                        }
                    }
                }
                if (!flagin) break;
                if (len==0){
                    flag=1;
                    break;
                }
            }
            if (flag){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
