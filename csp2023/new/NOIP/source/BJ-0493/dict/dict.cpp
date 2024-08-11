#include<bits/stdc++.h>
using namespace std;
int n,m,a[3001][27],mi[27];
void work1(int i){
    for(int j=26;j>=1;j--){
        mi[26-j+1]=a[i][j];
    }
}
int check(int i){
    for(int j=1,k=1;j<=26,k<=26;j++,k++){
        while(mi[k]==0&&k<=26) k++;
        while(a[i][j]==0&&j<=26) j++;
        if(k>26||j>26) break;
        if(j<26-k+1) return 1;
        else if(j>26-k+1) return 0;
    }
    return 1;
}
int main(){
    freopen("dict1.in","r",stdin);
    freopen("dict.out","w",stdout);
    mi[1]=3001;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            a[i][c-'a'+1]++;
        }
    }
    for(int i=1;i<=n;i++){
        int k=1,j=26;
        while(k<=26,j>=1){
            while(mi[k]==0&&k<=26) k++;
            while(a[i][j]==0&&j>=1) j--;
            if(k>26||j<1) break;
            if(j<26-k+1){
                work1(i);
                break;
            }
            else if(j>26-k+1) break;
            else if(j==26-k+1&&a[i][j]<mi[k]){
                work1(i);
                break;
            }
            else if(j==26-k+1&&a[i][j]>mi[k]) break;
            k++;
            j--;
        }
    }
    for(int i=1;i<=n;i++) cout<<check(i);
    return 0;
}

