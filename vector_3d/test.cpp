#include<iostream>

#include"vector_3d.hpp"

using namespace std;

int main(){
	const vector_3d vec {1000, 1110, 10};
	const vector_3d new_vec {vector_3d {1, 2, 3}}; // Move Constructor.

	try
	{
		cout<<new_vec.r()<<" "<<new_vec.g()<<" "<<new_vec.b();
	}
	catch(string &ex)
	{
		cout<<ex;
	}
	return 0;
}