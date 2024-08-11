#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
int ans=0;
int num[10][10];

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>num[i][j];
        }
    }
    for(int num1=0;num1<=9;num1++){
        for(int num2=0;num2<=9;num2++){
            for(int num3=0;num3<=9;num3++){
                for(int num4=0;num4<=9;num4++){
                    for(int num5=0;num5<=9;num5++){
                        int tnum[10];
                        tnum[1]=num1;tnum[2]=num2;tnum[3]=num3;tnum[4]=num4;tnum[5]=num5;
                        bool flag=true;
                        for(int i=1;i<=n;i++){
                            int times;
                            int fudu;
                            int isfirst=false;
                            bool flag2=true;
                            bool isthesame=true;
                            int bq1pos;
                            int bigorsmall;//1:num[i][j]<tnum[j]  0:num[i][j]>tnum[j]
                            for(int j=1;j<=5;j++){

                                if(num[i][j]!=tnum[j]){
                                    isthesame=false;
                                    if(!isfirst){
                                        isfirst=true;
                                        bq1pos=j;
                                        times=1;
                                        if(num[i][j]>tnum[j]){
                                            bigorsmall=0;
                                            fudu=num[i][j]-tnum[j];
                                        }
                                        else{
                                            bigorsmall=1;
                                            fudu=tnum[j]-num[i][j];
                                        }
                                    }

                                    else if(times==1){
                                            if(bq1pos==j+1 || bq1pos==j-1){
                                                if(num[i][j]>tnum[j] && bigorsmall==0){
                                                    if(num[i][j]-tnum[j]!=fudu){
                                                        flag2=false;
                                                        break;
                                                    }
                                                    times++;
                                                }
                                            else if(num[i][j]<tnum[j] && bigorsmall==1){
                                                if(tnum[j]-num[i][j]!=fudu){
                                                    flag2=false;
                                                    break;
                                                }
                                                times++;
                                            }
                                            else if(tnum[j]<num[i][j] && bigorsmall==1){
                                                if(10-(num[i][j]-tnum[j])!=fudu){
                                                    flag2=false;
                                                    break;
                                                }
                                                times++;
                                            }
                                            else if(tnum[j]<num[i][j] && bigorsmall==0){
                                                if(10-(tnum[j]-num[i][j])!=fudu){
                                                    flag2=false;
                                                    break;
                                                }
                                                times++;
                                            }
                                            else{
                                                flag2=false;
                                                break;
                                            }
                                        }
                                        else{
                                            flag2=false;
                                            break;
                                        }
                                    }

                                    else{
                                        flag2=false;
                                        break;
                                    }
                                }
                            }
                            if(!flag2 || isthesame){
                                flag=false;
                                break;
                            }
                        }
                        if(flag){
                            ans++;
//                            cout<<tnum[1]<<tnum[2]<<tnum[3]<<tnum[4]<<tnum[5]<<endl;
                        }
                    }
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

