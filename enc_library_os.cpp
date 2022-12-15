//============================================================================
// Name        : enc_library_os.cpp
//============================================================================

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/** Converts a lowercase letter to uppercase.
 * @author O Smith
 * @param[in] input Character to change (char)
 * @param[out] input Changed Character if lower case (char)
 * @return Inputted character's upper case version.
 * @date 03/12/2021
 * @test to_upper('a') -> 'A'
 * @test to_upper('X') -> 'X'
 * @test to_upper('1') -> '1'
 * @test to_upper('M') -> 'M'
 * @test to_upper('S') -> 'S'
 * @test to_upper('b') -> 'B'
 */

char to_upper(char input) {

	if (input >= 97 && input <= 122) {
		return input - 32;
	} else {
		return input;
	}
}  

/** Checks if given character is alphabetic.
 * @author O Smith
 * @param[in] input Character to check (char)
 * @return True if alphabetic, false if anything else.
 * @date 03/12/2021
 * @test is_alpha('a') -> true
 * @test is_alpha(''') -> false
 * @test is_alpha('M') -> true
 * @test is_alpha('/0') -> false
 * @test is_alpha('1') -> false
 */

bool is_alpha(char input) {
	if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122)) {
		return true;
	} else {
		return false;
	}
}

/** Checks if given character is uppercase.
 * @author O Smith
 * @param[in] input Character to check (char)
 * @return True if uppercase, false if anything else.
 * @date 04/12/2021
 * @test is_upper('a') -> false
 * @test is_upper(''') -> false
 * @test is_upper('M') -> true
 * @test is_upper('B') -> true
 * @test is_upper('1') -> false
 */

bool is_upper(char input) {
	if (input >= 97 && input <= 122) {
		return true;
	} else {
		return false;
	}
}

/** Calculates the character that occurs the most.
 * It returns an integer containing the occurance.
 * @author O Smith
 * @date 05/1/2022
 * @param[in] occur_count Integer array of character occurrences (int[])
 * @return Returns max, the value in occur_count with the biggest value
 * @test *occur_count[26] = {1, 12, 1, 9, 53, 134, 23, 504} * max_index(occur_count) -> max = 504
 * @test *occur_count[26] ={1,0}* max_index(occur_count) -> max = ''
 * @test max_index(a_count[]) -> Error (Does not build)
 * @test max_index(occur_count[]) -> Error (Does not build)
 */

int max_index(int occur_count[]) {
	int max = 0;
	int i;
	for (i = 0; i != 26; i++) {
		if (max < occur_count[i]) {
			///Sets the largest value of occur_count to max
			max = occur_count[i];
		}
	}
	return max;
}

/** Carries out the text analysis on the given encypted text.
 * Such as suggesting the most suitable key to use
 * And providing user with most occurent character
 * @author O Smith
 * @param[in] occur_count Integer array of character occurrences (int[])
 * @return Void
 * @date 05/1/2022
 * @test occur_count[26] = {1, 12, 1, 9, 53, 134, 23, 504} * print_analysis_array(occur_count) -> Suggested Key : 12
 */

void print_analysis_array(int occur_count[]) {
	int i;
	///For loop prints out the characters from the encrypted text and how many times they occur
	for (i = 0; i != 26; i++) {
		cout << char(i + 'A') << " occurs:" << occur_count[i] << " Times"
				<< endl;
	}
	///This for loop prints out the analysis of the text. Which shows the most occurent character in the encrypted text
	///It also makes the suggestion of which key to use based on the analysis.
	for (i = 0; i != 26; i++) {
		if (max_index(occur_count) == occur_count[i]) {
			cout << "The most frequent letter is: " << char('A' + i)
					<< " with a count of: " << occur_count[i] << endl;
			cout
					<< "If we assume this is E when decrypted the most likely key is: "
					///This is the analysis of the text which determines the suggessted key to use
					<< (char('A' + i) - 'E') << endl;
		}
	}
}

