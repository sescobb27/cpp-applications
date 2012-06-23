#include<iostream>
#include<vector>

using namespace std;

typedef vector< vector<int> > Matriz;
typedef vector<int> Array;
int sumaColumna(Matriz &matriz,int);
//void printMatriz(int matriz[5][5]){
//     for(int i=0; i<5; ++i){
//          for(int j=0; j<5; ++j){
//               cout << "[" << matriz[i][j] << "]";
//          }
//          cout<<"\n";
//     }
//}

void printVector(Matriz &matriz){
int fila = 0,columna = 0;
     for(int i=0; i<matriz.size(); ++i){
          for(int j=0; j<matriz[0].size(); ++j){
//               cout << "[" << matriz[i][j] << "]";
               cout << "[" << matriz.at(i).at(j) << "]";
               fila += matriz.at(i).at(j);
          }
          columna = sumaColumna(matriz, i);
          cout << " suma por fila= " << fila << ", suma por columna= " << columna;
          columna = 0;
          fila = 0;
          cout <<"\n";
     }
}

int sumaColumna(Matriz &matriz, int columna){
int cont=0;
     for(int j=0; j<matriz[0].size(); ++j){
          cont += matriz.at(j).at(columna);
     }
     return cont;
}

int main(){
//    int matriz[5][5];
//     int num;
//     for(int i=0; i<5; ++i){
//          for(int j=0; j<5; ++j){
//               cin >> num;
//               matriz[i][j] = num;
//          }
//     }
//     printMatriz(matriz);
//     return 0;
     int filas, columnas;
     Matriz matriz;
     cout << "cantidad de filas:\n";
     cin >> filas;
     cout << "cantidad de columnas:\n";
     cin >> columnas;
     Array arr(columnas);     
     for(int i=0; i<filas; ++i){
          for(int j=0; j<columnas; ++j){
               cin >> arr[j];
          }
          matriz.push_back(arr);
     }
     printVector(matriz);
     return 0;
}
