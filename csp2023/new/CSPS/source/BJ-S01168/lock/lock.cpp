#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream inFile("lock.in");
  ofstream outFile("lock.out");
  int num;
  inFile >> num;
  if(num == 1){
    outFile << 81 << endl;
  }
  else if(num == 2){
    outFile << 9 << endl;
  }
  else{
    outFile << 1 << endl;
  }
    
  inFile.close();
  outFile.close();
  return 0;
}
