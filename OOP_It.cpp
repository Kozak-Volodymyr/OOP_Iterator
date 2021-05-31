#include<iostream>
#include<string.h>
#include<vector>
#define max 15
using namespace std;
template<typename T,typename U>
class Iterator {
public:
	 typedef typename std::vector<T>::iterator it;
	 Iterator(U*p, bool reverse = false) :mp(p) {
		  mit = mp->l.begin();
	 }
	 void First() {
		  mit = mp->l.begin();
	 }
	 void Next() {
		  mit++;
	 }
	 bool Done() {
		  return(mit == mp->l.end());
	 }
	 it Current() {
		  return mit;
	 }
private:
	 U*mp;
	 it mit;
};
template<class T>
class Container {
	 friend class Iterator<T, Container>;
public:
	 void Add(T a) {
		  l.push_back(a);
	 }
	 void  Delete(Iterator<T,Container> a) {
		  l.erase(a.Current());
	 }
	  T Sum(Iterator<T, Container>a, Iterator<T, Container>a1) {
		  return (*a.Current()+ *a1.Current());
	 }
	 Iterator<T, Container>*Create() {
		  return new Iterator<T, Container>(this);
	 }
private:
	 std::vector<T>l;
};
int main() {
	 system("chcp 1251");
	 double Sum;
	 Container<int>cont;
	 cout << "\n Введіть дані:" << endl;
	 for (int i = 0; i < max; i++) {
		  int n;
		  cin >> n;
		  if (n == 0)
				break;
		  cont.Add(n);
	 }
	 Iterator<int, Container<int>>*it = cont.Create();
	 cout <<"\n Черга:" << endl;
	 for (it->First(); !it->Done(); it->Next()) {
		  cout << *it->Current() << endl;
	 }
	 it->First();
	 Iterator<int, Container<int>>*it2 = cont.Create();
	 it2->Next();
	 Sum = cont.Sum(*it, *it2);
	 cout << "\n Сума елементів:" << Sum << endl;
	 cont.Delete(*it2);
	 cout << "\n Черга після видалення елемента:" << endl;
	 for (it->First(); !it->Done(); it->Next()) {
		  cout << *it->Current() << endl;
	 }
}
