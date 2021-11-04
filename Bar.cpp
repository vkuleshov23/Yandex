#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Ingredients{
private:
	int h;
	char symb;
public:
	Ingredients(int height, char c){
		h = height;
		symb = c;
	}
	int getH(){
		return h;
	}
	char getSymb(){
		return symb;
	}
};

vector<string> readGlass(int h){
	vector<string> glass;
	string layer = "-";
	for (int i = 0; i < h+1; i++) {
		getline(cin, layer);
		if(layer == "")
			continue;
		glass.push_back(layer);
	}
	return glass;
}

void change(vector<string>& glass, char symb, int i, int w){
	for (int j = 0; j < w; j++){
		if(glass[i][j] == ' ')
			glass[i][j] = symb;
	}
}

int findInt(string data){
	int i = 0;
	for(;data[i] != ' ';i++){}
	string integer = "";
	i++;
	for(;data[i] != ' '; i++){
		integer += data[i];
	}
	return stoi(integer);
}

vector<Ingredients> readIngreds(int layers){
	vector<Ingredients> ingreds;
	char ing = ' ';
	int height = 0;
	string name = "";
	for (int i = 0; i < layers+1; i++){
		getline(cin, name);
		if(name == "")
			continue;
		height = findInt(name);
		ing = name[name.size()-1];
		ingreds.push_back(Ingredients(height, ing));
	}
	return ingreds;
}

void fill(int w, int h, vector<string>& glass, vector<Ingredients>& ingreds){
	h -= 2;
	for (int i = 0; i < ingreds.size(); i++){
		for (int j = 0; j < (ingreds[i]).getH(); j++){
			change(glass, (ingreds[i]).getSymb(), h, w);
			h--;
		}
	}
}

int main(){
	int w = 0, h = 0;
	cin >> h >> w;
	vector<string> glass = readGlass(h);
	int layers = 0;
	cin >> layers;
	vector<Ingredients> ingreds = readIngreds(layers);
	fill(w, h, glass, ingreds);
	for (string str : glass){
		for (char c : str){
			cout << c;
		}
		cout << '\n';
	}
	return 0;
}