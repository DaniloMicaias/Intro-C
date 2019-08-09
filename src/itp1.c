#include "/home/theking7br/Documentos/itp/inc/console.h"

void main(){
  int l, c, t1, t2;

  //Entrada de dados
  print("l: ");
  l = readInt();
  print("c: ");
  c = readInt();

  //Manipulação dos dados inseridos
  t1 = l*c + ((l-1)*(c-1));
  t2 = 2*(l-1) + 2*(c-1);

  //Saída dos dados manipulados
  print("t1: ");
  printInt(t1);
  print("t2: ");
  printInt(t2);
}