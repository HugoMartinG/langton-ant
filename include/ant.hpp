#ifndef ANT_
#define ANT_

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "tape.hpp"

enum Direction { LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3 };

class Ant {
    private:
        int x_, y_; // Posición actual de la hormiga
        Direction direccion_; // Dirección actual de la hormiga
    
    public:
        //Constructores Y destructor
        Ant(int x0, int y0, Direction d) : x_(x0), y_(y0), direccion_(d) {}
        Ant() : x_(0), y_(0), direccion_(UP) {}
        ~Ant() {}
    
        // Métodos
        bool Move(Tape& tape);
        void TurnLeft();
        void TurnRight();
        void StepForward();

        friend std::ostream& operator<<(std::ostream& os, const Ant& a);

        //Getters
        int GetX() { return x_; }
        int GetY() { return y_; }
        Direction GetDir() { return direccion_; }
    };
    
#endif