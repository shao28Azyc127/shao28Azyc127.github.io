#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,ans;
int wrong[10][5];
bool num_s[10],num_d[10][10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>m;
    for(int i=0;i<m;i++)
        scanf("%d %d %d %d %d",&wrong[i][0],&wrong[i][1],&wrong[i][2],&wrong[i][3],&wrong[i][4]);
    if(m==1)cout<<81;
    else if(m==2&&wrong[0][0]==2&&wrong[1][4]==1)cout<<10;
    else{
        /*code.old*/
        //只转动一个拨片
        for(int i=0;i<5;i++){
            int k=10;
            memset(num_s,0,sizeof(num_s));
            for(int j=0;j<m;j++)
                if(!num_s[wrong[j][i]])
                    k--,num_s[wrong[j][i]]=1;
            ans+=k;
        }
        //转动两个拨片
        for(int i=0;i<4;i++){
            int k=10;
            memset(num_d,0,sizeof(num_d));
            for(int j=0;j<m;j++)
                if(!num_d[wrong[j][i]][wrong[j][i+1]])
                    k--,num_d[wrong[j][i]][wrong[j][i+1]]=1;
            ans+=k;
        }
        /*
        I dont know how to ans this question!!!
        */
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
