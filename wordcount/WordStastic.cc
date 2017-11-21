#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct Record
{
	string word;
	int count;
};

class WordStastic
{
public:
	void readFile(const string & filename);
	void writeFile(const string & filename);
private:
	vector<Record> _words;
};

void WordStastic::readFile(const string & filename)
{
	ifstream ifs(filename);
	if(!ifs.good())
	{
		cout << "ifs open file error" << endl;
		ifs.close();
		return;
	}
	string line;
	string word;
	size_t idx;
	while(getline(ifs, line))
	{
		istringstream iss(line);
		while(iss >> word)
		{
			for(idx = 0; idx != _words.size(); ++idx)
			{
				if(_words[idx].word == word)
				{
					++_words[idx].count;
					break;
				}
			}
			if(idx == _words.size())
			{
				Record rec = {word, 1};
				_words.push_back(rec);
			}
		}
	}

}

void WordStastic::writeFile(const string & filename)
{
	size_t idx;
	ofstream ofs(filename);
	if(!ofs.good())
	{
		cout << "ofs open file error" << endl;
		ofs.close();
		return;
	}

	for(idx = 0; idx != _words.size(); ++idx)
	{
      	ofs << "[" << _words[idx].word << "] " << _words[idx].count << endl;
	}
	ofs.close();
}

int main(void)
{
	WordStastic ws;
	ws.readFile("The_Holy_Bible.txt");
	ws.writeFile("wordCount.dat");

	return 0;
}
