#include<iostream>
using namespace std;
int main(){

  int x[7]={3,9,7,8,16,-4,4};
  
  for(int i=0;i<7; i++){
    for(int j=i+1; j<7; j++){
      if(x[i]+x[j]==12){
        cout<<x[i]<<","<<x[j]<<endl;
      }
    }
  
  }  
}
