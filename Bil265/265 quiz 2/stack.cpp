#include<iostream>
#include<stack>

using namespace std;

int main(){
	
	stack<int> S;
	
	for(int i=1; i<=5;i++)
		S.push(i);
		
		cout<<"Stack size= "<<S.size()<<endl;
		cout<<"Poping the stack! "<<endl;
	
	
	while(!S.empty()){
		cout<< S.top()<<" ";
		S.pop();
	}
	
	
	return 0;
}

/*
#include<iostream>
#include<stack>

using namespace std;

int main(){
	
	stack<int> s;
	
	for(int i=1; i<=5; i++){
		s.push(i);
	}

	cout<<"size of stack: "<<s.size()<<endl;
	
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop
	}
	
	return 0;
}

*/
