#include<bits/stdc++.h>
using namespace std;
int bh[100001][11]={};//0为未知，1为真，2为假
int tri(int n,int b){
    int bp=b,np=0;
    while(np<n){
        if(bp>=2*pow(3,n-np)){
            bh[b][np]=2;
            bp-=2*pow(3,n-np);
        }else if(bp>=pow(3,n-np)){
            bh[b][np]=1;
            bp-=pow(3,n-np);
        }else{
            bh[b][np]=0;
        }
        np++;
    }
    return 0;
}
int trb(int n,int q,int b){//n总位数。q当前位数，b当前编号
    int b0=b;
    int b1=b+pow(3,n-q);
    int b2=b+2*pow(3,n-q);
    if(q<n){
        trb(n,q+1,b0);
        trb(n,q+1,b1);
        trb(n,q+1,b2);
    }
    if(q==n){
        tri(n,b0);
        tri(n,b1);
        tri(n,b2);
    }
    return 0;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int p=0;p<t;p++){
        int n,m;
        cin>>n>>m;
        trb(n,0,0);
        int ans=n+1;
        int zlj[m][3]={};//指令集,1真2假3未知4正赋5反赋
        for(int i=0;i<m;i++){
            char u;
            int v;
            cin>>u;
            if(u=='T'){
                cin>>v;
                zlj[i][0]=1;
                zlj[i][1]=v-1;
            }
            if(u=='F'){
                cin>>v;
                zlj[i][0]=2;
                zlj[i][1]=v-1;
            }
            if(u=='U'){
                cin>>v;
                zlj[i][0]=3;
                zlj[i][1]=v-1;
            }
            if(u=='+'){
                int v2;
                cin>>v>>v2;
                zlj[i][0]=4;
                zlj[i][1]=v-1;
                zlj[i][2]=v2-1;
            }
            if(u=='-'){
                int v2;
                cin>>v>>v2;
                zlj[i][0]=5;
                zlj[i][1]=v-1;
                zlj[i][2]=v2-1;
            }
        }
        for(int i=0;i<pow(3,n+1);i++){
            if(i%3!=0){
                continue;
            }
            int t[n]={},is=1,up=0;//t暂存本组数值，is表示是否和原样相同，up表示未知个数
            for(int j=0;j<n;j++){
                t[j]=bh[i][j];
                //cout<<t[j]<<' ';
            }
            //cout<<endl;
            for(int j=0;j<m;j++){
                int w=zlj[j][1],w2=zlj[j][2];
                if(zlj[j][0]==1){
                    t[w]=1;
                }
                if(zlj[j][0]==2){
                    t[w]=2;
                }
                if(zlj[j][0]==3){
                    t[w]=0;
                }
                if(zlj[j][0]==4){
                    t[w]=t[w2];
                }
                if(zlj[j][0]==5){
                    if(t[w2]==0){
                        t[w]=0;
                    }else if(t[w2]==1){
                        t[w]=2;
                    }else if(t[w2]==2){
                        t[w]=1;
                    }
                }
                //cout<<w<<'/'<<t[w]<<' ';
            }
            for(int j=0;j<n;j++){
                if(t[j]!=bh[i][j]){
                    is=0;
                }
                if(bh[i][j]==0){
                    up++;
                }
                //cout<<t[j]<<' ';
            }
            if(is==1){
                ans=min(ans,up);
                //cout<<up<<' '<<endl;
            }else{
                //cout<<'/'<<endl;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}