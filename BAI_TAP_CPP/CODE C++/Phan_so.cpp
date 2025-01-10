#include<iostream>
#include<Math.h>
using namespace std;
class Phan_so {
	int Tu_so;
	int Mau_so;
public:
	Phan_so() {
		Tu_so = 0;
		Mau_so = 1;
	}
	Phan_so(int ts, int ms) {
		Tu_so = ts;
		if (ms==0) {
			cerr << "LOI CHIA CHO KHONG";
			exit(0);
		}
		else 
		Mau_so = ms;
	}
	friend istream& operator>>(istream&, Phan_so&);
	friend ostream& operator<<(ostream&, Phan_so&);
	Phan_so operator+(const Phan_so&);
	Phan_so operator-(const Phan_so&);
	Phan_so operator*(const Phan_so&);
	Phan_so operator/(const Phan_so&);
	
	int gcd(int n, int d) {
    	if (d == 0) 
			return n;
    	else 
			return abs(gcd(d,n%d));
	}
	
	void Rut_gon() {
		int UC = gcd(Tu_so, Mau_so);
		Tu_so = Tu_so / UC;
		Mau_so = Mau_so / UC;
	}
};
//----------------------------//
istream& operator >> (istream& is, Phan_so& ps) {
	cout << "Tu so = "; is >> ps.Tu_so;
	cout << "Mau so = "; is >> ps.Mau_so;
	return is;
}
//----------------------------//
ostream& operator << (ostream& os, Phan_so& ps) {
	os << ps.Tu_so << "/" << ps.Mau_so;
	return os;
}
//----------------------------//
Phan_so Phan_so::operator+(const Phan_so& ps) {
	Phan_so tmp;
	tmp.Tu_so = Tu_so*ps.Mau_so + Mau_so*ps.Tu_so;
	tmp.Mau_so = Mau_so*ps.Mau_so;
	tmp.Rut_gon();
	return tmp;	
}
//----------------------------//
Phan_so Phan_so::operator-(const Phan_so& ps) {
	int ts = Tu_so*ps.Mau_so - Mau_so*ps.Tu_so;
	int ms = Mau_so*ps.Mau_so;	
	return Phan_so(ts/gcd(ts,ms),ms/gcd(ts,ms));	
}
//----------------------------//
Phan_so Phan_so::operator*(const Phan_so& ps) {
	int ts = Tu_so*ps.Tu_so;
	int ms = Mau_so*ps.Mau_so;	
	return Phan_so(ts/gcd(ts,ms),ms/gcd(ts,ms));	
}
//----------------------------//
Phan_so Phan_so::operator/(const Phan_so& ps) {
	int ts = Tu_so*ps.Mau_so;
	int ms = Mau_so*ps.Tu_so;	
	return Phan_so(ts/gcd(ts,ms),ms/gcd(ts,ms));	
}
//----------------------------//
int main() {
	Phan_so ps1, ps2, ps3;
	
	cin >> ps1;
	cout << ps1;
	
	cout << endl;
	
	cin >> ps2;
	cout << ps2;
	
	cout << endl;
	ps3 = ps1 / ps2; 	//ps3 = ps1.operator+(ps2); 
	cout << ps1 << " / " << ps2 << " = " << ps3;
	
	return 0;
}
