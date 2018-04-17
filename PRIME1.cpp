#include <iostream>
#include <math.h>
using namespace std;
bool Check(long long int a){
	if (a<2)
		return false;
	for (int i=2;i<=sqrt(a);i++)
		if (a%i==0)
			return false;
	return true;
}

int main(){
	long long int n,a,b;
	cin>>n;
	for (long long int i=0;i<n;i++){
		cin>>a>>b;
		for (long long int j=a;j<=b;j++)
			if (Check(j))
				cout<<j<<endl;
	}
	return 0;
}
