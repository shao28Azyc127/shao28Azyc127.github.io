#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
string memory[80100];
string names[110],init[110][110],namein[110][110],str[110];
int num = 1,numstr = 1,dz = 0,lens[110],pos[110],dizhi[110],maxd[110];

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin>>n;
    for (int i = 1;i <= n;i++){
        int op;
        cin>>op;
        if (op == 1){
            cin>>names[num]>>lens[num];
            num++;
            for (int j = 1;j <= lens[num-1];j++){
                cin>>init[num-1][j]>>namein[num-1][j];
                if (init[num-1][j] == "byte"){
                    maxd[num-1] = max(maxd[num-1],1);
                }
                if (init[num-1][j] == "short"){
                    maxd[num-1] = max(maxd[num-1],2);
                }
                if (init[num-1][j] == "int"){
                    maxd[num-1] = max(maxd[num-1],4);
                }
                if (init[num-1][j] == "long"){
                    maxd[num-1] = max(maxd[num-1],8);
                }
            }
            for (int j = 1;j <= lens[num-1];j++){
                dizhi[num-1] += maxd[num-1];
            }
            cout<<dizhi[num-1]<<" "<<maxd[num-1]<<endl;
        }

        if (op == 2){
            string t;
            cin>>t>>str[numstr];

            if (t == "byte"){
                cout<<dz<<endl;
                memory[dz] = str[numstr];
                dz += 1;
            }
            else if (t == "short"){
                cout<<dz<<endl;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
            }
            else if (t == "int"){
                cout<<dz<<endl;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
            }
            else if (t == "long"){
                cout<<dz<<endl;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
                memory[dz] = str[numstr];
                dz += 1;
            }
            else{
                cout<<dz<<endl;
                for (int j = 1;j < num;j++){
                    if (t == names[j]){
                        int clonedz = dz;
                        for (int q = 1;q <= lens[j];q++){
                            if (init[j][q] == "byte"){
                                for (int p = 0;p < 1;p++){
                                    memory[dz+p] = str[numstr] + "." + namein[j][q];
                                }
                                dz += maxd[j];
                            }
                            if (init[j][q] == "short"){
                                for (int p = 0;p < 2;p++){
                                    memory[dz+p] = str[numstr] + "." + namein[j][q];
                                }
                                dz += maxd[j];
                            }
                            if (init[j][q] == "int"){
                                for (int p = 0;p < 4;p++){
                                    memory[dz+p] = str[numstr] + "." + namein[j][q];
                                }
                                dz += maxd[j];
                            }
                            if (init[j][q] == "long"){
                                for (int p = 0;p < 8;p++){
                                    memory[dz+p] = str[numstr] + "." + namein[j][q];
                                }
                                dz += maxd[j];
                            }
                        }
                    }
                }
            }
            numstr++;
        }
        if (op == 3){
            string t;
            cin>>t;
            for (int i = 0;i < dz;i++){
                if (memory[i].substr(0,t.size()) == t){
                    cout<<i<<endl;
                    break;
                }
            }
        }
        if (op == 4){
            int t;
            cin>>t;
            if (memory[t] != ""){
                cout<<memory[t]<<endl;
            }
            else{
                cout<<"ERR"<<endl;
            }
        }
    }
    return 0;
}