/** Counts the occurance of the characters in the given file.
 * Checks file line by line
 * @author O Smith
 * @param[in] en_file Encypted Filename (std::string)
 * @param[out] occur_count Integer array of character occurrences (int[])
 * @date 05/1/2022
 * @test Tests in testing document 
 */

void character_count(std::string en_file) {
	string line;
	int occur_count[26] = { 0 };
	ifstream InputFile(en_file);
	///Checks whether or not the file name is correct and open 
	if (InputFile.is_open()) {
		///Loops through file line by line 
		while (getline(InputFile, line)) {

			unsigned int i;
			unsigned int n;
			///Ascii valur of uppercase a
			int ascii_upper = 97;
			///Ascii value of lowercase a
			int ascii_lower = 65;
			for (i = 0; i < 26; i++) {
				for (n = 0; n <= line.length(); n++) {
					///Checks both upper and lower case letters
					if (line[n] == ascii_upper || line[n] == ascii_lower) {
						///Increments by one whenever a character is counted
						occur_count[i] += 1;
					}
				}
				///Increments through the uppercase alphabet 
				ascii_upper += 1;
				///Increments through the lowercase alphabet
				ascii_lower += 1;
			}
		}
		///Calls the print_analysis_array function with the occurences in the int array occur_count
		print_analysis_array(occur_count);
		/// Closes the file stream
		InputFile.close();
	} else {
		///Exits the program if the file cannot be opened
		cout << "Encrypted Text file not found. Exiting ..." << endl;
		exit(1);
	}

}

/** Decrypts the given .txt file line by line.
 * Gives user sample of decrypted text
 * Allows user to try different keys
 * @author O Smith
 * @param[in] en_file Encrypted Filename (std::string)
 * @param[in] de_file Decrypted Filename (std::string)
 * @param[in] key Decryption Key Chosen by user (int)
 * @param[out] plain Plain text string to write to file (string)
 * @param[out] decrypted_file Text file of decrypted text
 * @date 05/01/2022
 * @test Tests in testing Documentation
 */

void decrypt(std::string en_file, std::string de_file, int key) {
	string line;
	string plain;
	///Opens file, Does not need to be checked as this function only called after check
	ifstream InputFile(en_file);
	///Creates file with name given with de_file.
	ofstream OutputFile(de_file);
	///Loops line by line
	while (getline(InputFile, line)) {
		unsigned int i;
		int ascii_z;
		///Iterates through the line until the end of line 
		for (i = 0; i < line.length(); ++i) {
		if (is_alpha(line[i]) != 0) {
			ascii_z = 90;
			if (is_upper(line[i]) != 0) {
				ascii_z = 122;
			}
			plain += (line[i] - key - ascii_z) % 26 + ascii_z;
		} else {
			plain += line[i];
		}
	}
	///Adds new line to 'plain' after every line of decryption.
	plain += '\n';
}
	///Displays a sample of text that has been decrypted from the text file.
	cout << "Here is a sample of decrypted text" << endl;
	cout << '"';
	for (int i = 0; i < 128; i++) {
		cout << plain[i];
	}
	cout << '"' << endl;

	cout << "Would you like to continue with the current key? (y/n)" << endl;
	char choice;
	cin >> choice;
	if (choice == 'y') {
		///Finishes writing all of decrpyted text to the new text file
		OutputFile << plain;
		cout << "The rest of the text has been decrypted using the key: " << key << " & written to the file: " << de_file << endl;
	}
	else
	{
		cout << "Would you like to try another key? (y/n)" << endl;
		cin >> choice;
		if (choice != 'y') {
			///Code exits if the user choses not to try another key
			exit(1);
		} else {
			cout << "What key would you like to try: ";
			cin >> key;
			///Loops back to the begining of the function with the new key
			decrypt(en_file, de_file, key);
		}
	}
	///Closes filestream for en_file
	InputFile.close();
	///Closes filestream for de_file
	OutputFile.close();
	}

