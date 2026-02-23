#include "simulator.hpp"
#include "tape.hpp"
#include "ant.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Uso: ./hormiga <fichero_inicializacion>\n";
        return 1;
    }

    std::string filename = argv[1];

    // Inicializar simulador
    Simulator sim(filename);

    // Ejecutar simulación
    sim.Run();

    // Preguntar al usuario si quiere guardar el estado final
    std::cout << "¿Desea guardar el estado final en un fichero? (s/n): ";
    char opcion;
    std::cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        std::cout << "Nombre del fichero de salida: ";
        std::string outFile;
        std::cin >> outFile;

        std::ofstream out(outFile);
        if (!out) {
            std::cerr << "Error al abrir el fichero de salida.\n";
            return 1;
        }

        out << sim; // Sobrecarga del operador << en Simulator (hay que implementarla)
        out.close();
        std::cout << "Estado guardado en " << outFile << "\n";
    }

    return 0;
}
