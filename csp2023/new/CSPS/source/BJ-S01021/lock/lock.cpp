#include<bits/stdc++.h>
using namespace std;
int n,n1[7][11],n2[7][11],n3[7],ans,zong;
int main(){
    std::ios::sync_with_stdio(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<81<<endl;
        return 0;
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>n1[i][j];
            }
        }
        for(int i=0;i<5;i++){
            n2[0][i]=n1[0][i];
            n3[i]=1;
        }
        for(int k=0;k<5;k++){
            for(int i=1;i<n;i++){
                int flag=0;
                for(int j=0;j<n3[0];j++){
                    if(n1[i][k]==n2[j][k]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    if(n3[k]==1){
                        zong++;
                    }
                    n3[k]++;
                    n2[n3[k]][k]=n1[i][k];
                }
            }
        }
        if(zong==1){
            if(n3[0]>1||n3[4]>1){
                cout<<10<<endl;
            }
            else{
                for(int i=0;i<5;i++){
                    if(n3[i]>1){
                        cout<<10+n3[i]<<endl;
                        break;
                    }
                }
            }
        }
        else{
            for(int i=0;i<4;i++){
                if(n3[i]>1){
                    cout<<10-min(n3[i],n3[i+1])<<endl;
                    break;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
