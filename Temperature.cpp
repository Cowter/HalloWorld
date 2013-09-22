#include <iostream>

using namespace std;

float trans(float f){
	return (f-32)*5/9;
}

void main(){
	float f;
	cout<<"F=";
	cin>>f;
	cout<<"F="<<f<<endl<<"C="<<trans(f)<<endl;
	system("pause");
}