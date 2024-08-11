#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n;
int a[10][N];
int ans;
int g[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }
    for(int i1=0;i1<=9;i1++){
        for(int i2=0;i2<=9;i2++){
            for(int i3=0;i3<=9;i3++){
                for(int i4=0;i4<=9;i4++){
                    for(int i5=0;i5<=9;i5++){
                        bool b=1;
                        for(int i=1;i<=n;i++){
                            int zhuan=-1;
                            memset(g,0,sizeof(g));
                            int cnt=0;
                            if(a[i][1]!=i1){
                                g[1]=1;
                                cnt++;
                                int bu=a[i][1]-i1;
                                if(bu<0){
                                    bu+=10;
                                }
                                if(zhuan==-1){
                                    zhuan=bu;
                                }
                                else{
                                    if(zhuan!=bu){
                                        b=0;
                                        break;
                                    }
                                }
                            }
                            if(a[i][2]!=i2){
                                g[2]=1;
                                cnt++;
                                int bu=a[i][2]-i2;
                                if(bu<0){
                                    bu+=10;
                                }
                                if(zhuan==-1){
                                    zhuan=bu;
                                }
                                else{
                                    if(zhuan!=bu){
                                        b=0;
                                        break;
                                    }
                                }
                            }
                            if(a[i][3]!=i3){
                                g[3]=1;
                                cnt++;
                                int bu=a[i][3]-i3;
                                if(bu<0){
                                    bu+=10;
                                }
                                if(zhuan==-1){
                                    zhuan=bu;
                                }
                                else{
                                    if(zhuan!=bu){
                                        b=0;
                                        break;
                                    }
                                }
                            }
                            if(a[i][4]!=i4){
                                g[4]=1;
                                cnt++;
                                int bu=a[i][4]-i4;
                                if(bu<0){
                                    bu+=10;
                                }
                                if(zhuan==-1){
                                    zhuan=bu;
                                }
                                else{
                                    if(zhuan!=bu){
                                        b=0;
                                        break;
                                    }
                                }
                            }
                            if(a[i][5]!=i5){
                                g[5]=1;
                                cnt++;
                                int bu=a[i][5]-i5;
                                if(bu<0){
                                    bu+=10;
                                }
                                if(zhuan==-1){
                                    zhuan=bu;
                                }
                                else{
                                    if(zhuan!=bu){
                                        b=0;
                                        break;
                                    }
                                }
                            }
                            if(cnt>2){
                                b=0;
                                break;
                            }
                            if(cnt==2){
                                b=0;
                                for(int i=1;i<=4;i++){
                                    if(g[i]==1&&g[i+1]==1){
                                        b=1;
                                    }
                                }
                                if(!b)break;
                            }

                        }
                        if(b){
                            ans++;
                            //cout<<i1<<i2<<i3<<i4<<i5<<endl;
                        }
                    }
                }
            }
        }
    }
    cout<<max(ans-n,0);
    return 0;
}
