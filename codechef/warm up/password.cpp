#include<bits/stdc++.h>
using namespace std;

bool isValid(string password) 
{ 

	// For checking if password length 
	// is between 8 and 15 
	if (!(password.length() >= 10)) return false; 
	string vir;
	if (true) 
	{ 
		int count = 0; 
		// Check digits from 0 to 9 
		for(int i = 0; i <= 9; i++) 
		{ 			
			// To convert int to string 
			std::string str1 = std::to_string(i); 
			vir=str1.substr(1, str1.size() - 2);
			if (password.find(vir) != 
				std::string::npos) 
				count = 1; 
		} 
		if (count == 0) 
			return false; 
	} 
	// For special characters 
	if (!((password.find("@") != std::string::npos) || 
		(password.find("#") != std::string::npos) || 
		(password.find("!") != std::string::npos) || 
		(password.find("~") != std::string::npos) || 
		(password.find("$") != std::string::npos) || 
		(password.find("%") != std::string::npos) || 
		(password.find("^") != std::string::npos) || 
		(password.find("&") != std::string::npos) || 
		(password.find("*") != std::string::npos) || 
		(password.find("(") != std::string::npos) || 
		(password.find(")") != std::string::npos) || 
		(password.find("-") != std::string::npos) || 
		(password.find("+") != std::string::npos) || 
		(password.find("/") != std::string::npos) || 
		(password.find(":") != std::string::npos) || 
		(password.find(".") != std::string::npos) || 
		(password.find(",") != std::string::npos) || 
		(password.find("<") != std::string::npos) || 
		(password.find(">") != std::string::npos) || 
		(password.find("?") != std::string::npos) || 
		(password.find("|") != std::string::npos))) 
		return false; 
	
	if (true) 
	{ 
		int count = 0; 
		for(int i = 65; i <= 90; i++) 
		{ 
			char c = (char)i; 
			string str1(1, c); 
			
			if (password.find(vir) != 
				std::string::npos) 
				count = 1; 
		} 
		if (count == 0) 
			return false; 
	} 

	if (true) 
	{ 
		int count = 0; 
		for(int i = 90; i <= 122; i++) 
		{ 
			// Type casting 
			char c = (char)i; 
			string str1(1, c); 

			if (password.find(str1) != 
				std::string::npos) 
				count = 1; 
		} 
		if (count == 0) 
			return false; 
	} 
	return true; 
} 

// Driver code 
int main() 
{ 
	int t; cin>>t;
	while(t--){
		string s;
		cin>>s;
		if (isValid(s))  cout << "YES" << endl; 
		else cout << "NO" << endl; 
	}
	return 0;
} 

