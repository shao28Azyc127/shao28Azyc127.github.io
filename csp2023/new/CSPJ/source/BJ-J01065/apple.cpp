#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>vis;
    vector<bool>flag;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,res1=0,res2=0;
    cin>>n;
    int num=n;
    for(int i=0;i<n;i++){
        vis.push_back(i+1);
        flag.push_back(0);
    }
    while(1){
        res1++;
        vector<int>ben;
        for(int i=0;i<num;i=i){
			while(flag[i]==1)i++;
			int tot=0;
			if(i>=num)break;
            if(vis[i]==num&&res2==0){
                res2=res1;
                //cout<<1<<endl;
            }
            //vis.erase(vis.begin()+i);
            flag[i]=1;
            //cout<<i+1<<" ";
            n--;
            while(tot!=3){
				if(flag[i]==0)tot++;
				if(tot==3)break;
				i++;
			}
        } 
        //cout<<endl;
        if(n<=0){
			break;          
		}
    }
    cout<<res1<<" "<<res2;
}
