//---------------------------------//
class Gparent {
public:
	int gData;
};
//---------------------------------//
class Mother: virtual public Gparent {
};
//---------------------------------//
class Father: virtual public Gparent {
};
//---------------------------------//
class Child: public Mother, public Father {
public:
	void cFunc() {
		gData = 10;
	}
};
//---------------------------------//
int main() {
	Child ch;
	ch.cFunc();	
}
