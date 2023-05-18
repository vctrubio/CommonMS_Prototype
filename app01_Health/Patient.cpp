#include "Patient.hpp"

unsigned int Patient::s_count = 1;

void uiPatient(Patient *ptr) //this should be a typedef<T> so its compatible with Doctor
{
    string input;

    if (!ptr)
        return;
    cout << ptr;
    cout << "------------------------------------------n>";
    cout << "CMDS: archive, alta, baja, history, back\n>";

    while (getline(cin, input))
    {
        if (input.length() > 0)
        {
            if (input == "back")
                break;
            else if (input == "archive")
                ptr->archive();
            else if (input == "alta")
                ptr->alta();
            else if (input == "baja")
                ptr->baja();
            else if (input == "history")
            {
                int i = 0;
                // for (auto i : ptr->appointments())
                // {
                //     cout << ++i << i->getTime();
                //     //for now....
                // }
            }
        }
        else
            cout << ptr->name() << "|>";
    }
}

string Patient::rtnCsv()
{
    string str = to_string(_id) + "," + _name + "," + (_ingr ? "true" : "false") + "," + (_archived ? "true" : "false") + "\n";
    return str;
}
