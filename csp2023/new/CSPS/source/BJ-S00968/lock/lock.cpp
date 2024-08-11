#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[10][10];
char ch[10];
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    bool op;
    cin >>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin >>a[i][j];
        }
    }
    if(n==1){
        cout <<81;
    }else{
        int cnt=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    for(int l=0;l<10;l++){
                        for(int m=0;m<10;m++){
                            i+=48;
                            j+=48;
                            k+=48;
                            l+=48;
                            m+=48;
                            ch[1]=char(i);
                            ch[2]=char(j);
                            ch[3]=char(k);
                            ch[4]=char(l);
                            ch[5]=char(m);
                            i-=48;
                            j-=48;
                            k-=48;
                            l-=48;
                            m-=48;
                            op=false;
                            for(int o=1;o<=n;o++){
                                int sum=0,sum1=0;
                                bool flag=true;
                                for(int f=1;f<=5;f++){
                                    int x=ch[f]-'0',y=a[o][f];
                                    if(x!=y) sum++;
                                }
                                int x[10];
                                x[1]=a[o][1],x[2]=a[o][2],x[3]=a[o][3],x[4]=a[o][4],x[5]=a[o][5];
                                //2 8 3 5 1
                                for(int f=1;f<5;f++){
                                    int xx=ch[f]-'0',_xx=ch[f+1]-'0',y=x[f],_y=x[f+1];
                                    if(abs(xx-_xx)==abs(y-_y) && ((xx==y) && (_xx==_y) || (xx!=y && _xx!=_y))){
                                        sum1++;
                                        x[f]=xx;
                                        x[f+1]=_xx;
                                    }
                                }
                                for(int f=1;f<=5;f++){
                                    if(ch[f]!=x[f]) flag=false;
                                }
                                if(sum>1 && (!flag || (flag && sum1>1))){
                                    op=true;
                                    break;
                                }
                            }
                            if(op) break;
                            cnt++;
                        }
                    }
                }
            }
        }
        cout <<cnt;
    }
    return 0;
}
