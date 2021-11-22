#include <iostream>
#include <windows.h>
#include "ListaDuplamenteEncadeada.cpp"
 
using namespace std;
 
int main() {
    // Double-Threaded List
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
 
    TipoLista lista;
    Apontador x;
    TipoItem item;

    CriaListaVazia(&lista);
    
    int opcao_menu;
    do {
        Menu();
        cout << "  \n        Escolha uma opção: ";
        cin >> opcao_menu;
        system ("cls");
        switch (opcao_menu) {
              case 1:   break;   
              case 2:   break; 
              case 3:   break;
              case 4:   break;
              case 5:   break;
         }
    } while (opcao_menu!=5); 

    return 0;
}