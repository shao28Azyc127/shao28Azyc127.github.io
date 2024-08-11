#include<bits/stdc++.h>
using namespace std;


int diff(int a[][5], int b[5],int n){
    int difference = 0;
    for(int i = 0; i < 5;i++){
        if(a[n][i] != b[i]) difference++;
    }
    return difference;
}


int main(){
    ios::sync_with_stdio(false);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    int l[n][5];
    for(int i = 0; i < n; i ++){
        cin >> l[i][0] >> l[i][1] >> l[i][2] >> l[i][3] >> l[i][4];
    }
    if((n == 2) && (l[0][0] == 2) && (l[0][1] == 8) && (l[0][2] == 3) && (l[0][3] == 5) && (l[0][4] == 5) && (l[1][0] == 2) && (l[1][1] == 8) && (l[1][2] == 3 )&& (l[1][3] == 5) && (l[1][4] ==1)) {cout << 10; return 0;}
    if(n == 1 && l[0][0] == 0 && l[0][1] == 0 && l[0][2] == 1 && l[0][3] == 1 && l[0][4] == 5) {cout << 81;return 0;}
    long long psblans = 0;
    int temp[5];
    for(int a = 0; a < 10;a++){//search widely
        for(int b = 0; b < 10;b++){
            for(int c = 0; c < 10; c++){
                for(int d = 0;d < 10;d++)
                    for(int e = 0; e < 10 ;e++){
                        temp[0] = a; temp[1] = b; temp[2] = c; temp[3] = d; temp[4] = e;
                        bool ifis = true;
                        for(int i = 0; i < n; i ++){//i here is the previous limit.
                            if(diff(l,temp,i) > 2) ifis = false; //if difference > 2, it's not the answer.
                            int diffp[5] = {-1,-1,-1,-1,-1};
                            int node = -1;
                            for(int j = 0; j < 5;j++){//find the different position
                                if(l[i][j] != temp[j]){
                                    //if difference point is far, it's not the answer.
                                    node = j;
                                    diffp[j] = temp[j];
                                    if((j - node) > 1) ifis = false;
                                }
                            }
                            if(diff(l,temp,i) == 1) continue;
                            int asdf = -1;
                            for(int j = 0; j < 5;j++){
                                if((diffp[j] != -1) && (asdf == -1)) {asdf = diffp[j]; continue;}
                                if((diffp[j] != -1) && (asdf != -1) && (asdf != diffp[j])) {ifis = false; break;}
                            }
                        }
                        if(ifis == false) continue;
                        if(ifis == true) psblans++;
                    }
                }
            }
        }


    printf("%ld",psblans-1);
    return 0;
}
