#include <bits/stdc++.h>

using namespace std;

class Mat_hang{
	private:
		int Ma_hang;
		char Ten_hang[30];
		float Gia_ban;
	public:
		friend istream& operator>>(istream& is, Mat_hang& h);
		friend ostream& operator<<(ostream& os, Mat_hang& h);
		float Tien(){
			return Gia_ban;
		}
};

class Khach_hang{
	private:
		int Ma_Khach_hang;
		char Ten_khach_hang[30];
		int So_luong;
		Mat_hang Hang[20];
	public:
		friend istream& operator>>(istream& is, Khach_hang& k);
		friend ostream& operator<<(ostream& os, Khach_hang& k);
		float Tong_tien(){
			float Tong = 0;
			for(int i=0; i<So_luong; i++){
				Tong = Tong + Hang[i].Tien();
			}
			return Tong;
		}
};

istream& operator>>(istream& is, Mat_hang& h){
	cout<<"Nhap ma hang: ";
	is>>h.Ma_hang;
	cout<<"Nhap ten hang: ";
	is.ignore();
	is.getline(h.Ten_hang, 30);
	cout<<"Nhap gia ban: ";
	is>>h.Gia_ban;
	return is;
}
ostream& operator<<(ostream& os, Mat_hang& h){
	os<<"Ma hang: "<<h.Ma_hang<<endl;
	os<<"Ten hang: "<<h.Ten_hang<<endl;
	os<<"Gia ban: "<<h.Gia_ban<<endl;
	return os;	
}
istream& operator>>(istream& is, Khach_hang& k) {
    cout << "Nhap ma khach hang: ";
    is >> k.Ma_Khach_hang;
    cout << "Nhap ten khach hang: ";
    is.ignore();
    is.getline(k.Ten_khach_hang, 30);
    cout << "Nhap so luong mat hang: ";
    is >> k.So_luong;
    for (int i = 0; i < k.So_luong; i++) {
        cout << "Nhap thong tin mat hang thu " << i + 1 << ":" << endl;
        is >> k.Hang[i];
    }
    return is;
}
ostream& operator<<(ostream& os, Khach_hang& k) {
    os << "Ma khach hang: " << k.Ma_Khach_hang << endl;
    os << "Ten khach hang: " << k.Ten_khach_hang << endl;
    os << "So luong mat hang: " << k.So_luong << endl;
    for (int i = 0; i < k.So_luong; i++) {
        os << "Thong tin mat hang thu " << i + 1 << ":" << endl;
        os << k.Hang[i];
    }
    os << "Tong tien: " << k.Tong_tien() << endl;
    return os;
}
int main() {
    Khach_hang kh;
    cout << "Nhap thong tin khach hang:" << endl;
    cin >> kh;
    cout << "Thong tin khach hang vua nhap:" << endl;
    cout << kh;
    return 0;
}
