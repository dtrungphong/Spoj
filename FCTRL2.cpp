#include <iostream>
#include <string>
using namespace std;

void Balance(string &a,string &b){
	if (a.size()>b.size())
		b= string(a.size()-b.size(),'0')+b;
	a = string(b.size()-a.size(),'0')+a;
}

string Sum(string a, string b){
	Balance(a,b);
	int temp=0;
	for (int i=a.size()-1;i>=0;i--){
		a[i]=a[i]+b[i]+temp-48;
		temp=0;
		if (a[i]>'9'){
			temp=1;
			a[i]=a[i]-10;
		}
	}
	if (temp!=0)
		a="1"+a;
	return a;
}

string Sub(string a, string b){
	Balance(a,b);
	int temp=0;
	for (int i=a.size()-1;i>=0;i--){
		a[i]=a[i]-b[i]-temp;
		temp=0;
		if (a[i]<0){
			temp=1;
			a[i]=a[i]+58;
		}
		else
			a[i]=a[i]+48;
	}
	int i=0;
	while (a[i]=='0'){
		a=string(a.begin()+1,a.end());
	}
	if (a.size()==0)
		a="0";
	return a;
}


string MulChar(string a,char b){
    if(b=='0') return "0";
    if(b=='1') return a;
	int f=0;
	for (int i=a.size()-1;i>=0;i--){
		a[i]=(a[i]-48)*(b-48)+f;
		f=0;
		if (a[i]>9){
			f=(a[i])/10;
			a[i]=(a[i])%10+48;
		}
		else a[i]+=48;
	}
	if (f>0){
		a=char(f+48)+a;
	}
	return a;
}

string Mul(string a,string b){
    string c="0";
    for (int i=0;i<a.size();i++){
        if (i!=a.size()-1)
            c=Sum(MulChar(b,a[i]),c)+"0";
        else
            c=Sum(MulChar(b,a[i]),c);
    }
    return c;
}

string Fac(string a){
    if (a=="1")
        return "1";
    return Mul(a,Fac(Sub(a,"1")));
}

int main(){
    int n;
    string k;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>k;
        cout<<Fac(k)<<endl;
    }
    return 0;
}
