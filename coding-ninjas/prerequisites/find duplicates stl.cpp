#include<bits/stdc++.h>
using namespace std;

vector<int> duplicate(vector<int> input){
	set<int>s;
	vector<int> result;
	for(int i=0;i<input.size();i++){
		if(s.find(input[i])==s.end()){
			s.insert(input[i]);
			result.push_back(input[i]);
		}
	}
	return result;
}


//method2
vector<int> duplicate(vector<int> input){
	vector<int> result;
	sort(input.begin(),input.end());
	result.puch_back(input[i]);
	for(int i=0;i<input.size();i++){
		if(input[i]!=input[i-1]){
			result.push_back(input[i]);
		}
	}

	return result;
}

