#include "Appointment.hpp"


bool surgeryPro() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    double probability = 4.0 / 5.0;
    return dis(gen) < probability;
}

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
