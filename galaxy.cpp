#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <thread>

using namespace std;


static bool compare( long int p1,  long int p2) {
    return p1 < p2;
}

 long int findMax(int from, int to, vector< long int>& vec){
	 long int max = 0;
	for (int i = from; i <= to; i++){
		if(vec[i] > max){
			max = vec[i];
			// cout << "max: " << max << '\n';
		}
	}
	return max;
}

void findRealSize(vector< long int>& slabsVec){
	vector< long int> copyVec = slabsVec;
	for(int i = slabsVec.size()-2; i >= 0; i--){
		long int max = findMax(i+1, slabsVec.size()-1, copyVec);
		slabsVec[i] = slabsVec[i] - max;
		if(slabsVec[i] < 0) slabsVec[i] = 0;
		
		// cout << "copyVec\n";
		// for( long int i : copyVec){
		// 	cout << i << ' ';
		// }
		// cout << '\n';
	}
}

 long int check( long int peopSize, vector< long int>& slabsVec){
	for( long int i = 0; i < slabsVec.size(); i++){
		if(peopSize <= slabsVec[i]){
			return i;
		}
	}
	return -1;
}

 long int sum(vector< long int>& peopVec, vector< long int>& slabsVec){
	 long int sum = 0;
	for( long int peopSize : peopVec){
		 long int res = check(peopSize, slabsVec);
		if(res == -1){
			break;
		} else{
			slabsVec.erase(slabsVec.begin() + res);
			sum++;
		}
	}
	return sum;
}

void sorting(vector< long int> vec){
	sort(vec.begin(), vec.end(), compare);
}

int main(){
	 long int slabs = 0, peop = 0;
	cin >> slabs >> peop;
	vector< long int> slabsVec;
	vector< long int> peopVec;
	for( long int i = 0, size = 0; i < slabs; i++){
		cin >> size;
		slabsVec.push_back(size);
		// slabsSet.insert(size);
	}
	for( long int i = 0, size = 0; i < peop; i++){
		cin >> size;
		peopVec.push_back(size);
	}
	
	// cout << "slabs\n";
	// for( long int i : slabsVec){
	// 	cout << i << ' ';
	// }
	// cout << '\n';

	// cout << "realSize\n";
	findRealSize(slabsVec);
	// cout << "end realSize\n";

	// cout << "slabs\n";
	// for( long int i : slabsVec){
	// 	cout << i << ' ';
	// }
	// cout << '\n';

	sort(peopVec.begin(), peopVec.end(), compare);
	sort(slabsVec.begin(), slabsVec.end(), compare);


	// cout << "slabs\n";
	// for( long int i : slabsVec){
	// 	cout << i << ' ';
	// }
	// cout << '\n';


	// cout << "People\n";
	// for( long int i : peopVec){
	// 	cout << i << ' ';
	// }
	// cout << '\n';


	cout << sum(peopVec, slabsVec) << '\n';

	return 0;
}