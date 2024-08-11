#include <bits/stdc++.h>
using namespace std;
int main(){
    FILE* f=freopen("lock.in","r",stdin);
    FILE* f2=freopen("lock.out","w",stdout);
    int n,a[10][10],mem[100]={0},mem2[100]={0},h=0,mem3[100]={0},ans1=0,ans2=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
            if(a[i][j]!=mem[j]&&mem2[j]==0&&i!=1){
                mem2[j]=1;
                mem3[h++]=j;
            }
            else if(i==1){
                mem[j]=a[i][j];
            }
        }
    }
    if(h<3){
        if(n>=3){
            ans1=0;
        }
        else{
            if(h==0){
                ans1=45;
            }
            else if(h==1&&n==1){
                ans1=8;
            }
            else if(h==1&&n!=1){
                ans1=10;
            }
            else{
                ans1=2;
            }
        }
    }
    else{
        cout<<-1;
        return 0;
    }
    if(h==0){
        cout<<81;
        return 0;
    }
    if(h==2&&mem3[1]-mem3[0]>=2){
        ans2=0;
    }
    else {
        for(int i=1;i<=9;i++){
            int c,b,d,e,yes=1,yes2=1,yes3=1;
            for(int k=0;k<h;k++){
                for(int j=1;j<=n;j++){
                    if(mem3[k]==1){
                        yes2=0;
                    }
                    if(yes2){
                        b=a[j][mem3[k]-1]-i;
                        if(b<0){
                            b=10+b;
                        }
                        c=a[j][mem3[k]]-i;
                        if(c<0){
                            c=10+c;
                        }
                        if(j==1){
                            d=b;
                            e=c;
                            continue;
                        }
                        if(!(b==d&&c==e)){
                            yes=0;
                            break;
                        }
                        d=b;
                        e=c;
                    }
                    else{
                        yes=0;
                        break;
                    }
                    if(yes){
                        ans2++;
                    }
                }
            }
        }
        for(int i=1;i<=9;i++){
            int c,b,d,e,yes=1,yes2=1,yes3=1;
            for(int k=0;k<h;k++){
                for(int j=1;j<=n;j++){
                    if(mem3[k]==5){
                        yes3=0;
                    }
                    if(yes3){
                        b=a[j][mem3[k]+1]-i;
                        if(b<0){
                            b=10+b;
                        }
                        c=a[j][mem3[k]]-i;
                        if(c<0){
                            c=10+c;
                        }
                        if(j==1){
                            d=b;
                            e=c;
                            continue;
                        }
                        if(!(b==d&&c==e)){
                            yes=0;
                            break;
                        }
                        d=b;
                        e=c;
                    }
                    else{
                        yes=0;
                        break;
                    }
                }
                if(yes){
                    ans2++;
                }
            }
        }
    }
    cout<<ans1+ans2;
    fclose(f);
    fclose(f2);
    return 0;
}
