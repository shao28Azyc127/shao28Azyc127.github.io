#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
const int maxn=15;
int n,a[maxn][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int tmp=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            bool flag=1;
            for(int k=1;k<=5;k++){
                if(a[i][k]!=a[j][k]){
                    flag=0;
                    break;
                }
            }
            if(flag) tmp++;
        }
    }
    n-=tmp;
    if(n==1){
        printf("81\n");
        return 0;
    }
    if(n==2){
        int k[10],cnt=0;
        for(int i=1;i<=5;i++){
            if(a[1][i]!=a[2][i]){
                k[++cnt]=i;
            }
        }
        if(cnt>=5){
            cout<<0<<endl;
            return 0;
        }
        if(cnt==1){
            if(k[1]==1 || k[1]==5) cout<<10<<endl;//8+2
            else cout<<12<<endl;//8+2+2
            return 0;
        }
        if(cnt==2){
            if(k[2]-k[1]!=1){//buxianglin
                cout<<2<<endl;
            }
            else{//xianglin
                if(a[1][k[1]]-a[2][k[1]]==a[1][k[2]]-a[2][k[2]]){//chaxiangdeng
                    cout<<10<<endl;//2+8
                }
                else{
                    cout<<2<<endl;
                }
            }
            return 0;
        }
        if(cnt==3){
            if(k[1]==1 && k[2]==3 && k[3]==5){
                cout<<0<<endl;
                return 0;
            }
            if(k[2]-k[1]==1 && k[3]-k[2]!=1){
                if(a[1][k[1]]-a[2][k[1]]==a[1][k[2]]-a[2][k[2]]) cout<<2<<endl;
                else cout<<0<<endl;
            }
            else if(k[2]-k[1]!=1 && k[3]-k[2]==1){
                if(a[1][k[2]]-a[2][k[2]]==a[1][k[3]]-a[2][k[3]]) cout<<2<<endl;
                else cout<<0<<endl;
            }
            else if(k[2]-k[1]==1 && k[3]-k[2]==1){
                int tmp=0;
                if(a[1][k[1]]-a[2][k[1]]==a[1][k[2]]-a[2][k[2]]) tmp+=2;
                if(a[1][k[2]]-a[2][k[2]]==a[1][k[3]]-a[2][k[3]]) tmp+=2;
                cout<<tmp<<endl;
            }
            return 0;
        }
        if(cnt==4){
            cout<<2<<endl;
            return 0;
        }
    }

    cout<<1<<endl;

    return 0;
}
