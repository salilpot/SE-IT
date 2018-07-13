#include<iostream>
using namespace std;
class Data
{
private:
	int DAY_OF_MONTH;
	int HIGHTEMP;
	int LOWTEMP;
	int AMOUNT_RAIN;
	int AMOUNT_SNOW;
public:
	Data(){                     //This is a default constructor called by itself when object is created.
          DAY_OF_MONTH=0;
          HIGHTEMP=0;
	 	  LOWTEMP=0;
	 	  AMOUNT_RAIN=0;
	 	  AMOUNT_SNOW=0;    
	}

	void Input(){
			cout<<"Enter day:";
			cin>>DAY_OF_MONTH;
			cout<<"Enter high temperature(°C):";
	        cin>>HIGHTEMP;
	        cout<<"Enter low temperature(°C):";
	        cin>>LOWTEMP;
	        cout<<"Enter amount of rain(mm):";
	        cin>>AMOUNT_RAIN;
	        cout<<"Enter amount of snow(cm):";
	        cin>>AMOUNT_SNOW;
	        Step();
	}

	void Display(){
		
			cout<<"Day:"<<DAY_OF_MONTH<<endl;
			cout<<"High temp(°C):"<<HIGHTEMP<<endl;
			cout<<"Low temp(°C):"<<LOWTEMP<<endl;
			cout<<"Amount of rain(mm):"<<AMOUNT_RAIN<<endl;
			cout<<"Amount of snow(cm):"<<AMOUNT_SNOW<<endl;
			Step();
	}

	void ModifyData(Data D[100],int n){
        int DAY;
        cout<<"Enter day for which you want to modify the data:";
        cin>>DAY;
        for(int i=1;i<=n;i++){
            D[i].Display();
        }
        for(int i=0;i<n;i++){
        	if(DAY==D[i].DAY_OF_MONTH){
        		D[i].Input();
        		cout<<"Modified Data is:"<<endl;
        		D[i].Display();
        	}
        }
	}

	inline void Step(){
		cout<<"**************************"<<endl;
	}

	void MONTH_REPORT(Data D[100],int n){       //Generates monthly report as average.
		int sumH=0,sumL=0,sumR=0,sumS=0;
		float avgH,avgL,avgR,avgS;
		cout<<"REPORT:"<<endl;
		cout<<"Number of days:"<<n<<endl;
		for(int i=1;i<=n;i++){
               sumH+=D[i].HIGHTEMP;
               sumL+=D[i].LOWTEMP;
               sumR+=D[i].AMOUNT_RAIN;
               sumS+=D[i].AMOUNT_SNOW;
		}
		avgH = sumH/n;
		cout<<"Average high temperature:"<<avgH<<endl;
		avgL = sumL/n;
		cout<<"Average low temperature:"<<avgL<<endl;
		avgR = sumR/n;
		cout<<"Average rainfall(mm):"<<avgR<<endl;
		avgS = sumS/n;
        cout<<"Average snowfall(cm):"<<avgS<<endl;
	}
};

int main(){
	Data D2;
	Data D[100],*ptr[100];
	int n,choice;
	char ch;
	cout<<"Enter number of days:";
	cin>>n;
	for(int i=1;i<=n;i++){
		ptr[i]=&D[i];
	}
	do{
		cout<<"Enter choice:\n1.Enter Data.\n2.Display all data.\n3.Modify Data\n4.Generate monthly report\n";
		cin>>choice;
        switch(choice)
        {
        	case 1:
        	{
        		for(int i=1;i<=n;i++){
		              ptr[i]->Input();
	            }
	            break;
        	}
        	case 2:
        	{
        		cout<<"Entered Data is:"<<endl;
	            for(int i=1;i<=n;i++){
                      ptr[i]->Display();
                }
                break;
        	}
        	case 3:
        	{
        		D2.ModifyData(D,n);
        		break;
        	}
        	case 4:
        	{
        		D2.MONTH_REPORT(D,n);
        		break;
        	}
        	default:
        	{
        		cout<<"Invalid input.Please try again.."<<endl;
        		break;
        	}
        }
        cout<<"Want to try again?(Y/y):";
        cin>>ch;
	}while(ch=='Y' || ch=='y');    
}