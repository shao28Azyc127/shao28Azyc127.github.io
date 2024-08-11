#include <bits/stdc++.h>

using namespace std;

int n;
int locka[8][5];
int locking[99999];
void bre(){
    for(int i = 0;i<=9;i++){
        for(int i2 = 0;i2<=9;i2++){
            for(int i3 = 0;i3<=9;i3++){
                for(int i4 = 0;i4<=9;i4++){
                    for(int i5 = 0;i5<=9;i5++){
                        for(int j = 0;j<n;j++){
                            int cont = 5;
                            int site = i*10000+i2*1000+i3*100+10*i4+i5;
                            int chage[5],si = 0,changed[5];
                            if(locking[site] != -1){
                                if(i != locka[j][0]){
                                    cont--;
                                    chage[si] = i-locka[j][0];
                                    changed[si] = 0;
                                    if(chage[si]<0){
                                        chage[si]+=10;
                                    }
                                    si++;
                                }
                                if(i2 != locka[j][1]){
                                    cont--;
                                    chage[si] = i2-locka[j][1];
                                    changed[si] = 1;
                                    if(chage[si]<0){
                                        chage[si]+=10;
                                    }
                                    si++;
                                }
                                if(i3 != locka[j][2]){
                                    cont--;
                                    chage[si] = i3-locka[j][2];
                                    changed[si] = 2;
                                    if(chage[si]<0){
                                        chage[si]+=10;
                                    }
                                    si++;
                                }
                                if(i4 != locka[j][3]){
                                    cont--;
                                    chage[si] = i4-locka[j][3];
                                    changed[si] = 3;
                                    if(chage[si]<0){
                                        chage[si]+=10;
                                    }
                                    si++;
                                }
                                if(i5 != locka[j][4]){
                                    cont--;
                                    chage[si] = i5-locka[j][4];
                                    changed[si] = 4;
                                    if(chage[si]<0){
                                        chage[si]+=10;
                                    }
                                    si++;
                                }
                                if(cont==4||(chage[0]==chage[1]&&cont==3&&changed[1]-changed[0]==1)){
                                    locking[site] = 1;
                                }
                                else{
                                    locking[site] = -1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int ans = 0;
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<5;j++){
            cin>>locka[i][j];
        }
    }
    for(int i = 1;i<=99999;i++){
        locking[i] = 0;
    }
    if(n==1){
        cout<<81;
       return 0;
    }
    bre();
    for(int i = 1;i<=99999;i++){
        if(locking[i] == 1){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
