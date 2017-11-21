#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

std::string mirror_end(const std::string & in)
{
	return std::string(in.begin(),
						std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}

int main(void)
{
	cout << mirror_end("abXYZba") << endl
		 << mirror_end("abca") << endl
		 << mirror_end("aba") << endl;

	return 0;
}
