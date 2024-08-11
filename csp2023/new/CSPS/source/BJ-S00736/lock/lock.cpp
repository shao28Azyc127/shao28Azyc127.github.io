#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int all[N][6];
int a[10][6];
int num=0;
void init(){
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int r=0;r<=9;r++){
                        num++;
                        all[num][1]=i;
                        all[num][2]=j;
                        all[num][3]=k;
                        all[num][4]=l;
                        all[num][5]=r;
                    }
                }
            }
        }
    }
    return;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }
    int cnt=0,cnt1=0,cnt2=0;
    for(int i=1;i<=num;i++){
        int flag=0;
        for(int j=1;j<=n;j++){
            int tmp=0;
            int res=0;
            for(int k=1;k<=5;k++){
                if(all[i][k]!=a[j][k]){
                    res++;
                    tmp=k;
                }
            }
            if(res>2||res==0)flag=1;
            else if(res==2){
                if(all[i][tmp-1]<a[j][tmp-1])all[i][tmp-1]+=10;
                if(all[i][tmp]<a[j][tmp])all[i][tmp]+=10;
                if(all[i][tmp-1]-a[j][tmp-1]!=all[i][tmp]-a[j][tmp]){
                    flag=1;
                }
                /*else {
                    for(int k=1;k<=5;k++){
                        if(all[i][k]>=10){
                            cout<<all[i][k]-10<<" ";
                        }
                        else cout<<all[i][k]<<" ";
                    }
                    cout<<"\n";
                }*/
                if(all[i][tmp-1]>=10)all[i][tmp-1]-=10;
                if(all[i][tmp]>=10)all[i][tmp]-=10;
            }
        }
        if(flag==0){
            cnt++;
            //for(int k=1;k<=5;k++)cout<<all[i][k]<<" ";
            //cout<<"\n";
        }
    }
    //cout<<cnt1<<" "<<cnt2<<"\n";;
    cout<<cnt;
    return 0;
}
