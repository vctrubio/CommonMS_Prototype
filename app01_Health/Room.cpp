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

// string Room::print()
// {
//     string rtn;

//     rtn += "Room Number: " + to_string(_nb) + "\n";
//     // os << "Availability: " << (_available ? "Available" : "Occupied") << std::endl;
//     // if (!_appointment) {
//     //     os << "Appointment Details: " << *(_appointment) << std::endl;
//     // }
//     return rtn;
// };