#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


const int cow_size = 100;
const int days = 7;



struct cow
{
	int id;
	int time[days][2];
	double total;
	int low_yeild;
};


void record_yeild(cow arr[], int count)
{
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "yields for cow " << arr[i].id << endl;
		

		for (int j = 0; j < days; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				cout << "Enter milkings for day" << ": " << j+1 <<(k==0 ?  " yeild 1" : " yeild 2") <<": ";

				cin >> arr[i].time[j][k];
				arr[i].total += arr[i].time[j][k];

				if (arr[i].time[j][k] < 12)
				{
					arr[i].low_yeild++;
				}

			}

		}

	}

}


void stats(cow arr[],int count)
{
	cout << endl;
	double volume = 0;

	for (int i = 0; i < count; i++)
	{

		volume += arr[i].total;

	}

	double average = volume / (count * days * 2);
	
	cout << "Total weekly volume of herd : " <<  fixed << setprecision(1) << volume <<endl;
	
	cout << "Average yield per cow : "  << fixed << setprecision(1) << average << endl;

}


void production(cow arr[], int count)
{

	double max = 0;
	int productive = -1;

	for (int i = 0; i < count; i++)
	{
		if (arr[i].total >= max)
		{

			max = arr[i].total;
			productive = i;
		}
		
	}
	if (productive != -1)
	{
		cout << "most productive cow is " << arr[productive].id << " with total yeild of : " << arr[productive].total << endl;


	}
	else
	{
		cout << "no data" << endl;
	}


	for (int i = 0; i < count; i++)
	{

		if (arr[i].low_yeild >= 4)
		{

			cout << arr[i].id << " cow has produced less than 12 liters in 4 or morre days " << endl;
		}


	}
	



}


int main()
{
	cow arr[cow_size];
	int count;

	do
	{
	    cout << "enter no. of cows : ";
	    cin >> count;

	
		if (count > 100 || count < 1)
		{
			cout << "invalid cows number enter number which is (<100 and >1)" << endl;
			
		}

	} while (count <= 0 || count > 100);


	for (int i = 0; i < count; i++)
	{
		arr[i].total = 0;
		arr[i].low_yeild = 0;

		do
		{
			

			cout << "enter 3 digit id for cow " << i + 1 << ": ";
			cin >> arr[i].id;


			if (arr[i].id < 100 || arr[i].id > 999)
			{
				cout << "invalid id enter 3 digit id" << endl;
				
			}

		} while (arr[i].id < 100 || arr[i].id > 999);


	}

	record_yeild(arr, count);
	stats(arr, count);
	production(arr, count);

	return 0;

}
