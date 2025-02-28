// abstract base class
#include <iostream>
using namespace std;
//----------------------------//
class CPolygon {
protected:
	int width, height;
public:
	void set_values (int a, int b) { 
		width=a; height=b; 
	}
	virtual int area(void) = 0;// Ham ao thuc su
};
//----------------------------//
class CRectangle: public CPolygon {
public:
	int area (void) { 
		return (width*height); 
	}
};
//----------------------------//
class CTriangle: public CPolygon {
public:
	int area (void) { 
		return (width*height/2); 
	}
};
//----------------------------//
int main () {
	CPolygon* ppoly1 = new CRectangle;
	CPolygon* ppoly2 = new CTriangle;
	
	ppoly1->set_values (4,5);
	ppoly2->set_values (4,5);
	
	cout << ppoly1->area() << endl;
	cout << ppoly2->area() << endl;
	
	return 0;
}
