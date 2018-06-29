#include<iostream>
using namespace std;
class Dimension
{
private:
	double a;
	double b;
public:
	void TInput()
	{
		cout<<"Enter base of triangle:";
		cin>>a;
		cout<<"Enter height of triangle:";
		cin>>b;
	}
	void RInput()
	{
		cout<<"Enter length of rectangle:";
		cin>>a;
		cout<<"Enter breadth of rectangle:";
		cin>>b;
	}

	void ComputeTA()
	{
		double res1;
		res1=((0.5)*(a)*(b));
		cout<<"Area of triangle is:"<<res1<<endl;
	}

	void ComputeRA()
	{
		double res2;
		res2=((a)*(b));
		cout<<"Area of rectangle is:"<<res2<<endl;
	}
};

int main()
{
	Dimension O1;
	int choice;
	cout<<"Select operation:\n1.Area of triangle\n2.Area of rectangle"<<endl;
	cin>>choice;

    switch(choice)
    {
    	case 1:
    	{
            O1.TInput();
            O1.ComputeTA();
            break;
    	}
        case 2:
        {
            O1.RInput();
            O1.ComputeRA();
        }

        default:
        {
        	cout<<"Invalid input.Please try again..."<<endl;
        }
    }
    return 0;
}
