#include<bits/stdc++.h>
using namespace std;
int m,n,m1=1,cnt,z;
int w[4000][30];
string s,e[4000];
int find(int x,int y){
    cnt=0,z=m;
    int i=1,j=26;
    while(z>0){
    while(w[x][i]==0){
        i++;
    }
    while(w[y][j]==0){
        j--;
    }
    if(i<j){
        return 1;//x xiao
    }
    if(i>=j){
        return 2;//y xiao
    }
    /*if(w[x][i]<=w[y][j]){
        return 1;
    }else{
        return 2;
        }

    }*/

}
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            w[i][s[j]-'a'+1]++;
        }
    }

 /*for(int i=1;i<=n;i++){
      for(int j=1;j<=26;j++){
        cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
    */
for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                if(find(i,j)==2){
                    cout<<0;
                    cnt=1;
                    break;
                }
            //cnt=max(cnt,find(i,j));
        }
        /*if(cnt==1){
            cout<<1;
        }else{
            cout<<0;
        }
*/
if(cnt==0){
    cout<<1;
}

    }
//cout<<endl<<find(4,3);
    return 0;
}
