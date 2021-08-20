#include<iostream>

#include"vector_3d.hpp"

using namespace std;

int main(){
	const vector_3d vec {1000, 1110, 10};
	try
	{
		cout<<vec[3];
	}
	catch(string &ex)
	{
		cout<<ex;
	}
	return 0;
}