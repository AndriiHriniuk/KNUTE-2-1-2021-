#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Person 
{
private:

public:
	string Name;
	int salary;
	Person()
	{
		salary = 0;
	}
	Person(int Name1, int salary1)
	{
		Name = Name1;
		salary = salary1;
	}
	void setName(string Name1)
	{
		Name = Name1;
	}
	void setSalary(int salary1)
	{
		salary = salary1;
	}
	void setPerson(string Name1, int salary1)
	{
		Name = Name1;
		salary = salary1;
	}
	string getName()
	{
		return Name;
	}
	int getSalary()
	{
		return salary;
	}
	~Person()
	{
		cout << "destructor" << endl;
	}
};

int main(int argc, char** argv)
{
	int i = 0;
	int k = 0;
	int salary = 0;
	string Name;
	Person masP[10];
	Person masNew[9];
	
	ifstream fin("D:\\Download\\cpp.txt");
	fin >> k;
	
	cout << k << endl;
	
	while (i < k)
	{		
		fin >> Name >> salary;
		//cout << Name << " " << salary << endl;
		masP[i].Name = Name;
		masP[i].salary = salary;
		cout << masP[i].Name << " " << masP[i].salary << endl;
		i++;
	}
	int i, j = 0;
	int max = 0;
	string l;
	while (i <= 9)
	{
		while (j <= 9)
		{
			if (max < masP[j].salary)
			{
				max = masP[i].salary;
				l = masP[i].Name;

			}
			j++;
			masP[i].salary
		}
		i++;
	}

	fin.close();
	return 0;
}