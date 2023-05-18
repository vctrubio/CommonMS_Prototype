#include "Room.hpp"

string Room::info()
{
    ostringstream os;
    os  << "Room Number: " << _nb << std::endl;
    os  << (_available ? "Available" : "Occupied") << std::endl;
    if (_appointment != nullptr) {
        os << "Appointment Details: " << *(_appointment) << std::endl;
    }
    return os.str();
};

void	Room::check()
{cout << "WE HAVE.. " << _appointment->getTime() << " and is " << _available << " tonight.\n";};
