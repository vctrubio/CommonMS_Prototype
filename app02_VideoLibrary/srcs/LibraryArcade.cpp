#include "../incl/Library.hpp"

void        Library::arcade()
{
	string  input;

    for (int i = 1; i <= 20; i += 6)
    {
        cout << string(i, '*') << endl;
        if (i == 1)
            cout << GREEN << "Entering\n" << ENDC;
        if (i == 7)
            cout << GREEN << "Arcade\n" << ENDC;
        if (i == 13)
            cout << GREEN << "Mode\n" << ENDC;
        this_thread::sleep_for(chrono::milliseconds(600));
    }

    if (filesystem::exists("cube"))
    {
        cout << GREEN << "What ID do you want to play?\n" << ENDC;
        cout << "**********************************|\n";
    }
    else
    {
        cout << RED << "ERROR: "<< ENDC << " ./cube executable game not found.\n";
        this_thread::sleep_for(chrono::seconds(1));
        return ;
    }    
    
    while (getline(cin, input))
    {
        if (input.size() > 0)
        {
            try
            {
                int id = stoi(input);
                int count = 1;
                for (auto i : rGames())
                {
                    if (id == count)
                    {
                        string  cmd = "./cube " + randDiff() + " " + i->name();
                        int     score = system(cmd.c_str());
                        i->addGame(_userName, score);
                    }
                    count++;
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                this_thread::sleep_for(chrono::seconds(1));
            }
            break;
        }
        cout << "|";
    }
}


string     randDiff()
{
    random_device rd;
    mt19937 rng(rd());

    int minDifficulty = 2;
    int maxDifficulty = 9;

    uniform_int_distribution<int> distribution(minDifficulty, maxDifficulty);
    int difficulty = distribution(rng);

    return to_string(difficulty);
}