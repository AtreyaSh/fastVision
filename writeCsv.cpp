#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

void writeCsv(string filePath, vector<double> myV, vector<string> header){

	ofstream myfile(filePath);
	int vsize1 = myV.size();
	int vsize2 = header.size();

	for(int n = 0; n < vsize2; n++){
		if((n+1)%vsize2 != 0)
		{
			myfile << header[n] << ',';
		}
		else
		{
			myfile << header[n] << '\r';
		}
	}

	for(int n = 0; n < vsize1; n++){
		if((n+1)%vsize2 != 0)
		{
			myfile << myV[n] << ',';
		}
		else
		{
			myfile << myV[n] << '\r';
		}
	}
}
