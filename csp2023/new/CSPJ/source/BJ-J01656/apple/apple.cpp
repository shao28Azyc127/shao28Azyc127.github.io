#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+2;
ll n;
ll head, tail;
struct node{
	ll id;
	ll pre;
	ll next;
}a[N];
ll icnt;
ll Nid;
int main(){
	freopen("apple.in", "r", stdin);
	freopen("apple.out", "w", stdout);
	scanf("%lld", &n);
	head = 1, tail = n;
	for(int i = 1; i <= n; i++){
		a[i].id = i;
		a[i].pre = i - 1;
		a[i].next = i + 1;
	}
	a[1].pre = -1;
	a[n].next = -1;
	ll itmp = 3;
	while(head != -1){
			itmp = 3;
			icnt++;
			for(int i = head; i != -1; i = a[i].next){
				if(itmp % 3 == 0){
					if(i == head){
						head = a[i].next;
						a[head].pre = -1;
					} else {
						a[a[i].pre].next = a[i].next;
					}
					if(i == n){
						Nid = icnt;
					}
				}
				itmp--;
				if(itmp == 0){
					itmp = 3;
				}
			}
			//cout << head << " - ";
		
	}
	/*for(int i = head; i != -1; i = a[i].next){
			cout << i << " ";
	}*/
	printf("%lld %lld", icnt, Nid);
	return 0;
}
