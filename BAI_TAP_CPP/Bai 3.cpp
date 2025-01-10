#include<iostream>
#include<cstring>
using namespace std;
//------------------------------//
class Thuoc {
	char Ten_thuoc[30];
	int Ma_thuoc;
	int So_luong;
	float Gia_ban;
public:
	void Nhap();
	void In();
	
	friend bool comparator(const Thuoc* p, const Thuoc *q);
	friend void Sap_xep(Thuoc TH[], int n); 
	friend void swap(Thuoc& p, Thuoc& q);

};
//------------------------------//
void Thuoc::Nhap() {
	cout << "Ma thuoc: "; cin >> Ma_thuoc;	
	cout << "Ten thuoc: "; cin.ignore(); cin.get(Ten_thuoc,30);	
	cout << "So luong: "; cin >> So_luong;
	cout << "Gia ban: "; cin >> Gia_ban;	
}
//------------------------------//
void Thuoc::In() {
	cout << "Ma thuoc: " << Ma_thuoc << endl;	
	cout << "Ten thuoc: " << Ten_thuoc << endl;
	cout << "So luong: " << So_luong << endl;
	cout << "Gia ban: " << Gia_ban << endl;
}
//------------------------------//
bool comparator(const Thuoc* p, const Thuoc* q) {
	return ((strcmp(p->Ten_thuoc,q->Ten_thuoc) > 0) ||
    		((strcmp(p->Ten_thuoc,q->Ten_thuoc) == 0) && 
			(p->Ma_thuoc > q->Ma_thuoc)));
}
//------------------------------//
void swap(Thuoc& p, Thuoc &q) {
	Thuoc tmp = p;
	p = q;
	q = tmp;
}
//------------------------------//
void Sap_xep(Thuoc TH[], int n) {
	int i, j;  
    for (i = 0; i < n-1; i++)      
    	for (j = 0; j < n-i-1; j++)  
    		if (comparator(&TH[j], &TH[j+1])) {     			
				swap(TH[j], TH[j+1]);
			}           	 
}
//------------------------------//
int main() {
	Thuoc *TH;
	int n;
	cout << "Nhap vao so luong thuoc: "; cin >> n;
	TH = new Thuoc[n];
	
	cout << "\nNHAP VAO DS THUOC\n";
	for(int i=0;i<n;i++) {
		cout << "***************\n";
		cout << "Thuoc thu " << i+1 << ":\n";
		TH[i].Nhap();
	}
	
	cout << "\nDS THUOC VUA NHAP VAO LA\n";
	for(int i=0;i<n;i++) {
		cout << "***************\n";
		cout << "Thuoc thu " << i+1 << ":\n";
		TH[i].In();
	}
	Sap_xep(TH, n);
	
	cout << "\nDS THUOC SAU KHI SAP XEP VAO LA\n";
	for(int i=0;i<n;i++) {
		cout << "***************\n";
		cout << "Thuoc thu " << i+1 << ":\n";
		TH[i].In();
	}	
	return 0;
}
