#include <bits/stdc++.h>

using namespace std;
int n;
int flag[9][10][10][10][10][10];
int ans;
int t[6];
void lock(int num){
    for(int k=0;k<=9;k++){
        flag[num][(t[1])%10][(t[2])%10][(t[3])%10][(t[4])%10][(t[5]+k)%10]=true;
        flag[num][(t[1])%10][(t[2])%10][(t[3])%10][(t[4]+k)%10][(t[5]+k)%10]=true;

        flag[num][(t[1])%10][(t[2])%10][(t[3])%10][(t[4]+k)%10][(t[5])%10]=true;
        flag[num][(t[1])%10][(t[2])%10][(t[3]+k)%10][(t[4]+k)%10][(t[5])%10]=true;

        flag[num][(t[1])%10][(t[2])%10][(t[3]+k)%10][(t[4])%10][(t[5])%10]=true;
        flag[num][(t[1])%10][(t[2]+k)%10][(t[3]+k)%10][(t[4])%10][(t[5])%10]=true;

        flag[num][(t[1])%10][(t[2]+k)%10][(t[3])%10][(t[4])%10][(t[5])%10]=true;
        flag[num][(t[1]+k)%10][(t[2]+k)%10][(t[3])%10][(t[4])%10][(t[5])%10]=true;

        flag[num][(t[1]+k)%10][(t[2])%10][(t[3])%10][(t[4])%10][(t[5])%10]=true;
    }
    return;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>t[j];
        }
        lock(i);
    }
    for(int i=0;i<=99999;i++){
        t[1]=i/10000;
        t[2]=(i%10000)/1000;
        t[3]=(i%1000)/100;
        t[4]=(i%100)/10;
        t[5]=i%10;
        bool ansFlag=true;
        for(int j=1;j<=n;j++){
            if(!flag[j][t[1]][t[2]][t[3]][t[4]][t[5]]) ansFlag=false;
        }
        if(ansFlag){
            //cout<<i<<endl;
            ans++;
        }
    }
    cout<<ans-n <<endl;
    return 0;
}
