#include <iostream>
#include <fstream>
#include <sstream>
#include "simulator.hpp"
#include <thread>
#include <chrono>


void Simulator::Run() {
    while (true) {
        system("clear");
        for (int y = 0; y < tape_.GetSizeY(); y++) {
            for (int x = 0; x < tape_.GetSizeX(); x++) {
                if (x == ant_.GetX() && y == ant_.GetY()) {
                    std::cout << ant_;
                } else {
                    std::cout << (tape_.GetCell(x,y) ? 'X' : ' ');
                }
            }
            std::cout << "\n";
        }
        std::cout << "Steps: " << steps_ << std::endl;
        if (!ant_.Move(tape_)) {
            break; // La hormiga ha salido de los límites
        }
        steps_++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }  
}

void Simulator::SavePrompt(const std::string& filename) {
    std::ofstream out(filename);

    tape_.save(out);

    out << ant_.GetX() << " " 
        << ant_.GetY() << " " 
        << ant_.GetDir() << std::endl;

    out.close();
}



