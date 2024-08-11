#include<bits/stdc++.h>
using namespace std;
int n;
int tot;
int cnt;
int main(){
	freopen("apple2.in", "r", stdin);
    freopen("apple2.ans", "w", stdout);
    cin>>n;
    cout<<1<<endl;
    tot = n;
    while(tot){
		if(tot%3!=0){
			tot-=tot/3+1;
			cnt++;
		}
	}
	cout<<cnt;
    if(n%3==1){
        cout<<" "<<1;
        fclose(stdin);
		fclose(stdout);
        return 0;
    }
    cout<<" "<<n%3+n/3+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
