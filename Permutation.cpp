#include <iostream>

using namespace std;

int count(int m,int n){
	int p(1),q(1);
	for(;n>0;m--,n--){
		p=p*m;
		q=q*n;
	}
	return p/q;
}

void main(){
	int m,n;
	cout<<"m=";
	cin>>m;
	cout<<"n=";
	cin>>n;
	cout<<count(m,n)<<endl;
	system("pause");
}