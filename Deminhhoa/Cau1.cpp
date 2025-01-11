#include <bits/stdc++.h>
using namespace std;
class Hoc_vien{
	private:
		int MaHV;
		char Hoten[30];
		char Lop[30];
		float Diem;
	public:
		Hoc_vien() : MaHV(0), Diem(0) {
			strcpy(Hoten, "");
			strcpy(Lop, "");
		}
		Hoc_vien(int ma, char ten[30], char lop[30], float diem)
			: MaHV(ma), Diem(diem){
			strcpy(Hoten, ten);
			strcpy(Lop, lop);	
		}
		friend istream& operator>>(istream& is, Hoc_vien& hv);
		friend ostream& operator<<(ostream& os, Hoc_vien& hv);
		bool operator>(Hoc_vien& h){
			return Diem>h.Diem;
		}
		friend void sapxep(Hoc_vien ds[], int n);
};
void sapxep(Hoc_vien ds[], int n){
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			if(ds[i] > ds[j]){
				swap(ds[i], ds[j]);
			}
		}
	}
}
istream& operator>>(istream& is, Hoc_vien& hv){
	cout<<"Nhap ma hv: ";
	is>>hv.MaHV;
	is.ignore();
	cout<<"Nhap ho ten: ";
	is.getline(hv.Hoten, 30);
	cout<<"Nhap lop: ";
	is.getline(hv.Lop, 30);
	cout<<"Nhap diem: ";
	is>>hv.Diem;
	return is;
}
ostream& operator<<(ostream& os, Hoc_vien& hv){
	os<<"Ma hv: "<<hv.MaHV<<endl;
	os<<"Ho ten: "<<hv.Hoten<<endl;
	os<<"Lop: "<<hv.Lop<<endl;
	os<<"Diem: "<<hv.Diem<<endl;
	return os;
}

int main(){
	int n;
	cout<<"Nhap so hoc vien: "; cin>>n;
	Hoc_vien *DSHV = new Hoc_vien[n];
	for (int i=0; i<n; i++){
		cout<<"Nhap hoc vien thu "<<i+1<<" :\n";
		cin >> DSHV[i];
	}
	cout<<"Danh sach hoc vien vua nhap:\n";
	for (int i=0; i<n; i++){
		cout<<"Hoc vien thu "<<i+1<<" : \n"<<DSHV[i];
	}
	sapxep(DSHV, n);
	cout<<"Danh sach hoc vien da sap xep:\n";
	for (int i=0; i<n; i++){
		cout<<"Hoc vien thu "<<i+1<<" : \n"<<DSHV[i];
	}
	delete[] DSHV;
}
