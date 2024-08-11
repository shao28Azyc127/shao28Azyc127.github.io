#include<iostream>
using namespace std;
int n, d, less=100010, hav;
int len[100010];
int pri[100010];
int tot, left;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.ans", "w", stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
		cin>>len[i]
	}
	for(int i=0;i<n;i++){
		cin>>pri[100010];
	}
	less=pri[0]
	left=0;
	for(int i=0;i<n-1;i++){
		hav+=len[i]-left
		if(pri[i]<less){
			less=pri[i];
		}
		if(hav%d==0){
			left=0;
			tot+=(hav/d)*less;
		}else{
			left=(hav/d+1)*4-hav;
			tot+=(hav/d+1)*less;
		}
	}
	cout<<tot;
	fclose(stdin);
    fclose(stdout);
    return 0;
}
