#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

//Дано число N и далее N строк.Найти количество
//уникальных эквивалентных строк и вывести их.
//P.S.Две строки назовём эквивалентными, если после
//удаления пробелов и перевода символов в нижний
//регистр они совпадают.
//Размер программы должен быть как можно меньше -
//активно используйте лямбда - функции.

//foo for "good" string
std::string prepare(const std::string& str) {
	std::string result = " ";
	result.assign(str);
	std::transform(str.begin(), str.end(), result.begin(), ::tolower); //converting to lower case
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());//erasing all ' '
	return result;
};

struct Statistics {
	int count = 0;
	std::string str;
};

int main() {
	setlocale(LC_ALL, "Russian");
	std::ifstream fin("input.txt");//input into file
	if (fin.is_open()) {
		std::string bad_string = " ";
		std::map <std::string, int> Map;//key - string, counter - num of equal strings
		while (!fin.eof()) {
			std::getline(fin, bad_string);
			bad_string = prepare(bad_string);
			if (bad_string.size() > 0) {
				//adding key and counter for each new string
				Map[bad_string]++;
			}
		}
		int counter = 0;
		std::vector <Statistics> strings; //creating array strings of structures <Statistics>
		for (const auto& it : Map) {
			strings.push_back({ it.second, it.first }); //filling strings
		}
		std::sort(strings.begin(), strings.end(), [&](const Statistics& s1, const Statistics& s2) {
			return s1.count < s2.count; //from small to big
		}); //sorting structures from vector strings (small->big)
		std::ofstream fout("output.txt");
		for (int i = 0; i < strings.size(); i++) {
			if (strings[i].count == 1)
				counter++;
		}
		if (fout.is_open()) {
			for (int i = 0; i < counter; i++)
					fout << "Unique string: " << strings[i].str << std::endl;
			fout << "Number of unique strings: " << counter << std::endl;
		}
		else {
			std::cout << "Output file opening failed" << std::endl;
			return 0;
		}
	}
	else {
		std::cout << "Input file opening failed" << std::endl;
		return 0;
	}
	fin.close();
	return 0;
}
