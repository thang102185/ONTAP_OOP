#include<iostream>
using namespace std;
class Matrix {
	int **data;
public:
	Matrix() {
		data = new int *[2];
    	for(int i = 0; i < 2; i++) 
			data[i] = new int[2];
	}
	~Matrix() {
		for (int i = 0; i < 2; i++)
			delete data[i];
		delete data;
	}
	friend istream& operator>> (istream&, Matrix&);	
	friend ostream& operator<< (ostream& , Matrix&);
	
	void Nhap();
	void Xuat();
	Matrix operator+(Matrix& m) {
		Matrix T;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				T.data[i][j] = data[i][j] + m.data[i][j];
			}
		}
		return T;
	}
	int det() {
		return (data[0][0]*data[1][1] - data[1][0]*data[0][1]);
	}
	int operator()(int i, int j) {
		if (i >= 2 || j >= 2) {
			cout << "Khong co gia tri nay";
			exit(0);	
		}
		else
			return data[i][j];
	}
	// Tang dang tien to
	void operator++() {
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				data[i][j] = ++data[i][j];
			}
		}		
	}
	//Tang dang hau to
	Matrix operator++(int) {
		Matrix T;
			for(int i = 0; i < 2; i++) {
				for(int j = 0; j < 2; j++) {
					T.data[i][j] = data[i][j]++;
				}
			}
		return T;
	}		
};
//---------------------------------------//
void Matrix::Nhap() {
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++) {
			cout << "Nhap phan tu a[" << i << "][" << j <<"] = ";
			cin >> data[i][j];
		}
}
//---------------------------------------//
void Matrix::Xuat() {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++)
			cout  << data[i][j] << " ";
		cout << endl;
	}
}
//---------------------------------------//
int main() {
	Matrix m1, m2;
	m1.Nhap();
	m1.Xuat();
	
	m2.Nhap();
	m2.Xuat();
	cout <<"m3 = m1 + m2:\n";
	Matrix m3 = m1 + m2;
	m3.Xuat();
	cout << m1(1,0);
	cout << endl;
	m3++;
	m3.Xuat(); 
	return 0;
}
