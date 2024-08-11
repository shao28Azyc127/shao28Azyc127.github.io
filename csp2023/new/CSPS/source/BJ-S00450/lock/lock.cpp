#include<bits/stdc++.h>
using namespace std;

int f[6];

int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);

    int n;
    int a[10][6];
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }

    int cnt=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(a[1][j]!=a[i][j]){
                cnt++;
                break;
            }
        }
    }
    if(cnt==3){
        cout<<2;
        return 0;
    }else if(cnt==4){
        cout<<1;
        return 0;
    }

    cnt=0;
    if(n==1){
        cout<<81;
        return 0;
    }else if(n==2){
        if(cnt==1){
            cout<<10;
            return 0;
        }
        for(int i=1;i<=n;i++){
            if(a[1][i]!=a[2][i]){
                cnt++;
                f[cnt]=i;
            }
        }
        if(cnt==2){
            if(f[1]+1!=f[2]){
                cout<<1;
                return 0;
            }else{
                if(a[1][f[1]]-a[2][f[1]]==a[1][f[2]]-a[2][f[2]]){
                    cout<<10;
                    return 0;
                }else{
                    cout<<4;
                    return 0;
                }
            }
        }else{
            cout<<10;
            return 0;
        }
    }else if(n==3){
        for(int i=2;i<=n;i++){
            for(int j=1;j<=5;j++){
                if(a[1][j]!=a[i][j]){
                    cnt++;
                    f[cnt]=j;
                    break;
                }
            }
        }
        if(cnt==2){
            if(f[1]+1!=f[2]){
                cout<<1;
                return 0;
            }else{
                int x=a[1][f[1]]-a[2][f[1]];
                int y=a[1][f[2]]-a[2][f[2]];
                for(int i=2;i<=n-1;i++){
                    if(x!=a[i][f[1]]-a[i+1][f[1]]){
                        cout<<1;
                        return 0;
                    }
                    if(y!=a[i][f[2]]-a[i+1][f[2]]){
                        cout<<1;
                        return 0;
                    }
                }
                cout<<10-n;
            }
        }
    }
	fclose(stdin);
	fclose(stdout);
}
