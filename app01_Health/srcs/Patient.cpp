#include "../incl/Patient.hpp"

unsigned int Patient::s_count = 1;

void uiPatient(Patient *ptr)
{
    string input;

    if (!ptr || ptr->isArchive())
        return;

    if (ptr->ingr())
        cout << RED;
    else
        cout << GREEN;
    cout << ptr->name() << ENDC << " |'archive', 'alta', 'baja', 'back'\n";
    for (auto *appointment : ptr->appointments())
        cout << appointment << endl; //cannot dereference. idk Y.
    cout << "\n>";

    while (getline(cin, input))
    {
        if (input.length() > 0)
        {
            if (input == "back")
                break;
            else if (input == "archive")
            {
                ptr->archive();
                break;
            }
            else if (input == "alta")
                ptr->alta();
            else if (input == "baja")
                ptr->baja();
        }
        if (ptr->ingr())
            cout << RED;
        else
            cout << GREEN;
        cout << ptr->name() << ENDC << " |'archive', 'alta', 'baja', 'back'\n>";
    }
}

string Patient::rtnCsv()
{
    string str = to_string(_id) + "," + _name + "," + (_ingr ? "true" : "false") + "," + (_archived ? "true" : "false") + "\n";
    return str;
}

Patient::~Patient()
{
    cout << RED << "-1" << ENDC " Patient: " << _name << endl;
}