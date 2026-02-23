#include "ant.hpp"
#include "tape.hpp"

// ===== Métodos base Ant =====

void Ant::TurnLeft() {
    switch (dir_) {
        case Direction::LEFT:  dir_ = Direction::DOWN; break;
        case Direction::DOWN:  dir_ = Direction::RIGHT; break;
        case Direction::RIGHT: dir_ = Direction::UP; break;
        case Direction::UP:    dir_ = Direction::LEFT; break;
    }
}

void Ant::TurnRight() {
    switch (dir_) {
        case Direction::LEFT:  dir_ = Direction::UP; break;
        case Direction::UP:    dir_ = Direction::RIGHT; break;
        case Direction::RIGHT: dir_ = Direction::DOWN; break;
        case Direction::DOWN:  dir_ = Direction::LEFT; break;
    }
}

void Ant::StepForward() {
    switch (dir_) {
        case Direction::LEFT:  x_--; break;
        case Direction::RIGHT: x_++; break;
        case Direction::UP:    y_--; break;
        case Direction::DOWN:  y_++; break;
    }
}


// ===== Ant_DI =====

Ant_DI::Ant_DI(int x, int y, Direction d) : Ant(x,y,d) {}

void Ant_DI::Move(Tape& tape) {
    if (x_ < 0 || x_ >= tape.GetSizeX() || y_ < 0 || y_ >= tape.GetSizeY()) {
        return;
    }
    CellColor color = tape.GetColor(x_, y_);

    switch (color) {
        case CellColor::White: TurnRight(); break;
        case CellColor::Black: TurnLeft(); break;
        default: break;
    }

    tape.NextColor(x_, y_);
    StepForward();
}


// ===== Ant_DDII =====

Ant_DDII::Ant_DDII(int x, int y, Direction d) : Ant(x,y,d) {}

void Ant_DDII::Move(Tape& tape) {
    if (x_ < 0 || x_ >= tape.GetSizeX() || y_ < 0 || y_ >= tape.GetSizeY()) {
        return;
    }

    CellColor color = tape.GetColor(x_, y_);
    switch (color) {
        case CellColor::White: TurnRight(); break;
        case CellColor::Black: TurnLeft(); break;
        case CellColor::Red:   TurnRight(); break;
        case CellColor::Green: TurnLeft(); break;
        default: break;
    }   
    tape.NextColor(x_, y_);
    StepForward();
}