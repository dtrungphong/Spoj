#include <iostream>

using namespace std;

long int Rev(long int a){
	long int a1=0,b1=0;
	while (a>0){
		a1=a1*10+a%10;
		a=a/10;
	}
	return a1;
}

int main(){
	long int n,a,b;
	cin>>n;
	for (long int i=0;i<n;i++){
		cin>>a>>b;
		cout<<Rev(Rev(a)+Rev(b))<<endl;
	}
	return 0;
}
