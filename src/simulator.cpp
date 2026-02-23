#include "simulator.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>

// Convierte símbolo a Direction
Direction ParseDirection(char c) {
    if (c == '<') return Direction::LEFT;
    if (c == '>') return Direction::RIGHT;
    if (c == '^') return Direction::UP;
    return Direction::DOWN;
}

Simulator::Simulator(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error abriendo fichero\n";
        exit(1);
    }

    // Línea 1: tamaño de la cinta y número de colores
    int sizeX, sizeY, numColors;
    file >> sizeX >> sizeY >> numColors;
    tape_ = Tape(sizeX, sizeY, numColors);

    std::string line;
    std::getline(file, line); // limpiar salto

    // Línea 2: hormigas
    std::getline(file, line);
    std::stringstream ss(line);
    std::string token;

    while (std::getline(ss, token, ';')) {
        std::stringstream antStream(token);

        std::string type;
        int x, y;
        char dirChar;

        antStream >> type >> x >> y >> dirChar;

        Direction dir = ParseDirection(dirChar);

        if (type == "DI") {
            ants_.push_back(new Ant_DI(x, y, dir));
        }
        else if (type == "DDII") {
            ants_.push_back(new Ant_DDII(x, y, dir));
        }
        else {
            std::cerr << "Tipo de hormiga desconocido: " << type << std::endl;
        }
    }

    // Líneas 3..n: celdas no blancas
    int x, y, color;
    while (file >> x >> y >> color) {
        tape_.SetColor(x, y, static_cast<CellColor>(color));
    }
}

Simulator::~Simulator() {
    for (Ant* ant : ants_) {
        delete ant;
    }
}

// Ejecuta la simulación
void Simulator::Run() {
    bool inside = true;
    while (inside) { // Presiona 'q' para salir
        for (Ant* ant : ants_) {
            if (ant->GetX() < 0 || ant->GetX() >= tape_.GetSizeX() || ant->GetY() < 0 || ant->GetY() >= tape_.GetSizeY()) {
                inside = false; 
            }
        }
        system("clear");

        std::cout << "+";
        for (int i = 0; i < tape_.GetSizeX(); i++){
            std::cout << "-";
        }
        std::cout << "+\n";
        // Dibujar la cinta y las hormigas
        for (int y = 0; y < tape_.GetSizeY(); y++) {
            std::cout << "|";
            for (int x = 0; x < tape_.GetSizeX(); x++) {

                bool printed = false;

                for (Ant* ant : ants_) {
                    if (ant->GetX() == x && ant->GetY() == y) {
                        std::cout << ant->GetSymbol();
                        printed = true;
                        break;
                    }
                }

                if (!printed) {
                    //Imprimir el color de la celda
                    switch(tape_.GetColor(x, y)) {
                        case CellColor::White: std::cout << " "; break;
                        case CellColor::Black: std::cout << "\033[40m \033[0m"; break;
                        case CellColor::Red: std::cout << "\033[41m \033[0m"; break;
                        case CellColor::Green: std::cout << "\033[42m \033[0m"; break;
                        case CellColor::Blue: std::cout << "\033[44m \033[0m"; break;
                        case CellColor::Yellow: std::cout << "\033[43m \033[0m"; break;
                        case CellColor::Magenta: std::cout << "\033[45m \033[0m"; break;
                        case CellColor::Cyan: std::cout << "\033[46m \033[0m"; break;
                        case CellColor::Brown: std::cout << "\033[43m \033[0m"; break; // Usamos amarillo para marrón
                        default: std::cout << " "; break;
                    }


                }
            }
            std::cout << "|\n";
        }
        std::cout << "+";
        for (int i = 0; i < tape_.GetSizeX(); i++){
            std::cout << "-";
        }
        std::cout << "+\n";

        // Mover todas las hormigas
        for (Ant* ant : ants_) {
            ant->Move(tape_);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return;
}

std::ostream& operator<<(std::ostream& os, const Simulator& sim) {
    for (int y = 0; y < sim.tape_.GetSizeY(); ++y) {
        for (int x = 0; x < sim.tape_.GetSizeX(); ++x) {
            bool drawn = false;
            for (Ant* ant : sim.ants_) {
                if (ant->GetX() == x && ant->GetY() == y) {
                    os << ant->GetSymbol();
                    drawn = true;
                    break;
                }
            }
            if (!drawn)
                os << static_cast<int>(sim.tape_.GetColor(x, y));
        }
        os << "\n";
    }
    return os;
}
