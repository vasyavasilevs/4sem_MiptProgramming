#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#define NUM_OF_WORDS 10

void prepare(std::string& str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower); //converting to lower case
	if (ispunct(str[str.length() - 1])) //if the last symbol is punct
		str.pop_back();//erase
};
//creating vector including structures 
struct Statistics {
	int count;
	std::string word;
};

bool comparatorForStat(const Statistics& s1, const Statistics& s2) {
	return s1.count > s2.count; //from big to small
};

int main() {
	std::ifstream fin("input.txt");
	std::map<std::string, int> Map;
	if (fin.is_open()) {
		std::string word;
		while (!fin.eof()) {
			fin >> word;
			prepare(word);
			Map[word]++;
		}
		std::vector<Statistics> s; //creating array s of structures 
		Statistics unit; //creating elementary structure to use it for step-by-step pushing s
		for (const auto& it: Map) {
			s.push_back({ it.second, it.first }); // aka unit.word = it.first; unit.count = it.second; s.push_back(unit);
		}
		std::sort(s.begin(), s.end(), comparatorForStat); //sorting structures from vector s (big->small)
		std::ofstream fout("output.txt");
		if (fout.is_open()) {
			for (size_t i = 0; i < NUM_OF_WORDS; i++) {
				fout << s[i].word << '\n';
			}
		}
		else {
			std::cout << "Output file opening failed" << std::endl;
			return 0;
		}
		fout.close();
	}
	else {
		std::cout << "Input file opening failed" << std::endl;
		return 0;
	}
	fin.close();
	return 0;
}