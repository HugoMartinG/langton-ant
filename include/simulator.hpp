#ifndef SIMULATOR_
#define SIMULATOR_

#include "tape.hpp"
#include "ant.hpp"

class Simulator {
    private:
        Tape tape_; //cinta
        Ant ant_; // hormiga
        int steps_; //pasos realizados
    
    public:
        // Constructores
        Simulator(Tape t, Ant a) : tape_(t), ant_(a), steps_(0) {}
        Simulator() : tape_(), ant_(), steps_(0) {}


        void Run();
        void SavePrompt(const std::string& filename);
    };

#endif