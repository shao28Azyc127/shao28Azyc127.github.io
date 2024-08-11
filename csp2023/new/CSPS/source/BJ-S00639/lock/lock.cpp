#include <iostream>
#include <cstdio>
#include <cstring>
#include <random>
using namespace std;
int lock[9][6];
int same[9];
int n;
int make_par(int x1,int y1,int x2,int y2){
    int ans=0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
                for(int k=0;k<3;k++){
                    int
                    if(dx[k]==0){

                    }
                }
            /*if(((x1+i)%10==(x2+j)||(x1-i)%10==(x2+j)||(x1+i)%10==(x2-j))%10&&((y1+j)%10==(y2+j)%10||(x1-i)%10==(x2+j)||(x1+i)%10==(x2-j))){
                ans++;
                printf("%d %d %d %d\n",(x1-i)%10,(x2+j)%10,(y1+i)%10,(y2+j)%10);
            }*/
        }
    }
    return ans;
}
int look_4_1(){
    int sum=45;
    int tms=0;
    for(int i=1;i<=8;i++){
        if(same[i]){
            if(tms==0){
                sum=9;
                tms++;
            }
            else{
                sum=0;
            }
        }
    }
    return sum;
}
int look_4_2(){
    int sum=36;
    int tms1=0,tms2=0;
    for(int i=1;i<=8;i++){
        if(same[i]&&same[i-1]){
            //sum-=make_par()
        }
        else if(same[i]){
            if(tms2==0){

            }
        }
    }
    return sum;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n1=0,n2=0;
    scanf("%d",&n);
    memset(lock,-1,sizeof(lock));
    for(int j=1;j<=n;j++){
        for(int i=1;i<=5;i++){
            cin>>lock[j][i];
            if(lock[j][i]!=lock[j-1][i]){
                same[i]++;
            }
        }
    }
    cout<<make_par(5,5,5,1)<<endl;
    if(n==1){
        cout<<81;
        return 0;
    }
    n1=look_4_1();
    n2=0;
    cout<<n1+n2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
