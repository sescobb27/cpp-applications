#include<iostream>

using namespace std;
int* sortBurbuja(int*,int,char);

int main(){
     int length;
     int num;
     char yes_no;
     cout << "longitud arreglo\n";
     while(cin >> length){
          int arr[length];
          cout << "de mayor a menor\?" << "y/n\n";
          cin >> yes_no;
          cout << "agregar numeros\n";
          for(int i=0; i<length; ++i){
               cin >> num;
               arr[i]= num;
          }
          int* new_arr = sortBurbuja(arr,length,yes_no);
          cout << "El nuevo arreglo es-> ";
          for(int i=0; i<length; ++i){
               cout << "[" << arr[i] << "]";
          }
          cout << "\nlongitud arreglo\n";
     }
     return 0;
}

int* sortBurbuja(int* arr,int length, char tipo){
     int aux;
     if(tipo=='n'){//de menor a mayor
          for(int i= 0; i<length; ++i){
               for(int j=0; j<length-1; ++j){
                    if(arr[j] > arr[j+1]){
                         aux = arr[j];
                         arr[j] = arr[j+1];
                         arr[j+1] = aux;
                    }
               }
          }
     }else{//de mayor a menor
          for(int i= 0; i<length; ++i){
               for(int j=0; j<length-1; ++j){
                    if(arr[j] < arr[j+1]){
                         aux = arr[j];
                         arr[j] = arr[j+1];
                         arr[j+1] = aux;
                    }
               }
          }
     }
     return &arr[0];
}
