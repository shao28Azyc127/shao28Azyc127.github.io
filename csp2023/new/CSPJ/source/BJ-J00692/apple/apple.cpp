#include <bits/stdc++.h>
using namespace std;
int a[114514];
int n,i=0,ans = 0,cnt = 0,ji = 0,xh = 0;
bool flag1 = true,you = false,head = true;
int main(){
    //freopen("apple1.in","r",stdin);
    //freopen("apple.out","w",stdout);
    cin >> n;
    for(i = 0;i < n;i++){
        a[i] = 1;
    }
    while(flag1){
        ans++;
        xh = 0;
        for(i = 0;i < n;i++){
            if(a[i] == 1){
                break;
            }
        }
        for(i;i < n;i+=3){
            ji = 0;
            head = true;
            //for(int q = 0;q < n;q++){
            //    cout << a[q] << ' ';
            //}
            //cout << i << "----------";
            //cout << endl << "ji=" << ji << endl;
            if(i >= 1){
                for(int q = 0;q < i;q++){
                    if(a[q] == 1){
                        head = false;
                    }
                }
            }
            if(!head){
                int w = 0;
                if(!a[i]){
                    w++;
                }
                if(!a[i - 1]){
                    w++;
                }
                if(!a[i - 2]){
                    w++;
                }
                i += w;
            }
            while(a[i] == 0 && i < n){
                i++;
            }
            for(int q = 0;q < i;q++){
                if(a[q] == 1){
                    ji++;
                }
            }
            if(ji >= 2 || head){
                if(head && xh == 0){
                    a[i] = 0;
                    xh++;
                    //cout << i << endl;
                    if(a[n - 1] == 0){
                        cnt = ans;
                    }
                }else if(head && xh != 0){
                    //cout << endl;
                    continue;
                }else{
                    a[i] = 0;
                    //cout << i << endl;
                    if(a[n - 1] == 0){
                        cnt = ans;
                    }
                }
            }else{
                //cout << endl;
                continue;
            }
        }
        //for(int q = 0;q < n;q++){
        //    cout << a[q] << ' ';
        //}
        //cout << "++++++++++++++++" << ans << endl;
        you = false;
        for(i = 0;i < n;i++){
            if(a[i] == 1){
                you = true;
            }
        }
        if(you){
            flag1 = true;
        }else{
            flag1 = false;
        }
    }
    if((n - 1) % 3 == 0){
        cout << ans << " " << 1;
    }else{
        cout << ans << " " << cnt;
    }

   // fclose(stdin);
   // fclose(stdout);
    return 0;
}
