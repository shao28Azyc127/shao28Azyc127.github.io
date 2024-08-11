#include<bits/stdc++.h>
using namespace std;

const long long N=2e5+5;
struct shu{
	long long b,c;
	long long a;
};

int n,g[N][N]={0},u,v,aa[N]={-1},youde[N],you=2,big=0,big1;
shu kd[N];
int abc(int i){
	int a1,b1;
	int j;
    for(j=1;j<=n;j++){
		if(aa[j]<0){
			if(g[i][j]==1){
			    if(a1<kd[j].a){
				    a1=kd[j].a;
				    b1=j;
			    }
		    }
		}
	}
		
	
    return j;
}
int jj(int x){
	for(int j=1;j<=n;j++){
		if(aa[j]>=0){
			aa[j]+=max(kd[j].b+kd[j].c,1);
		}
	}
	return 0;
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>kd[i].a>>kd[i].b>>kd[i].c;
	}
	for(int i=1;i<n;i++){
	    cin>>u>>v;
	    g[u][v]=g[v][u]=1;
	}
	for(int i=1;i<=n;i++){
	    if(i==1) {
		    aa[i]=0;
		    youde[1]=1;
		}
		else{
			jj(i);
		    if(i==2){
			    aa[abc(1)]=0;
			    youde[2]=abc(1);
			    continue;
		    }
		    for(int i=1;i<=you;i++){
				if(kd[abc(youde[i])].a>big){
					//aa[youde[i]]=0;
					big=kd[abc(youde[i])].a;
					big1=abc(youde[i]);
				}
					//aa[youde[i-1]]=0;
				
			}
			aa[big1]=0;
	    }
	    
	    
	}
	int tian=0;
	for(int i=1;i<=n;i++){
		if(kd[i].a>aa[i]){
		    if((kd[i].a-aa[i])>tian){
			    tian=kd[i].a-aa[i];
			}
		}
	}
	cout<<n+tian;
	return 0;
}
