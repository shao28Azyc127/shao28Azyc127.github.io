#include <iostream>
#include <fstream>

using namespace std;

int taskOne;
int taskTwo;
int resOne = 0;
int resTwo = 1;

void ParseIn(){
  ifstream inFile("apple.in");
  inFile >> taskOne;
  taskTwo = taskOne-1;
  inFile.close();
}

void Core(){
  int pick;
  while(taskOne > 0){
    pick = taskOne / 3;
    if(pick * 3 < taskOne){
      pick++;
    }
    taskOne-=pick;
    resOne++;
  }
  while(taskTwo % 3 != 0){
    pick = taskTwo / 3;
    if(pick * 3 < taskTwo){
      pick++;
    }
    taskTwo-=pick;
    resTwo++;
  }
  

  
}

void WriteOut(){
  ofstream outFile("apple.out");
  outFile << resOne << ' ' << resTwo << endl;
  outFile.close();
}

int main(){
  ParseIn();
  Core();
  WriteOut();
  return 0;
}