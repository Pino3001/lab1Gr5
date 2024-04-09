#include "Empresa.h"
#include <string>
#include "iostream"
using namespace std;
int main(){
    Empresa e = Empresa("string nombre", "string nombre_legal", 15);
    cout << e.getNombre()<< "\n";
    return 0;
}