#include <iostream>

using namespace std;

unsigned int count(int m,int n){
	unsigned int p(1);

        for(int i=1;i<=n;m--,i++){

		p=p*m/i;

	}

	return p;

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