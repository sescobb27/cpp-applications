#include<iostream>
#include <math.h> 

using namespace std;

int main(){

int num;
bool primo = false;
cout << "Escriba un numero:\n";
while(cin >> num){
     if (num == 1){
     cout <<"primo\n";
     }else if(num==2){
          cout << "primo\n";
     }else{
          int cont = 2;
          while(cont <= sqrt(num)){
               if(num%cont == 0){
                    cout << "no es primo\n";
                    primo = true;
                    break;
               }else if(cont==2){
                    cont = 3;
               }else{
                    cont += 2;
               }
          }
          if(!primo){
              cout << "primo\n"; 
          }else{
               primo = false;
          }
     }
}
return 0;

}
