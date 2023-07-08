#include <iostream>
using namespace std;
//implicit conversitions of datatype


int f(int x) 
{
    cout <<"x is "<<x<<endl;
	return x;
}

float g()					// example no. 5 
{
	return -1;
}

int main()
{
	int Int = 1;
	short Short = 2;
	long Long = 3;
	float Float = 4.0;
	double Double = 5.1;

	//Int+Short (1+2) gives 5
    cout <<"value of Int+Short is "<<Int+Short<<endl;
	Int = Int + Short;		// example no. 1
    
    cout <<"value of Int si "<<Int<<endl;

    //if condition return only 1 or 0 so double is converted into int
    //but replaced the original value
	if (Double){// example no. 2
        cout<<"double is "<<Double<<endl;
	     Double--;
         cout<<"double is "<<Double<<endl;
    }				
    
	Float = 1;				// example no. 3
    cout <<"Float becomes "<<Float<<endl;
    Float =9.8;
	f(Float);				// example no. 4
    cout <<"g() is "<<g()<<endl;
    return 0;
}

