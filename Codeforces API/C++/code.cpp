#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef LOCAL 
#include "/media/brayand/BrayanD/debugger.h"
#else
#define db(...) false
#define dbl(...) false
#define dbg(...) false
#define dbm(...) false
#define dbs(...) false
#define dbas(...) false
#endif

struct contest
{
	string id;
	string name;
	vector<pair<string,int>> v1, v2, v3;
};

vector<pair<string,int>> get(string cad)
{
	stringstream sss;
	sss << cad;

	vector<pair<string,int>> vect;
	string temp;
	int num;

	while(sss >> temp)
	{
		sss >> num;
		vect.push_back({temp,num});
	}

	return vect;
}

bool find(string cad, string pat)
{
	for(int i = 0 ; i+(int)pat.size()-1 < (int)cad.size() ; i++)
	{
		if(cad.substr(i,pat.size()) == pat)
		{
			return true;
		}
	}
	return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("data.out");

    vector<contest> vect;

    string cad;
    
    while(getline(fin,cad))
    {
    	contest C;
    	C.id = cad;
    	getline(fin,cad);
    	C.name = cad;
    	getline(fin,cad);
    	C.v1 = get(cad);
    	getline(fin,cad);
    	C.v2 = get(cad);
    	getline(fin,cad);
    	C.v3 = get(cad);
    	getline(fin,cad);

    	vect.push_back(C);
    }

    int cont = 0;

    for(auto x : vect)
    {
    	if(find(x.name,"(Div. 2)") && x.v2.size() && x.v2.size() == x.v1.size()-3)
    	{
    		db(x.id);
    		db(x.name);
    	}
    	// if(x.v2.size())
    	// {
    	// 	for(auto p : x.v3)
    	// 	{
    	// 		if(2000 <= p.second && p.second <= 2300)
    	// 		{
    	// 			db(x.id);
    	// 			db(x.name);
    	// 			db(x.v2);
    	// 			db(p);
    	// 			cout << '\n';
    	// 			cout << '\n';
    	// 		}
    	// 	}
    	// }
    }

    return 0;
}