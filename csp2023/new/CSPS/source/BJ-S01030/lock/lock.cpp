#include<bits/stdc++.h>
using namespace std;
int n,num,ans,r;
int a[10][10];
bool flag[6],book;
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=5;j++){
            cin >> a[i][j];
        }
    }
    if (n==1){
        cout << 81 << endl;
        return 0;
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<=5;j++){
            if (a[i][j]!=a[i+1][j]) {
                flag[j]=true;
                r=j;
            }
        }
    }
    for (int i=1;i<=5;i++){
        if (flag[i]==true) num++;
    }
    if (num==2){
        for(int i=0;i<=9;i++){
            for (int j=0;j<=9;j++){
                for (int k=1;k<=n;k++){
                    if (a[k][r-1]!=i){
                        if (a[k][r]!=j){
                            if (a[k][r-1]-i!=a[k][r]-j) book=true;
                        }
                    }
                }
                if (book==false) ans++;
                book=false;
            }
        }
    }
    if (num==1){
        if (r==1){
            for(int i=0;i<=9;i++){
                for (int j=0;j<=9;j++){
                    for (int k=1;k<=n;k++){
                        if (a[k][r]!=i){
                            if (a[k][r+1]!=j){
                                if (a[k][r]-i!=a[k][r+1]-j) book=true;
                            }
                        }
                    }
                    if (book==false) ans++;
                    book=false;
                }
            }
        }
        else if (r==5){
            for(int i=0;i<=9;i++){
                for (int j=0;j<=9;j++){
                    for (int k=1;k<=n;k++){
                        if (a[k][r-1]!=i){
                            if (a[k][r]!=j){
                                if (a[k][r-1]-i!=a[k][r]-j) book=true;
                            }
                        }
                    }
                    if (book==false) ans++;
                    book=false;
                }
            }
        }
        else{
            for(int i=0;i<=9;i++){
                for (int j=0;j<=9;j++){
                    for (int k=1;k<=n;k++){
                        if (a[k][r-1]!=i){
                            if (a[k][r]!=j){
                                if (a[k][r-1]-i!=a[k][r]-j) book=true;
                            }
                        }
                    }
                    if (book==false) ans++;
                    book=false;
                }
            }
            for(int i=0;i<=9;i++){
                for (int j=0;j<=9;j++){
                    for (int k=1;k<=n;k++){
                        if (a[k][r]!=i){
                            if (a[k][r+1]!=j){
                                if (a[k][r]-i!=a[k][r+1]-j) book=true;
                            }
                        }
                    }
                    if (book==false) ans++;
                    book=false;
                }
            }
        }
    }
    cout << max(0,ans-n) << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
