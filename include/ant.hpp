#ifndef ANT_HPP
#define ANT_HPP

#include "tape.hpp"

enum class Direction { LEFT, RIGHT, UP, DOWN };

class Ant {
protected:
    int x_, y_;
    Direction dir_;

public:
    Ant(int x, int y, Direction d) : x_(x), y_(y), dir_(d) {}
    virtual ~Ant() {}

    virtual void Move(Tape& tape) = 0;   // método abstracto
    virtual char GetSymbol() const = 0;

    void TurnLeft();
    void TurnRight();
    void StepForward();

    int GetX() const { return x_; }
    int GetY() const { return y_; }
};


// ===== Hormiga DI =====
class Ant_DI : public Ant {
public:
    Ant_DI(int x, int y, Direction d);

    void Move(Tape& tape) override;
    char GetSymbol() const override { return 'A'; }
};


// ===== Hormiga DDII =====
class Ant_DDII : public Ant {
public:
    Ant_DDII(int x, int y, Direction d);

    void Move(Tape& tape) override;
    char GetSymbol() const override { return 'B'; }
};

#endif
