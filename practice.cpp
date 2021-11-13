#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<char> v;
	v.push_back('c');
	for(auto i=v.begin();i!=v.end();i++){
		cout<<*i<<endl;
	}
	return 0;
}