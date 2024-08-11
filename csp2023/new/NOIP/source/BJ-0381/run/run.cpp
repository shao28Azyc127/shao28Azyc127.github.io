#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int c, t, n, m, k, d, a[N], x[N], y[N], v[N], ans = -1e18;
bool check() {
    for(int i = 1; i <= n - k; i++) {
        bool b = 1;
        for(int j = i; j <= i + k; j++) 
            if(!a[j]) {
                b = 0;
                break;
            }
        if(b) return 0;
    }
    return 1;
}
void work(int z, int p, int g, int q) {
    if(z == n + 1) {
        if(check()) ans = max(ans, p);
        return;
    }
    a[z] = 0;
    work(z + 1, p, 0, q);
    a[z] = 1;
    while(x[q] < z && q <= m) q++;
    while(x[q] == z && g + 1 >= y[q]) {
        p += v[q];
        q++;
    }
    work(z + 1, p - d, g + 1, q);
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin>>c>>t;
    while(t--) {
        cin>>n>>m>>k>>d;
        for(int i = 1; i <= m; i++) cin>>x[i]>>y[i]>>v[i];
        work(1, 0, 0, 1);
        cout<<ans<<endl;
    }
    return 0;
}

/*  main.cpp
    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    const string versionNumber = "v1.0.0";
    const int maxSize = 1e3 + 5;
    int listCount = 0, listType[maxSize];
    string listValue[maxSize];
    void printList() {
        cout<<"Welcome to ToDo-Editor!"<<endl;
        cout<<"Total: "<<listCount<<" ToDos"<<endl;
        for(int i = 1; i <= listCount; i++) {
            cout<<"No."<<i<<" ";
            if(listType[i]) cout<<"+ ";
            else cout<<"- ";
            cout<<listValue[i]<<endl;
        }
    }
    string getLower(string inputString) {
        for(int i = 0; i < inputString.length(); i++) 
            if(inputString[i] >= 'A' && inputString[i] <= 'Z') inputString[i] += 'a' - 'A';
        return inputString;
    }
    signed main() {
        ifstream listData("list.todo");
        while(listData>>listType[++listCount]) listData>>listValue[listCount];
        listCount--;
        printList();
        ifstream settingData("setting.dat");
        while(1) {
            cout<<"(ToDo) ";
            string commandValue;
            cin>>commandValue;
            commandValue = getLower(commandValue);
            if(commandValue == "quit" || commandValue == "q") break;
            else if(commandValue == "delete" || commandValue == "d") {

            } else if(commandValue == "create" || commandValue == "c") {
                
            } else if(commandValue == "finish" || commandValue == "f") {
                
            } else if(commandValue == "setting" || commandValue == "s") {
                while(1) {
                    cout<<"  [S] ";
                    string settingCommandValue;
                    cin>>settingCommandValue;
                    settingCommandValue = getLower(settingCommandValue);
                    if(settingCommandValue == "quit" || settingCommandValue == "q") break;
                    else if(settingCommandValue == "help" || settingCommandValue == "h") {
                        cout<<"  Setting of ToDo-Editor "<<versionNumber<<endl;
                        ifstream settingHelpData("shelp.dat");
                        string settingHelpValue;
                        while(getline(settingHelpData, settingHelpValue)) cout<<"  "<<settingHelpValue<<endl;
                    } else 
                        cout<<"  No matching command '"<<settingCommandValue<<"'. Type 'help' or 'h' for help."<<endl;
                }
            } else if(commandValue == "help" || commandValue == "h") {
                cout<<"ToDo-Editor "<<versionNumber<<endl;
                ifstream helpData("help.dat");
                string helpValue;
                while(getline(helpData, helpValue)) cout<<helpValue<<endl;
            } else 
                cout<<"No matching command '"<<commandValue<<"'. Type 'help' or 'h' for help."<<endl;
        }
    }
*/

/*  help.dat = shelp.dat
'delete' or 'd'     Delete a todo project.
'create' or 'c'     Create a todo project.
'finish' or 'f'     Mark a todo project with condition 'done'.
'setting' or 's'    Change system settings.
'help' or 'h'       Get informations and tips.
*/

/*  setting.dat
0 0 0 0 0 0 0
*/

/*  list.todo
0 todo1
1 todo2
1 todo3
*/