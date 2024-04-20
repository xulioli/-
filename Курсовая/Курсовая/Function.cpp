#include"Function.h"
#include<locale>
struct trainer {
	string name;
	int tren;
};
void DataInitializatiom() {
	ofstream _buf("file.txt");
	if (!_buf) {
		cout << "ошибка создания файла!" << endl;
		_buf.close();
	}
}

//void DataEntryUser() {
//	string UserFirstName;
//	string Pasword;
//	ofstream record("fileUsers.txt", ios::app);
//	if (record) {
//		cout <<  "войдите в наше приложение!" << endl;
//		cout << "введите свой логин" << endl;
//		cin >> UserFirstName;
//		cout << "\nвведите свой пароль" << endl;
//		cin >> Pasword;
//		record << UserFirstName << endl;
//		record << Pasword << endl;
//	}
//	else {
//		cout << "файл не открылся!" << endl;
//	}
//}
int countOfUsers=0;
bool VerifyUserCredentials() {
	string enteredUsername; string enteredPassword;int tren;
	cout << "введите логин" << endl;
	cin >> enteredUsername;
	cout << "введите пароль" << endl;
	cin >> enteredPassword;
	ifstream file("fileUsers.txt");
	if (!file) {
		cout << "Ошибка при открытии файла!" << endl;
		return false;
	}

	string storedUsername, storedPassword;
	while (file >> storedUsername >> storedPassword) {
		countOfUsers++;
		file >> tren;
		if (enteredUsername == storedUsername && enteredPassword == storedPassword) {
			cout << "Доступ разрешен. Добро пожаловать, " << enteredUsername << "!" << endl;
			cout << "Ваши личные данные: " << endl;
			cout << "Ваше имя: "<<enteredUsername<<"!" << endl;
			cout << "Ваше кол-во занятий по абонименту: " << tren << "!" << endl;
			return true;
		}
	}

	cout << "Неверные учетные данные. Попробуйте снова." << endl;
	return false;
}

bool DataEntryAdmin() {
	string PaswordForAdmin;
		cin >> PaswordForAdmin;
		ifstream file("PaswordAdmin.txt");
		if (!file) {
			cout << "Ошибка при открытии файла!" << endl;
			return false;
		}
		string secretPasword;
		while (file >> secretPasword) {
			if (PaswordForAdmin == secretPasword) {
				cout << "добро пожаловать админ!" << endl;
				return true;
			}
			else {
				cout << "пароль введен неверно!" << endl;
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
			cout << "пользователь номер " << couter << "-" << usersLogin << endl;
			cout << "пароль пользователя номер " << couter << "-" << usersPasword<< endl;
			couter++;
		}
	}
	else {
		cout << "файл не открыт!" << endl;
	}
}

//тренера

void DataInitializatiomTrener() {
	ofstream _buf("Treners.txt");
	if (!_buf) {
		cout << "ошибка создания файла!" << endl;
	}
	_buf.close();
}

void DataTrainers() {
	string name;
	int tren;
	int n;

	cout << "введите кол-во данных" << endl;
	cin >> n;

	ofstream record("Trainers.txt", ios::app);

	if (record) {
		record << n << endl;
		for (int i = 0;i < n;i++) {
			cout << "ввведите имя тренера" << endl;
			cin >> name;

			cout << "введите количество тренировок" << endl;
			cin >> tren;

			record << name << endl;
			record << tren << endl;

			cout << "__________________________" << endl;
		}
	}
	else {
		cout << "ошибка открытия файла!" << endl;
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
			cout << "информация о тренере номер " << i+1 << endl;
			cout << "имя и фамилию: " <<name<< endl;
			cout << "количество тренировок: " <<tren<< endl;
		}
	}
	else {
		cout << "файл не открыт!" << endl;
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
			cout << "выберите номер тренера к которому хотите записаться(от 1 до " << n << "):";
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
					cout << "введите имя тренера к которому вы бы хотели записаться" << endl;
					cin >> name;
					cout << "введите количество тренировок" << endl;
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
	
	std::cout << "Введите количество структур: ";
	std::cin >> quantityOfStructs;
	std::vector<RouteInfoUser> route;
	route.reserve(quantityOfStructs);

	for (int i = 0; i < quantityOfStructs; ++i) {
		count++;
		RouteInfoUser routeN;
		std::cout << "Введите имя: ";
		std::cin >> routeN.name;
		std::cout << "Введите пароль: ";
		std::cin >> routeN.pasword;
		std::cout << "Введите значение тренировок по абонименту у пользователя: ";
		std::cin >> routeN.tren;
		route.push_back(routeN);
		file << count<<endl;
		file << routeN.name<<endl;
		file << routeN.pasword<<endl;
		file << routeN.tren<<endl;
	}

	std::cout << "Введенные структуры:" << std::endl;
	for (const auto& r : route) {
		std::cout << "Имя: " << r.name << ", tren: " << r.tren << std::endl;
	}
}


/*cout << "Список тренеров:\n1) Тренер Андрей\n2) Тренер Виталя\n3) Тренер Катя" << endl;
cout << "Специализация тренеров:\nАндрей - набор мышечной массы и похудение\nВиталя - подготовка к соревнованиям\nКатя - восстановление после травмы" << endl;
cout << "Сделайте свой выбор (1, 2 или 3): ";*/
