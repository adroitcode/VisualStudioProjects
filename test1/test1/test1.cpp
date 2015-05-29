#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;


//char *strrev(char *string);
string strrev(string &str){
	string rev_str = "";
	for (int x = str.size() - 1; x > -1; x--){
		rev_str += str[x];
	}
	return rev_str;
}


int main(){

	string str =  "Hello";


	cout << strrev(str) << endl;

	//cout << to_string(str.size()) << endl;
	//cout << to_string(strrev(str).size()) << endl;


	system("pause");


}