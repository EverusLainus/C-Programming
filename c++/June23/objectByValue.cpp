//safest way of passing object as a value is using copy constructor
#include <iostream>

using namespace std;

class Class {
    int i_stay;
	int *i_change;
public:
	Class(int value) 
	{
        cout <<"i use constructor"<<endl;
		 i_change = new int;
		*i_change = value;
        i_stay=value;
	}
    
//   Class(Class &source)
//	{ 
//       cout <<"i use object constructor"<<endl;
//		 i_change = new int;
//		*i_change = source.i_change_value();
//       i_stay=source.i_change_value();
//	}

	void increment()
	{ 
		(*i_change)++; 
        i_stay++;

	}
	int i_change_value()
	{ 
		return *i_change; 
	}
    int i_stay_value()
	{ 
		return i_stay; 
	}
};

int main()
{
	Class o1(123);
	Class o2 = o1;//uses copy constructor with object parameter
	Class o3(o2); 
    //value is a pointer; no modification by members is applied
    Class o4(o1.i_change_value());

    //before increament
    cout << "value before increament "<<o1.i_change_value() <<" ";
	cout << o2.i_change_value() << " ";
	cout << o3.i_change_value() << " "<<o4.i_change_value()<<endl;

//incrementing o1 value
    o1.increment();

//check if o1 methods affect copies	
    //value that changes
	cout << "value is a pointer "<<o1.i_change_value() <<" ";
	cout << o2.i_change_value() << " ";
	cout << o3.i_change_value() << " "<<o4.i_change_value()<<endl;

    //value that stays
	cout <<"value not a pointer " <<o1.i_stay_value() <<" ";
	cout << o2.i_stay_value() << " ";
	cout << o3.i_stay_value() << " "<<o4.i_stay_value()<<endl;
    return 0;  
}

/*
output:
$when used with copy constructor with object as parameter
i use constructor
i use object constructor
i use object constructor
i use constructor
value before increament 123 123 123 123
value is a pointer 124 123 123 123
value not a pointer 124 123 123 123

$without any object constructor
i use constructor
i use constructor
value before increament 123 123 123 123
value is a pointer 124 124 124 123
value not a pointer 124 123 123 123

#we get the original cloned of o1 cloned only in o4
but the o4 method is error prone. we might easily forget it

-----
to clone object- make a copy constructor with object as parameter
then pass object to clone
*/