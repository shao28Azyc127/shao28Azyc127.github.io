include<bits/cstd.h++>
using namespace std;
int n,m,k,num=1000000,num2,cen;
int xunzhao(int v){
    for(int i=0;i<m;i++){
        if(u[i][0]==v){
            cen+=1;
            if(num2<(u[i][2]-cen)){
                num2=u[i][2]-cen;
            }
            if(u[i][1]==m){
                return num2;
            }else{
                xunzhao(u[i][1]);
            }
        }
    }
    return ;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    int u[m][3];
    for(int i=1;i<=m;i++){
        cin<<u[i][0]<<u[i][1]<<u[i][2];
    }
    for(int i=0;i<m;i++){
        if(u[i][0]==1){
            num2=u[i][2];cen=0;
            if(u[i][1]==m&&k==1&&num>u[i][2]){
                num=u[i][2];
            }else{
                if(num>xunzhao(u[i][1])){
                    num=xunzhao(u[i][1]);
                }
            }
        }
    }
    for(int i=num;;i++){
        if(i%k==0){
            num=i;
            break;
        }
    }
    return 0;
}

