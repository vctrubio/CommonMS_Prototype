#include "../incl/Library.hpp"

string	Library::sortToStr(Sort mode)
{
	if (mode == AN)
		return "Ascending Title";
	if (mode == DN)
		return "Descending Title";
	if (mode == AS)
		return "Ascending Top Score";
	if (mode == DS)
		return "Descending Top Score";
	if (mode == GG)
		return "Ascending Genres";
	return "Common Managment Solutions";
}

Sort		getSort()
{
	string	input;
	string	output;

	putLine(output, '-');
	putLeft("|OPTIONS| 'AN' 'DN' on Name | 'AS' 'DS' on Score | 'GG' on Genre", output, 32);
	putLine(output, '-');
	cout << output << "|";

	while(getline(cin, input))
    {
        if (input == "/back")
			break;
		if (input == "AN")
			return AN;
		if (input == "DN")
			return DN;
		if (input == "AS")
			return AS;
		if (input == "DS")
			return DS;
		if (input == "GG")
			return GG;
		cout << "|";
    }
	return NM;
}
