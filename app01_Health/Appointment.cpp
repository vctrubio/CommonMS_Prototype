#include "Appointment.hpp"

string    dateToString(time_t date)
{
    char dateTimeStr[100];
    strftime(dateTimeStr, sizeof(dateTimeStr), "%Y-%m-%d %H:%M:%S", localtime(&date));
    return std::string(dateTimeStr);
}

vector<time_t>      generateRandomTimes()
{
    std::vector<time_t> randomTimes;
    
    time_t currentTime = time(nullptr);
    for (int i = 0; i < 4; ++i)
    {
        time_t randomTime = currentTime + (rand() % (3 * 24 * 60 * 60)); //NEEDS TO BE BETWEEN working hours....
        randomTimes.push_back(randomTime);
    }
    std::sort(randomTimes.begin(), randomTimes.end());
    std::cout << "Choose an appointment time:\n";
    for (int i = 0; i < 4; ++i)
    {
        char dateTimeStr[100];
        strftime(dateTimeStr, sizeof(dateTimeStr), "%d-%m-%Y %H:%M", localtime(&randomTimes[i]));
        std::cout << i + 1 << ". " << dateTimeStr << std::endl;
    }
    return randomTimes;
}

string	Appointment::csv()
{
	string str = to_string(_patient->id()) + "," + to_string(_doctor->id());
	return str;
}

Appointment::Appointment(Doctor *doctor, Patient *patient, Room *room):_doctor(doctor), _patient(patient)
{
    _status = false;

    vector<time_t>  times = generateRandomTimes();

    int choice;
    while (42)
    {
        cin >> choice;
        if (choice <= 4 && choice >= 1)
            break;
        cout << RED << "ERROR" << ENDC << " 1 2 3 or 4 \n";
    }
    _dateTime = times[choice - 1];
    dateTimeStr = dateToString(_dateTime);
    times.clear();
	cout << GREEN << "Appointment @ " << room->nb() << " => " << ENDC << patient->name() << " : " << doctor->name() << " : " << dateTimeStr << endl;
}
