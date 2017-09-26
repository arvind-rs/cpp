
/*
 * Solution to the following problem.
 * Suppose we have a large text file, and we want to pre-process it in such a way that we will then be able to (repeatedly) answer 
 * the following question very quickly for any two strings s1 and s2: "How many times does s2 appear immediately after s1 in this text file?" 
 * Write a program that reads in a text file and then implements a fast method that we can call repeatedly to answer that question for different strings.
 * @author: ArvindRS
 * @date: 09/25/2017
 */

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

// Function to preprocess the file to enable querying it
multimap<string, int> preprocess_file(string filename) {
	char ch;
	int pos = 0;
	int word_start_pos = -1;
	string word;
	multimap<string, int> m;
	ifstream fp;
	fp.open(filename);
	while(fp >> noskipws >> ch) {
		if(ch == ' ' || ch < 65 || (ch > 90  && ch < 97) || ch > 122 || fp.peek() == std::char_traits<wchar_t>::eof()) {
			//cout << word << "," << word_start_pos << endl;
			if(word != "")
				m.insert(pair<string,int>(word,word_start_pos));
			word = "";
			word_start_pos = -1;
		}
		else {
			if(word_start_pos == -1)
				word_start_pos = pos + 1;
			word += ch;
			pos++;
		}
	}
	fp.close();
	return m;
}

// Function to count the number of times s2 follows s1
int s2_follows_s1(string s1, string s2, multimap<string,int> m) {
	int count = 0;
	auto s1_it = m.find(s1);
	auto s2_it = m.find(s2);

	while(s1_it != m.end() && s2_it != m.end()) {
		//cout << s1_it->first << "," << s1_it->second << endl;
		//cout << s2_it->first << "," << s2_it->second << endl;
		int s1_pos = s1_it->second;
		int s2_pos = s2_it->second;
		// If the first second combination has been found increment the counter and advance to the next instances of first and second
		if(s1_pos + s1.length() == s2_pos)
			count++;
		// If first word position is before second word position then advance to the next instance of first word
		if(s1_pos < s2_pos) {
			m.erase(s1_it);
			s1_it = m.find(s1);
		}
		// If first word position is after second word position then advance to the next instance of second word
		else if(s1_pos > s2_pos) {
			m.erase(s2_it);
			s2_it = m.find(s2);
		}
		// If both pointers point to the same position, increment second and try again
		else if(s1_pos == s2_pos) {
			s2_it++;
		}
	}
	return count; 
}

int main(int argc, char **argv) {

	string filename = argv[1];

	// Using multimap structure as inputs words could be non-unique
	multimap<string, int> m;

	m = preprocess_file(filename);

	/*for(auto it = m.begin(); it != m.end(); it++)
		cout << it->first << "->" << it->second << endl;*/

	// Enter exit exit to exit!
	string input;
	while(true) {
		string s1 = "";
		string s2 = "";
		cin >> s1 >> s2;
		if(s1 == "exit" && s2 == "exit")
			break;
		int count = s2_follows_s1(s1, s2, m);
		cout << count << endl;
	}

	return 0;
}