#include <iostream>

using namespace std;

int power(int x,int y){
	if(y>0)
		return x*power(x,--y);
	else
		return 1;
}

void main(){
	int x,y;
	cout<<"x=";
	cin>>x;
	cout<<"y=";
	cin>>y;
	cout<<x<<"^"<<y<<"="<<power(x,y)<<endl;
	system("pause");
}