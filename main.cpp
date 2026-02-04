#include <iostream>
#include <fstream>
#include <string>
#include "include/tape.hpp"
#include "include/ant.hpp"
#include "include/simulator.hpp"


void printUsage() {
    std::cout << "Uso: ./hormiga input/entrada1.txt" << std::endl;
    std::cout << "Formato de entrada:" << std::endl;
    std::cout << "size_x size_y" << std::endl;
    std::cout << "ant_x ant_y direction" << std::endl;
    std::cout << "x1 y1" << std::endl;
    std::cout << "x2 y2" << std::endl;
    std::cout << "..." << std::endl;
    std::cout << "Cada par (xi, yi) representa una celda negra en la cinta." << std::endl;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "Uso: ./hormiga input/entrada1.txt" << std::endl;
        printUsage();
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cout << "Error al abrir el fichero de entrada." << std::endl;
        return 1;
    }

    int size_x, size_y;
    file >> size_x >> size_y;

    int ant_x, ant_y, dir;
    file >> ant_x >> ant_y >> dir;

    Tape tape(size_x, size_y);

    int x, y;
    while (file >> x >> y) {
        tape.SetBlack(x, y);
    }

    Ant ant(ant_x, ant_y, static_cast<Direction>(dir));

    Simulator simulator(tape, ant);

    simulator.Run();

    // Guardar el estado final
    static int output_counter = 1;
    std::string output_name = "output/output" + std::to_string(output_counter) + ".txt";
    output_counter++;

    simulator.SavePrompt(output_name);

    std::cout << "Estado guardado en: " << output_name << std::endl;

    return 0;
}
