#include <iostream>
#include <queue>
#include <string>
using namespace std;



class ColaDeImpresion {
    queue<string> docs;
    int size;
    
public:
    
    void agregarDocumento(string d){
        docs.push(d);
    }
    
    void imprimirDocumento(){
      while (!docs.empty()){
        cout << docs.front() << " ";
        docs.pop();
    }
        cout<<"la cola esta vacia";
        cout << endl;
    }
    
    int cantidadDeDocumentos(){
        return docs.size();
    }
    
    

};

int main() {
    ColaDeImpresion colaDeImpresion;

    cout << "Prueba 1: Agregar documentos y verificar la cantidad" << std::endl;
    colaDeImpresion.agregarDocumento("Documento 1");
    colaDeImpresion.agregarDocumento("Documento 2");
    
    if (colaDeImpresion.cantidadDeDocumentos() == 2) {
        cout << "Prueba 1 exitosa" << std::endl;
    } else {
        cout << "Prueba 1 fallida" << std::endl;
    }
    
    cout << "\nPrueba 2: Imprimir un documento" << std::endl;
    colaDeImpresion.imprimirDocumento(); // Debería imprimir "Documento 1"

    cout << "\nPrueba 3: Verificar la cantidad después de imprimir" << std::endl;
    if (colaDeImpresion.cantidadDeDocumentos() == 1) {
        cout << "Prueba 3 exitosa" << std::endl;
    } else {
        cout << "Prueba 3 fallida" << std::endl;
    }

    cout << "\nPrueba 4: Intentar imprimir con la cola vacía" << std::endl;
    colaDeImpresion.imprimirDocumento(); // Debería imprimir "Documento 2"
    colaDeImpresion.imprimirDocumento(); // Debería imprimir "La cola está vacía"
    return 0;
}
