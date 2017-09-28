
/*
 * Generate all substrings of a given string in lexographic order.
 * @author: ArvindRS
 * @date: 09/28/2017
 */

#include <iostream>
#include <map> // We could use a set too
using namespace std;

// Function to insert the char into a given string in lexographic order
string append_char(string s, char c) {
	int lo = 0;
	int hi = s.length()-1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(c < s[mid])
			hi = mid-1;
		else
			lo = mid+1;
	}
	int insertion_point = lo;
	string sub1 = s.substr(0,insertion_point);
	string sub2 = s.substr(insertion_point, s.length());
	return sub1 + c + sub2;
}

// Function to recursively generate all possible lexographic substrings
void find_all_substrings(string char_set, string prefix, map<string,int> &m) {
	for(int i = 0; i < char_set.length(); i++) {
		char c = char_set[i];
		// Check if character already in the prefix
		if(prefix.find(c) != std::string::npos)
			continue;
		// Create new prefix by inserting char in correct position in prefix
		string new_prefix = append_char(prefix, c);
		// Check if prefix is available in map
		if(m.find(new_prefix) != m.end())
			continue;
		// Else add the prefix to the map and recurse down
		m.insert(pair<string,int>(new_prefix,1));
		find_all_substrings(char_set, new_prefix, m);
	}
}

// Main Function
int main() {
	string test1 = "abc";
	map<string, int> m;
	find_all_substrings(test1,"",m);

	cout << m.size() << endl;
	for(auto it = m.begin(); it != m.end(); it++)
		cout << it->first << endl;
}