#include<bits/stdc++.h>

using namespace std;
template<class T>
class List{
	private:
		int n;
		T* mang;
	public:
		List(int spt=0){
			n = spt;
			if(spt==0) mang=NULL;
			else{
				mang = new T[n];
			}
		}
		~List(){
			delete[] mang;
		}
		void nhap(){
			cout<<"Nhap so luong phan tu";
			cin>>n;
			mang = new T[n];
			cout << "Nhap cac phan tu: ";
			for (int i=0; i<n; i++){
				cin>>mang[i];
			}
		}
		void xuat(){
			cout<<"Danh sach: ";
			for(int i=0; i<n; i++){
				cout << mang[i] << " ";
			}
			cout<<endl;
		}
		void sapxep(){
			for(int i=0; i<n-1; i++){
				for(int j=i+1; j<n; j++){
					if(mang[i] > mang[j]){
						swap(mang[i], mang[j]);
					}
				}
			}
		}
		void timkiem(T& t){
			for (int i=0; i<n; i++){
				if(mang[i] == t){
					return i;
				}
			}
			return -1;
		}	
};
