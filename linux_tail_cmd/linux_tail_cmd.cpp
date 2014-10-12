#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

string tail(const string &filename,int n){
	fstream file_ptr(filename.c_str());
	file_ptr.seekg(0,ios::end);

	int file_size = file_ptr.tellg(),newline_count = 0;
	string last_N_line;
	for(int i = 0;i<file_size;i++){
		file_ptr.seekg(-1-i,ios::end);
		char c;
		file_ptr.get(c);
		if(c=='\n'){
			newline_count++;
			if(newline_count>n) break;
		}
		last_N_line.push_back(c);
	}
	std::reverse(last_N_line.begin(),last_N_line.end());
	return last_N_line;


}

int main(){
	cout<<tail("test.txt",50)<<endl;
}