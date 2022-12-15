///============================================================================
/// Name        : caesar_os.cpp
///============================================================================

#include <iostream>
#include"enc_library_os.hpp"
using namespace std;

int main(int argc, char **argv) {
	///Creating Variable of command line argument 1
	string encrypted_file = argv[1]; 
	///Creating Variable of command line argument 2
	string decrypted_file = argv[2]; 
	///Creates the key variable
	int key;
	
	//Calling the character_count function with the command line argument 1
	character_count(encrypted_file); 

	cout << "Enter the key you would like to use:  ";
	///Takes user input and sends to int key
	cin >> key; 
	///Calling the decrypt function with all command line arguments, and user input of key
	decrypt(encrypted_file, decrypted_file, key); 
}
