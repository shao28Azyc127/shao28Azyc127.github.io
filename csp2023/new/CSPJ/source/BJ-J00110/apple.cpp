#include<bits/stdc++.h>
using namespace std;
int n,clr,nin;
int apl[100000010];
int main(){
    ios::sync_with_stdio(false);
    freopen("apple1.in","r", stdin);
    freopen("apple1.out","w", stdout);
    cin >> n;
    for(int i = 1; i<=n; i++){
        apl[i] = 1;
    }
    while(1){
        int k = 0;
        while(apl[k]==0){
            k++;
            if(k==n+1){
                cout << clr << " " << nin;
                return 0;
            }
        }
        while(k<=n){
            //cout << k << " ";
            apl[k] = 0;
            int kl = 1;
            if(k==n){
                nin = clr+1;
            }
            while(kl<=3&&k<=n){
                k++;
                if(apl[k] == 1){
                    kl++;
                }
            }
        }
        clr++;
        //cout << endl;
    }

}
/*
1 2 3 4 5 6 7 8
2 3 5 6 8
3 5 8
5 8
8

*/
