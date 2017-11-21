#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

class wordStastics
{
public:
	void readFile(const string & filename);
	void writeFile(const string & filename);
private:
	map<string, int> _words;
};

void wordStastics::readFile(const string & filename)
{
	std::ifstream ifs(filename);
	if(!ifs.good())
	{
		cout << "ifstream open file error!" << endl;
		return;
	}

	string line;
	while(getline(ifs, line))
	{
		std::istringstream iss(line);
		string word;
		while(iss >> word)
		{
			++_words[word];
#if 0
			auto it = _word.find(word);
			if(it == _word.end())
			{
				_words.insert(std::make_pair(word, 1))
			}
			else
				++(it->second);
#endif
		}
	}
	ifs.close();
}

void wordStastics::writeFile(const string & filename)
{
	std::ofstream ofs(filename);
	if(!ofs.good())
	{
		cout << "ofstream open file error!" << endl;
		return;
	}

	for(auto it = _words.begin(); it != _words.end(); ++it)
	{
		ofs << it->first << "  " << it->second << endl;
	}
	ofs.close();
}

int main(void)
{
	wordStastics ws;
	ws.readFile("The_Holy_Bible.txt");
	ws.writeFile("dict.txt");

	return 0;
}
