#include"Function.h"
#include<locale>
struct trainer {
	string name;
	int tren;
};
void DataInitializatiom() {
	ofstream _buf("file.txt");
	if (!_buf) {
		cout << "������ �������� �����!" << endl;
		_buf.close();
	}
}

//void DataEntryUser() {
//	string UserFirstName;
//	string Pasword;
//	ofstream record("fileUsers.txt", ios::app);
//	if (record) {
//		cout <<  "������� � ���� ����������!" << endl;
//		cout << "������� ���� �����" << endl;
//		cin >> UserFirstName;
//		cout << "\n������� ���� ������" << endl;
//		cin >> Pasword;
//		record << UserFirstName << endl;
//		record << Pasword << endl;
//	}
//	else {
//		cout << "���� �� ��������!" << endl;
//	}
//}
int countOfUsers=0;
bool VerifyUserCredentials() {
	string enteredUsername; string enteredPassword;int tren;
	cout << "������� �����" << endl;
	cin >> enteredUsername;
	cout << "������� ������" << endl;
	cin >> enteredPassword;
	ifstream file("fileUsers.txt");
	if (!file) {
		cout << "������ ��� �������� �����!" << endl;
		return false;
	}

	string storedUsername, storedPassword;
	while (file >> storedUsername >> storedPassword) {
		countOfUsers++;
		file >> tren;
		if (enteredUsername == storedUsername && enteredPassword == storedPassword) {
			cout << "������ ��������. ����� ����������, " << enteredUsername << "!" << endl;
			cout << "���� ������ ������: " << endl;
			cout << "���� ���: "<<enteredUsername<<"!" << endl;
			cout << "���� ���-�� ������� �� ����������: " << tren << "!" << endl;
			return true;
		}
	}

	cout << "�������� ������� ������. ���������� �����." << endl;
	return false;
}

bool DataEntryAdmin() {
	string PaswordForAdmin;
		cin >> PaswordForAdmin;
		ifstream file("PaswordAdmin.txt");
		if (!file) {
			cout << "������ ��� �������� �����!" << endl;
			return false;
		}
		string secretPasword;
		while (file >> secretPasword) {
			if (PaswordForAdmin == secretPasword) {
				cout << "����� ���������� �����!" << endl;
				return true;
			}
			else {
				cout << "������ ������ �������!" << endl;
				return false;
			}
		}
}

void PrintUsers() {
	ifstream file("fileUsers.txt");
	string usersLogin;
	string usersPasword;
	int couter=1;
	if (file) {
		while (file >> usersLogin>>usersPasword) {
			cout << "������������ ����� " << couter << "-" << usersLogin << endl;
			cout << "������ ������������ ����� " << couter << "-" << usersPasword<< endl;
			couter++;
		}
	}
	else {
		cout << "���� �� ������!" << endl;
	}
}

//�������

void DataInitializatiomTrener() {
	ofstream _buf("Treners.txt");
	if (!_buf) {
		cout << "������ �������� �����!" << endl;
	}
	_buf.close();
}

void DataTrainers() {
	string name;
	int tren;
	int n;

	cout << "������� ���-�� ������" << endl;
	cin >> n;

	ofstream record("Trainers.txt", ios::app);

	if (record) {
		record << n << endl;
		for (int i = 0;i < n;i++) {
			cout << "�������� ��� �������" << endl;
			cin >> name;

			cout << "������� ���������� ����������" << endl;
			cin >> tren;

			record << name << endl;
			record << tren << endl;

			cout << "__________________________" << endl;
		}
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	record.close();
}

void PrintTrainers() {
	ifstream file("Trainers.txt");
	string name;
	int  tren,n;
	if (file) {
		file >> n;
		for (int i = n;i < n;i++) {
			file >> tren;
			file >> name;
			cout << "���������� � ������� ����� " << i+1 << endl;
			cout << "��� � �������: " <<name<< endl;
			cout << "���������� ����������: " <<tren<< endl;
		}
	}
	else {
		cout << "���� �� ������!" << endl;
	}
}

void Copy() {
	ifstream reading ("Trainers.txt");
	ofstream record("Trainers_Buffer.txt", ios::out);
	string name;
	int  tren, n;
	if (reading) {
		if (record) {
			reading >> n;
			record << n << endl;
			for (int i = 0;i < n;i++) {
				reading >> name;
				record << name << endl;

				reading >> tren;
				record << tren << endl;
			}
		}
	}
	reading.close();
	record.close();
}


int _n;

void ChangeRecords() {
	Copy();
	ifstream reading ("Trainers_Buffer.txt");
	ofstream record ("Trainers.txt",ios::out);

	if (reading) {
		if (record) {
			string name;
			int  tren, n,plus,result;
			
			reading >> n;
			cout << "�������� ����� ������� � �������� ������ ����������(�� 1 �� " << n << "):";
			cin >> _n;
			_n--;
			record << n << endl;

			for (int i = 0;i < n;i++) {
				if (i !=_n) {
					reading >> name;
					record << name << endl;

					reading >> tren;
						record << tren << endl;
				}
				else {
					reading >> name;
					reading >> tren;
					plus = tren;
					cout << "������� ��� ������� � �������� �� �� ������ ����������" << endl;
					cin >> name;
					cout << "������� ���������� ����������" << endl;
					cin >> tren;
					result = tren + plus;
					record << name << endl;
					record << result<< endl;
				}
			}
		}
	}
	reading.close();
	record.close();
}

void Raschet() {
	ifstream reading("Transport_Buffer.txt");
	int count,sum;
	string name;
	int tren;
	count = _n;
	_n--;
	for (int i = 0;i < count;i++) {
		if (i = _n) {
			reading >> name;
			reading >> tren;
			sum = tren;
			cout << sum<<endl;
		}
	}
}

#include <iostream>
#include <string>
#include <vector>

struct RouteInfoUser {
	std::string name;
	string pasword;
	int tren;
};
int quantityOfStructs;
void AdminAndUsers() {
	ofstream file("fileUsers.txt",ios::app);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count=0;
	
	std::cout << "������� ���������� ��������: ";
	std::cin >> quantityOfStructs;
	std::vector<RouteInfoUser> route;
	route.reserve(quantityOfStructs);

	for (int i = 0; i < quantityOfStructs; ++i) {
		count++;
		RouteInfoUser routeN;
		std::cout << "������� ���: ";
		std::cin >> routeN.name;
		std::cout << "������� ������: ";
		std::cin >> routeN.pasword;
		std::cout << "������� �������� ���������� �� ���������� � ������������: ";
		std::cin >> routeN.tren;
		route.push_back(routeN);
		file << count<<endl;
		file << routeN.name<<endl;
		file << routeN.pasword<<endl;
		file << routeN.tren<<endl;
	}

	std::cout << "��������� ���������:" << std::endl;
	for (const auto& r : route) {
		std::cout << "���: " << r.name << ", tren: " << r.tren << std::endl;
	}
}


/*cout << "������ ��������:\n1) ������ ������\n2) ������ ������\n3) ������ ����" << endl;
cout << "������������� ��������:\n������ - ����� �������� ����� � ���������\n������ - ���������� � �������������\n���� - �������������� ����� ������" << endl;
cout << "�������� ���� ����� (1, 2 ��� 3): ";*/
