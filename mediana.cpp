#include <iostream>
#include <vector>

using namespace std;


int sum(vector<int>& vec){
	int sum = 0;
	for (int i = 0; i < vec.size(); i++){
		sum += vec[i];
	}
	return sum;
}
int max(vector<int>& vec){
	int max = vec[0];
	for (int i = 0; i <= vec.size(); i++){
		if(vec[i] > max){
			max = vec[i];
		}
	}
	return max;
}
int min(vector<int>& vec){
	int min = vec[0];
	for (int i = 0; i <= vec.size(); i++){
		if(vec[i] < min){
			min = vec[i];
		}
	}
	return min;
}

int calc(vector<int> arr, int i, int j){
	arr[i] = arr[i] - arr[j];
	
	int median = (sum(arr) - max(arr)) - min(arr);
	return median;
}
int calcSRC(vector<int> arr){
	int median = (sum(arr) - max(arr)) - min(arr);
	return median;
}
void check(vector<int> arr, vector<bool>& res, int median){
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] == median){
			res[i] = 1;
		}
	}
}

void findMedians(vector<int>& arr, vector<bool>& res){
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < arr.size(); j++){
			if(i != j){
				check(arr, res, calc(arr, i, j));
			}
		}
	}
}

int main(){
	vector<int> arr;
	vector<bool> res;
	int size = 3;
	for (int i = 0, data = 0; i < 3; i++){
		cin >> data;
		arr.push_back(data);
		res.push_back(false);
	}
	check(arr, res, calcSRC(arr));
	findMedians(arr, res);
	for(bool med : res){
		cout << (med? "YES" : "NO") << '\n';
	}

	return 0;
}