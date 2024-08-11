#include<bits/stdc++.h>
using namespace std;
int n,sum,zer1;//zero;
struct q{
    bool flag=0;
    char ch;
}str[2000010];
int z1(int q){
    int i=q,num=0;
    while(str[i].flag==0&&num<n){
        num++;
        i++;
        if(num==1&&str[i-1].ch==str[i-2].ch) return 0;
    }
    return num;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i].ch;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(str[i].ch==str[j].ch&&str[i].flag==0&&str[j].flag==0){
                str[i].flag=1;
                str[j].flag=1;
                sum++;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int j=z1(i);
        //cout<<j;
        if(j==n-i+1){
            zer1=0;
            break;
        }else if(j>1){
            //zero++;
            zer1++;
            i+=j;
        }
    }
    //cout<<zer1;
    if(sum==0){
        cout<<sum;
        return 0;
    }
    if(zer1==0||zer1==1){
        if(sum==1) cout<<sum;
        else cout<<sum+1;
        return 0;
    }

    return 0;
}
