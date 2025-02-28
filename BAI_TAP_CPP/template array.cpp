#include <iostream> 
using namespace std; 
//------------------------------//
template <typename T> 
class Array { 
private: 
	T *ptr; 
	int size; 
public: 
	Array(T arr[], int s); 
	void print(); 
}; 
//------------------------------//
template <typename T> 
Array<T>::Array(T arr[], int s) { 
	ptr = new T[s]; 
	size = s; 
	for(int i = 0; i < size; i++) 
		ptr[i] = arr[i]; 
} 
//------------------------------//
template <typename T> 
void Array<T>::print() { 
	for (int i = 0; i < size; i++) 
		cout << " " << *(ptr + i); 
	cout << endl; 
} 
//------------------------------//
int main() { 
	int arr[5] = {1, 2, 3, 4, 5}; 
	Array<int> a(arr, 5); 
	a.print(); 
	cout << endl;
	
	float arr_f[5] = {1.5, 2.3, 3.2, -4.2, 5.4}; 
	Array<float> b(arr_f, 5); 
	b.print(); 
	
	return 0; 
} 

