#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
	
	priority_queue<int> S;
	
	for(int i=1; i<=5;i++){
		S.push(i);
		cout<<S.top()<<"";
	}
	
	
	
	while(!S.empty()){
		cout<< S.front()<<" ";
		S.pop();
	}
	
	
	return 0;
}
