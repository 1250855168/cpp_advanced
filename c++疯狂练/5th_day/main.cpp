#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Person {
private:
  char name[20];
  char id[18];
  int age;
  char addr[20];

public:
  Person(){};
  Person(char *n, char *ID, int Age, char *Addr) {
    strcpy(name, n);
    strcpy(id, ID);
    age = Age;
    strcpy(addr, Addr);
  }
  void display() {
    cout << name << "\t" << id << "\t" << age << "\t" << addr << endl;
  }
};

int main() {
  vector<Person> v;
  vector<Person>::iterator pos;

  char ch;
  ofstream out("./Person.txt", ios::out | ios::binary | ios::app);
  char name[20];
  char id[18];
  int age;
  char addr[20];

  do {
    cout << "姓名： ";
    cin >> name;
    cout << "身份证号： ";
    cin >> id;
    cout << "年龄： ";
    cin >> age;
    cout << "地址： ";
    cin >> addr;
    Person per(name, id, age, addr);
    out.write((char *)&per, sizeof(per));
    cout << "Enter another Person(y/n)?";
    cin >> ch;
  } while (ch == 'y');
  out.close();
  ifstream in("./Person.txt", ios::in | ios::binary);
  Person t;
  in.read((char *)&t, sizeof(t));
  while (!in.eof()) {
    v.push_back(t);
    in.read((char *)&t, sizeof(t));
  }

  for (pos = v.begin(); pos != v.end(); pos++)
    pos->display();


  return 0;
}