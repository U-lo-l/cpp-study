#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct donators {
	char name[20];
	double money;
};

int main() {
	ifstream inFile;
	inFile.open("donation.txt");

	if (!inFile.is_open())
	{
		cout << "파일을 열 수 없습니다." << endl;
		cout << "프로그램을 종료합니다." << endl;
		exit(EXIT_FAILURE);
	}

	int total_people;
	inFile >> total_people;
	inFile.get();
	cout << "total people : " << total_people << endl;

	if (total_people) {
		donators* list = new donators[total_people];

		for (int i = 0; i < total_people; i++)
		{
			inFile.getline(list[i].name, 20);
			inFile >> list[i].money;
			inFile.get();
		}
		cout << "||고액기부자||" << endl;
		for (int i = 0; i < total_people; i++)
			if (list[i].money > 10000)
				cout << list[i].name << endl;

		cout << "||소액기부자||" << endl;
		for (int i = 0; i < total_people; i++)
			if (list[i].money <= 10000)
				cout << list[i].name << endl;

		inFile.close();
		delete[] list;
	}
	else
		cout << "기부자가 없습니다." << endl;
	return 0;
}