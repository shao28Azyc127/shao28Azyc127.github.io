#include<iostream>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,now=0,Mo=0,road=0,flag=1;
    int dis[100100],cost[100100];
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>dis[i];
    }
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    for(int i=1;i<n;i++){
        flag==1;
        for(int j=i;j<n&&flag==1;j++){
            //cout<<"in:"<<i<<"number:"<<Mo<<endl;
            if(cost[j]<cost[j+1]){
                if(dis[j]%d==0){
                //now=0;
                Mo+=dis[j]/d*cost[j];
                }else{
                //now=0;
                Mo+=(dis[i]/d+1)*cost[j];
                now+=dis[i]%d;
                }



            }
            else{
                if(j-i==0){
                if(dis[j]%d==0){
                //now=0;
                Mo+=dis[j]/d*cost[j];
                }else{
                //now=0;
                Mo+=(dis[j]/d+1)*cost[j];
                now+=dis[j]%d;
                }}else{
                    i=j;
                    flag=0;
                    //break;
                }
                }

        }
        }



    cout<<Mo;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
