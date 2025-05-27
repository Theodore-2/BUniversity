#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

class Kitap{
	public:
		string isim;
		int populerlik;
		
	Kitap(const string &isim, int populerlik) : isim(isim), populerlik(populerlik){	}
};

class Ogrenci{
	public:
		string isim;
		vector<Kitap> kitaplar;

	Ogrenci(const string &isim): isim(isim){}
	
};

bool populerlikSirala(const Kitap &a, const Kitap &b){
	return a.populerlik > b.populerlik;
}

int main(){
	
	vector<Kitap> kitaplar;
	kitaplar.push_back(Kitap("Matematik",8));
	kitaplar.push_back(Kitap("Tarih",5));
	kitaplar.push_back(Kitap("Fizik",7));
	
	sort(kitaplar.begin(),kitaplar.end(), populerlikSirala);
	
	vector<Ogrenci> ogrenciler;
	ogrenciler.push_back(Ogrenci("Ahmet"));
	ogrenciler.push_back(Ogrenci("Ayse"));
	ogrenciler.push_back(Ogrenci("Ali"));
	
	for (size_t i = 0; i < ogrenciler.size(); i++) {
        ogrenciler[i].kitaplar.push_back(kitaplar[i % kitaplar.size()]);
    }
    
    stack<Kitap> kitapStack;
    vector<Kitap> kitapVector;
    
    for (vector<Kitap>:: iterator it= kitaplar.begin(); it != kitaplar.end(); ++it){
    	kitapStack.push(*it);
    	kitapVector.push_back(*it);
	}


    cout << "Popülerlik sýrasýna göre kitaplar:" << endl;
	for(vector<Kitap>::iterator it=kitaplar.begin(); it != kitaplar.end();++it){
		cout<< it->isim << " ("<< it->populerlik <<") "<<endl;
	}
	
	cout << "\nÖðrenciler ve kitaplarý:" << endl;
	for(vector<Ogrenci>::iterator it= ogrenciler.begin(); it !=ogrenciler.end();++it){
		cout<< it->isim <<" -> ";
		for(vector<Kitap>::iterator KitIt= it-> kitaplar.begin(); KitIt != it-> kitaplar.end(); ++KitIt)
			cout<< KitIt->isim<<" ("<<KitIt->populerlik<< ") ";
	
		cout<<endl;
	}
	
	cout<<"\nKitap stack:" << endl;
	while(!kitapStack.empty()){
		Kitap k= kitapStack.top();
		cout<<k.isim<<" ("<<k.populerlik<<")"<<endl;
		kitapStack.pop();
	}
	
	cout<<"\nKitap veector"<<endl;
	for(vector<Kitap>::iterator it= kitapVector.begin(); it!=kitapVector.end();++it)
		cout<< it->isim << " ("<< it->populerlik<<")"<<endl;
	
	return 0;
}












