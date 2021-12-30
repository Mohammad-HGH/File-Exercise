#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line;
    int i = 0;
    vector<string> v;
    ifstream fin;
    ofstream fout;
    fin.open("./input.txt");
    fout.open("./output.txt");
    if (fin.is_open())
    {
        while (getline(fin, line))
        {
            stringstream ss(line);
            while (getline(ss, line, '\n'))
            {
                v.push_back(line);
            }
        }
        string word1, word2;
        word1 = v[0].erase(0, 1);
        word2 = v[1].erase(0, 1);
        for (int i = 2; i < v.size(); i++)
        {
            while (v[i].find(word1) != string::npos)
                v[i].replace(v[i].find(word1), word1.length(), word2);
            fout << endl
                 << v[i];
        }
    }
    fin.close();
    fout.close();
    return 0;
}