#include<bits/stdc++.h>
using namespace std;
int equalsmin[4]; 
int n,i=0,j=0,m=0,sum=0;
int lock1[9][5];
struct Number{
    bool is[10];
}number[5];
void cmp(int q,int p){
    int equals=0,place[5];
    for(j=0;j<5;j++){
        if(lock1[q][j]==lock1[p][j]){
            equals++;
            place[j]=1;
        }
    }
    if(equals==2){
        for(j=0;j<5;j++){
            if(place[j]==1) for(m=0;m<10;m++) if(m!=lock1[q][place[j]]) number[place[j]].is[m]=false;
            else{
                if(j<=3){
                    if(place[j]==0&&place[j+1]==0&&place[j+2]==0){
                        for(m=0;m<10;m++){
                            if(m!=lock1[q][place[j]]&&m!=lock1[p][place[j]])number[place[j]].is[m]=false;
                            if(m!=lock1[q][place[j+1]]&&m!=lock1[p][place[j+1]])number[place[j+1]].is[m]=false;
                            if(m!=lock1[q][place[j+2]]&&m!=lock1[p][place[j+2]])number[place[j+2]].is[m]=false;
                        }
                        equalsmin[place[j]]=lock1[p][place[j]]-lock1[p][place[j+1]];
                        equalsmin[place[j]]=lock1[p][place[j+1]]-lock1[p][place[j+2]];
                        j+=2;
                    }
                    else{
                        for(m=0;m<10;m++) if(m!=lock1[q][place[j]]&&m!=lock1[p][place[j]]) number[place[j]].is[m]=false;
                        equalsmin[place[j]]=lock1[q][place[j]]-lock1[q][place[j]];
                    }
                }
                else{
                    for(m=0;m<10;m++) if(m!=lock1[q][place[j]]&&m!=lock1[p][place[j]]) number[place[j]].is[m]=false;
                    equalsmin[place[j]]=lock1[q][place[j]]-lock1[q][place[j]];
                }
            }
        }
    }
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(;i<n;i++) for(j=0;j<5;j++) cin>>lock1[i][j];
    if(n==1){
        cout<<81<<endl;
        return 0;
    }
    for(i=0;i<5;i++) for(j=0;j<10;j++) number[i].is[j]=true;
    for(int t=0;t<n;t++) cmp(t,t+1);
    int A[5];
    for(i=0;i<10;i++){
        if(number[0].is[i]==true){
            for(j=0;j<10;j++){
                if(number[1].is[j]==true&&number[1].is[j]==number[0].is[i]-equalsmin[0]){
                    for(m=0;m<10;m++){
                        if(number[2].is[m]==true&&number[2].is[m]==number[1].is[j]-equalsmin[1]){
                            for(int x=0;x<10;x++){
                                if(number[3].is[x]==true&&number[3].is[x]==number[2].is[m]-equalsmin[2]){
                                    for(int y=0;y<10;y++){
                                        if(number[4].is[y]==true&&number[4].is[y]==number[3].is[x]-equalsmin[3]){
                                            sum++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
