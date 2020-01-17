#include <bits/stdc++.h>
using namespace std;


class Check
{
private:
	bool right;
	string mode;
	string filename1;
	string filename2;
	set<pair<int, int>> k1;
	set<pair<int, int>> k2;
	set<int> c1;
	set<int> c2;
public:
	Check(char*, char*, char*);
	void read(void);
	void compare(void);
	void write(void);
};

int main(int argc, char* argv[])
{
	Check Sol(argv[1], argv[2],argv[3]);
	Sol.read();
	Sol.compare();
	Sol.write();
	return 0;
}

Check::Check(char* name1,char* name2, char* mode)
{
	this->mode = mode;
	filename1 = name1;
	filename2 = name2;
}
void Check::read(void)
{
	fstream file1;
	fstream file2;
	file1.open(filename1, ios::in);
	file2.open(filename2, ios::in);
	if (mode == "k")
	{
		int id, coreness;
		while (file1 >> id >> coreness)
			k1.insert(pair<int, int>(id, coreness));
		while (file2 >> id >> coreness)
			k2.insert(pair<int, int>(id, coreness));

	}
	else if (mode == "c")
	{
		int id;
		while (file1 >> id)
			c1.insert(id);
		while (file2 >> id)
			c2.insert(id);
	}
	file1.close();
	file2.close();
}
void Check::compare(void)
{
	if (mode == "k")
	{
		if (includes(k1.begin(), k1.end(), k2.begin(), k2.end())==true && k1.size() == k2.size())
			right = true;
		else
			right = false;
	}
	else if (mode == "c")
	{
		if (includes(c1.begin(), c1.end(), c2.begin(), c2.end())==true && c1.size() == c2.size())
			right = true;
		else
			right = false;
	}
}
void Check::write(void)
{
	fstream file;
	file.open("compare_result.txt", ios::out);
	if (right)
		file << "same\n";
	else
		file << "different\n";
	file.close();
}
