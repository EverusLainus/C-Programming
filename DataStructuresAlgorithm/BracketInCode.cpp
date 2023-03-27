#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;

//not used starter file
//according to algorithm from lectures

int main() {
    std::string text;
    getline(std::cin, text);
    stack <char> collection; //stack keeping open braces
    stack <int> position;//stack keeping index of open braces
    int i=0;
    char top ='a';

//track each letter of the string
    for(char c =text[i]; i < text.length() ; i++ ){
        c=text[i];
        
//there is a open braces: save letter and position
        if(c=='(' || c=='[' || c=='{'){
            collection.push(c);
            position.push(i);
        } 
//there is no open or close brackets: skip this i       
        else if(c!='(' && c!='[' && c!='{' && c!=')' && c!=']' && c!='}' ){
            continue;
        }
//if the collection is empty index+1
        else if(collection.empty()){
            cout <<i+1<<endl;
            return 0;
        }
//else compare top letter with recent position
        else{
            top = (char) collection.top();
            if((top =='(' && c!=')')|| (top =='[' && c!=']')|| (top =='{' && c!='}')){
                cout<<i+1<<endl;                
                return 0;
            }
            collection.pop();
            position.pop();
        }
    }
//every letter has a pair
    if(collection.empty()){
        cout<<"Success"<<endl;
    }
//there are brackets without pair
    else{
        cout<< position.top()+1;
    }
return 1;
}