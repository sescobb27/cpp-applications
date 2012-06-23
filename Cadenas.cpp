#include<iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool incrementa(char[10]);

int main(){
     char num[10];
     char digit;
     int cont=1;
     while(cont < 10 && cin >> digit){
          num[cont-1] = digit;
          cont++;
     }
     if(incrementa(num)){
          int numero = atoi(num);
          if(999999999 == numero){
               cout << 0 << endl;
          }else{
               cout << ++numero << endl;
          }
     }
}

bool incrementa(char num[10]){
     int n;
     for(int i = 0; i<9; ++i){
          n = (int)num[i];
          switch(n-48){
               case 1: continue;
               case 2: continue;
               case 3: continue;
               case 4: continue;
               case 5: continue;
               case 6: continue;
               case 7: continue;
               case 8: continue;
               case 9: continue;
               case 0: continue;
               default: return false;
          }
     }
     return true;
}
