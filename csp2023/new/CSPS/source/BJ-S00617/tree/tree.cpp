#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[100010];
int b[100010];
int c[100010];
bool mapp[5010][5010];
int n;
int tree[100010];
int ans=2000000000;

void dfs(int day,int x)
{
//	cout<<"x:"<<x<<" day:"<<day<<endl;
    tree[x]=0;
    for(int i=1;i<=n;i++){
        if(tree[i]!=-1){
            tree[i]+=max(b[i]+day*c[i],1);
        }
    }
    
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(tree[i]<a[i]){
            flag=false;
            break;
        }
    }
    if(flag){
//		cout<<day<<endl;
        ans=min(ans,day);
        return;
    }

	int bftree[100010];
	for(int i=1;i<=n;i++){
		bftree[i]=tree[i];
	}
	bool aaa=false;
    for(int i=1;i<=n;i++){
        bool iscon=false;
        if(tree[i]!=-1){
			continue;
		}
        for(int j=1;j<=n;j++){
//            cout<<i<<' '<<j<<' '<<mapp[i][j]<<' '<<tree[j]<<' '<<day<<endl;
            if(mapp[i][j]==1 && tree[j]!=-1){
                iscon=true;
                break;
            }
        }
        if(iscon){
//            cout<<"i:"<<i<<" day:"<<day<<endl;
            aaa=true;
            dfs(day+1,i);
			for(int i=1;i<=n;i++){
				tree[i]=bftree[i];
			}
        }
    }
    if(!aaa){
		dfs(day+1,0);
	}
	for(int i=1;i<=n;i++){
		tree[i]=bftree[i];
	}
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        tree[i]=-1;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        mapp[u][v]=1;
        mapp[v][u]=1;
    }
    dfs(1,1);
    cout<<ans<<endl;
    return 0;
}
