#include<iostream>
#include<queue>

using namespace std;

int main(){
	
	queue<int> S;
	
	for(int i=1; i<=5;i++)
		S.push(i);
		
		cout<<"Queue size= "<<S.size()<<endl;
		cout<<"Poping the queue! "<<endl;
	
	
	while(!S.empty()){
		cout<< S.front()<<" ";
		S.pop();
	}
	
	
	return 0;
}


#include<queue>
#include <iostream>

using namespace std;

int main(){
	
	queue<int> S;
	for(int i=1;i<=5;i++)
		S.push(i);
	
	cout<<"queue size: "<<s.size()<<endl;
	while(!S.empty()){
		cout<<S.front()<<" ";
		S.pop();
	}
	
	return 0;
}
