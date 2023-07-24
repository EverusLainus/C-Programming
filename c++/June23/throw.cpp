//try "throw " instruction
#include<iostream>
using namespace std;

float Div(float a, float b)
{
	if(b == 0.0){
	    throw string("I can’t believe - division by zero :(");
	}
		
	return a / b;
}

int main(){
    try{
        float result = Div(2,0);
    }
    catch(string &problem){
        cout<<problem <<endl;
    }     
    return 0;
}