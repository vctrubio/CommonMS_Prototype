#include "../incl/Library.hpp"

void    Library::newGame()
{
    string  input;
    string  genre;

	cout << GREEN << " Create a new game\n" << ENDC;
    cout << " What is the Title? [Or 'back' to go back]\n|";

	while(getline(cin, input))
    {
        if (input == "back")
			return ;
        else if (input.length() > 0)
        {
            cout << "What Genre. Pick by index.\n";
			cout << "[1] Educational\n[2] Violent\n[3] Mysterious\n[4] Other\n:";
           	while(getline(cin, genre))
			{
				if (genre.length() > 0)
				{
                    userAddGame(input, genre[0] - 48);
                    return ;
                }
                cout << "|";
			}
            return ;
        }
        cout << "|";
    }
}