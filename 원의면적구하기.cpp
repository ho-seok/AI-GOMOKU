
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
class cir
{
	int rad;
	string name;
public:
	void setcir(string name, int rad);
	double getArea();
	string getName();
};
void cir::setcir(string name, int rad) {
	this->name = name;
	this->rad = rad;
}
double cir::getArea() {
	return rad*rad*3.14;
}
string cir::getName() {
	return name;
}
class cirManager
{
	cir *p;
	int size;
public:
	cirManager(int size);
	~cirManager();
	void srName();
	void srArea();
};
cirManager::cirManager(int size) {
	this->size = size;
	p = new cir[size];

	string name;
	int rad;

	for (int i = 0; i < size; i++) {
		cout << "원" << i + 1 << "의 이름과 반지름>>";
		cin >> name >> rad;

		string setName = name;
		int setRad = rad;
		p[i].setcir(name, rad);
	}
}
cirManager::~cirManager() {

}
void cirManager::srName() {
	bool nameExisted = false;
	string cirName;
	cout << "검색하고자 하는 원의 이름>>";
	cin >> cirName;

	for (int i = 0; i < size; i++) {
		if (cirName == p[i].getName()) {
			cout << p[i].getName() << "의 면적은" << p[i].getArea() << "입니다.";
			nameExisted = true;
		}
	}
	if (nameExisted == false) {
		cout << "이름을 제대로 입력하세요" << endl;
	}
	cout << endl;
}
void cirManager::srArea() {
	int minArea;

	cout << "최소 면적을 정수로 입력하세요>>";
	cin >> minArea;

	cout << minArea << "보다 큰 원을 검색함" << endl;
	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > minArea) {
			cout << p[i].getName() << "의 면적은" << p[i].getArea() << ",";
		}
	}
	cout << endl;
}
int main() {
	int cirNum;

	cout << "원의 개수>> ";
	cin >> cirNum;

	cirManager cirManager(cirNum);

	cirManager.srName();
	cirManager.srArea();
}
