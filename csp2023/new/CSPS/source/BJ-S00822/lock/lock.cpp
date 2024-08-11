#include <bits/stdc++.h>
using namespace std;
int s[8][5];
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>s[i][j];
        }
    }
    int ss[5], cnt=0;
    for(ss[0]=0;ss[0]<10;ss[0]++){
    for(ss[1]=0;ss[1]<10;ss[1]++){
    for(ss[2]=0;ss[2]<10;ss[2]++){
    for(ss[3]=0;ss[3]<10;ss[3]++){
    for(ss[4]=0;ss[4]<10;ss[4]++){
    bool flag = 1;
    for(int j=0;j<n;j++){
        int dq=0, d=-1;
        for(int k=0;k<5;k++){
            if(ss[k] != s[j][k]){
                dq++;
                if(d == -1) d = k;
            }
        }
        if(dq == 1){
            flag = 1;
        }else if(dq == 2 && d != 4 && ((ss[d] - s[j][d] + 10) % 10 == (ss[d + 1] - s[j][d + 1] + 10) % 10)){
            flag = 1;
        }else{
            flag = 0;
            break;
        }
    }
    if(flag){
        cnt++;
        //for(int i=0;i<5;i++)cout<<ss[i]<<" ";
        //cout<<endl;
    }
    }
    }
    }
    }
    }
    cout<<cnt<<endl;
    return 0;
}
