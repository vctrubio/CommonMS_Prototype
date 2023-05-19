#ifndef UI_HPP
#define UI_HPP

#include "../Headers.hpp"
#include "Library.hpp"

void	welcome();
void	box(vector<tuple<int, string>> obj, int &index);
void	putLine(string &out, char c);
void	putLeft(string in, string &out, char c);
void	putUnderScore(string &out);
char	itStr(const char **str, int limit);
int     strCheck(string s1, string s2);
#endif
