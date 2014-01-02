#include "State.hpp"

State::State(fsm::Q type_, std::string description_ = "No description")
    : type(type_), description(description_)
{

}

std::ostream & operator << (std::ostream & out, const State & s)
{
    return out << s.description;
}
