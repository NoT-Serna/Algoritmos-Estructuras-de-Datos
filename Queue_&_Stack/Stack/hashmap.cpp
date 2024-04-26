#include "hashmap.h"
#include <iostream>
#include <string>
#include <cassert>

class Inventario {
public:
    // Agrega una cierta cantidad de un producto al inventario.
    void agregarProducto(const std::string& codigo, int cantidad) {
        inventario.put(codigo, cantidad);
    }

    // Elimina un producto del inventario.
    void eliminarProducto(const std::string& codigo) {
        inventario.remove(codigo);
    }

    // Devuelve la cantidad disponible de un producto.
    int obtenerCantidad(const std::string& codigo) const {
        try {
            return inventario.get(codigo);
        } catch (const std::runtime_error&) {
            return 0;
        }
    }

    // Realiza una venta.
    void realizarVenta(const std::string& codigo, int cantidad) {
        if (existeProducto(codigo)) {
            int disponible = obtenerCantidad(codigo);
            if (disponible >= cantidad) {
                inventario.put(codigo, disponible - cantidad);
            } else {
                std::cout << "Stock insuficiente para el producto " << codigo << ". Venta cancelada.\n";
            }
        } else {
            std::cout << "El producto " << codigo << " no está disponible en el inventario. Venta cancelada.\n";
        }
    }

    // Verifica si un producto existe en el inventario.
    bool existeProducto(const std::string& codigo) const {
        return inventario.contains(codigo);
    }

    // Compara la cantidad actual de un producto con una cantidad dada.
    bool compararCantidad(const std::string& codigo, int cantidad) const {
        return obtenerCantidad(codigo) == cantidad;
    }

    // Imprime el estado actual del inventario.
    void imprimirInventario() const {
        std::cout << "Inventario:\n";
        for (const auto& pair : inventario) {
            std::cout << "Producto: " << pair.first << ", Cantidad: " << pair.second << "\n";
        }
    }

private:
    HashMap<int> inventario; // HashMap para almacenar el inventario
};

void realizarPruebas() {
    Inventario inventario;

    std::cout << "Iniciando pruebas...\n";

    // Test 1: Agregar productos
    inventario.agregarProducto("A001", 20);
    inventario.agregarProducto("A002", 15);
    inventario.agregarProducto("A003", 30);
    assert(inventario.compararCantidad("A001", 20) && "Test 1.1 fallido: cantidad incorrecta para A001");
    assert(inventario.compararCantidad("A002", 15) && "Test 1.2 fallido: cantidad incorrecta para A002");
    assert(inventario.compararCantidad("A003", 30) && "Test 1.3 fallido: cantidad incorrecta para A003");
    std::cout << "Test 1 pasado.\n";

    // Test 2: Obtener cantidad
    assert(inventario.obtenerCantidad("A001") == 20 && "Test 2.1 fallido: cantidad incorrecta para A001");
    assert(inventario.obtenerCantidad("A004") == 0 && "Test 2.2 fallido: cantidad incorrecta para A004 (producto no existe)");
    std::cout << "Test 2 pasado.\n";

    // Test 3: Realizar venta
    inventario.realizarVenta("A001", 10);
    inventario.realizarVenta("A002", 20);  // Debería mostrar mensaje de stock insuficiente
    inventario.realizarVenta("A004", 5);   // Debería mostrar mensaje de producto no disponible
    assert(inventario.compararCantidad("A001", 10) && "Test 3.1 fallido: cantidad incorrecta para A001 después de la venta");
    assert(inventario.compararCantidad("A002", 15) && "Test 3.2 fallido: cantidad incorrecta para A002 después de la venta fallida");
    std::cout << "Test 3 pasado.\n";

    // Test 4: Eliminar producto
    inventario.eliminarProducto("A003");
    inventario.eliminarProducto("A004");  // Debería mostrar mensaje de producto no existe
    assert(!inventario.existeProducto("A003") && "Test 4.1 fallido: A003 debería haber sido eliminado");
    std::cout << "Test 4 pasado.\n";

    std::cout << "Todas las pruebas han sido superadas.\n";
}

int main() {
    realizarPruebas();
    return 0;
}
