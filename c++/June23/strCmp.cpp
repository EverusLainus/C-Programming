#include <iostream>
#include <string>

using namespace std;

int main() 
{
  string str1, str2;

  cout << "Enter 2 lines of text:" << endl;
  getline(cin, str1);
  getline(cin, str2);
  cout << "You've entered:'" << endl;
  if (str1 == str2)
    cout << "\"" << str1 << "\" == \"" << str2 << "\"" << endl;
  else if (str1 > str2)
    cout << "\"" << str1 << "\" > \"" << str2 << "\"" << endl;
  else
    cout << "\"" << str2 << "\" <\"" << str1 << "\"" << endl;
}