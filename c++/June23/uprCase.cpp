#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string the_string = "A";

	for (int i = 0; i < the_string.length(); i++)
		the_string[i] = the_string[i] - 'a' + 'A';
	cout << the_string << endl;
}