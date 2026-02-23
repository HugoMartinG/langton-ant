#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <vector>
#include <string>
#include "tape.hpp"
#include "ant.hpp"

class Simulator {
private:
    Tape tape_;
    std::vector<Ant*> ants_;

public:
    Simulator(const std::string& filename);
    ~Simulator();
    friend std::ostream& operator<<(std::ostream& os, const Simulator& sim);


    void Run();
};

#endif
