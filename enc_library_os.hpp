
#ifndef ENC_LIBRARY_OS_HPP_
#define ENC_LIBRARY_OS_HPP_

char to_upper(char input);
bool is_alpha(char input);
bool is_upper(char input);
int max_index(int alpha_count[]);
void print_analysis_array(int occur_count[]);
void character_count(std::string en_file);
void decrypt(std::string en_file, std::string de_file, int key);


#endif /* ENC_LIBRARY_OS_HPP_ */






