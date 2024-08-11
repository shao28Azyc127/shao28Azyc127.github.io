#include <iostream>
int shu[28],num[3010][3010];
char jiesh[3010];
using namespace std;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    int cnt;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=26;i++)
            shu[i]=0;
        for(int i=1;i<=m;i++)
            cin>>jiesh[i];
        for(int i=1;i<=m;i++)
            shu[jiesh[i]-'a'+1]++;
        cnt=1;
    //    cout<<k<<endl;
        for(int i=1;i<=26;i++){
            while(shu[i]!=0){
                shu[i]--;
                num[k][cnt++]=i;
         //       cout<<i<<" ";
            }
        }
    //    cout<<endl;
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        flag=true;
        for(int j=1;j<=n;j++){
            if(i==j)
                continue;
            for(int k=m;k>=1;k--){
                if(num[j][k]<num[i][m-k+1]){
                    flag=false;
                    break;
                }
                else if(num[j][k]>num[i][m-k+1])
                    break;
            }
            if(flag==false)
                break;
        }
        if(flag)
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}