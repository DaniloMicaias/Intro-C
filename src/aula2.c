#include "/home/theking7br/Documentos/itp/inc/console.h"

void main(){
  int p1, p2, c1, c2;

  print("p1:");
  p1 = readInt();
  print("p2:");
  p2 = readInt();
  print("c1:");
  c1 = readInt();
  print("c2:");
  c2 = readInt();

  int x1 = p1*c1;
  int x2 = p2*c2;

  if(x1 = x2){
    print("0");      
  }else{
      if(x1>x2){
          print("-1");
      }else{
          print("1");
      }
  }

}