#include <bits/stdc++.h>

using namespace std;

struct buscador
{
    const int oo = 1e9;
    const long double median = 10.0;
    template<typename T>
    T max_assignment(const vector<vector<T>> &a)
    {
        int n = a.size(), m = a[0].size();
        assert(n <= m);
        vector<int> x(n, -1), y(m, -1);
        vector<T> px(n, numeric_limits<T>::min()), py(m, 0);
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < m; ++v) px[u] = max(px[u], a[u][v]);
        for (int u = 0, p, q; u < n;)
        {
            vector<int> s(n + 1, u), t(m, -1);
            for (p = q = 0; p <= q && x[u] < 0; ++p)
                for (int k = s[p], v = 0; v < m && x[u] < 0; ++v)
                    if (px[k] + py[v] == a[k][v] && t[v] < 0)
                    {
                        s[++q] = y[v], t[v] = k;
                        if (s[q] < 0)
                            for (p = v; p >= 0; v = p)
                                y[v] = k = t[v], p = x[k], x[k] = v;
                    }
            if (x[u] < 0)
            {
                T delta = numeric_limits<T>::max();
                for (int i = 0; i <= q; ++i)
                    for (int v = 0; v < m; ++v) if (t[v] < 0)
                            delta = min(delta, px[s[i]] + py[v] - a[s[i]][v]);
                for (int i = 0; i <= q; ++i)
                    px[s[i]] -= delta;
                for (int v = 0; v < m; ++v)
                    py[v] += (t[v] < 0 ? 0 : delta);
            }
            else ++u;
        }
        T cost = 0;
        for (int u = 0; u < n; ++u)
            cost += a[u][x[u]];
        return cost;
    }
    int edit_distance(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        int dp[n+1][m+1];
        for(int i = 0 ; i <= n ; i++)
        {
            dp[i][0] = i;
        }
        for(int j = 0 ; j <= m ; j++)
        {
            dp[0][j] = j;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= m ; j++)
            {
                dp[i][j] = oo;
                int delta = !(s1[i-1] == s2[j-1]);

                if(dp[i-1][j] + 1 < dp[i][j])
                {
                    dp[i][j] = dp[i-1][j] + 1;
                }
                if(dp[i][j-1] + 1 < dp[i][j])
                {
                    dp[i][j] = dp[i][j-1] + 1;
                }
                if(dp[i-1][j-1] + delta < dp[i][j])
                {
                    dp[i][j] = dp[i-1][j-1] + delta;
                }
            }
        }
        return dp[n][m];
    }
    long long puntaje(vector<string> v1, vector<string> v2)
    {
        int N = v1.size();
        int M = v2.size();

        if(N > M)
        {
            swap(N,M);
            swap(v1,v2);
        }

        if(N == 0)return -1e18;

        vector<vector<long long>> vect(N, vector<long long>(M));

        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
            	long double sz1 = v1[i].size();
       			long double sz2 = v2[j].size();
                long double tam = max(sz1, sz2);
                long double sum = (sz1 + sz2)/2.0;
                long double prop = (1.0-((long double)edit_distance(v1[i], v2[j]))/tam);
                long double cost = (median + sum) * prop - (long double)(abs(i-j));
                if(cost < 0)cost = 0;
                vect[i][j] = cost*1000000.0;
            }
        }
        return max_assignment<long long> (vect);
    }
};

int main()
{
	ifstream fin("input.txt");

	vector<char> alpha;

    for(char c = 32 ; c <= 126 ; c++)
    {
    	alpha.push_back(c);
    }

    function<bool(char)> is_alpha = [&](char c)
    {
    	if('a' <= c && c <= 'z')return true;
    	if('A' <= c && c <= 'Z')return true;
    	return false;
    };

    function<char(char)> to_lower = [&](char c)
    {
    	if('A' <= c && c <= 'Z')return (char)(c-'A'+'a');
    	return c;
    };

    function<vector<string>(string)> convert = [&](string cad)
    {
    	for(int i = 0 ; i < cad.size() ; i++)
    	{
	    	if(!is_alpha(cad[i]) && cad[i] != ' ')
			{
				cad[i] = ' ';
			}
			cad[i] = to_lower(cad[i]);
    	}

    	cad += " ";

		vector<string> tv;

		string tp;

		for(int i = 0 ; i < cad.size() ; i++)
		{
			if(cad[i] == ' ')
			{
				if(tp.size())
				{
					tv.push_back(tp);
					tp.clear();
				}
			}
			else
			{
				tp += cad[i];
			}
		}

		return tv;
    };

    vector<string> original;
    vector<string> temporal;

	string temp;

	while(getline(fin,temp))
	{
		string cad;

		for(int i = 0 ; i < temp.size() ; i++)
		{
			bool flag = false;

			for(auto x : alpha)
			{
				if(temp[i] == x)
				{
					flag = true;
				}
			}

			if(flag)cad += temp[i];
			else cad += " ";
		}
		original.push_back(temp);
		temporal.push_back(cad);
	}

	vector<vector<string>> vvv;

	for(auto sss : temporal)
	{
		int cont = 0;
		int pos = 0;
		for(auto x : sss)
		{
			if(x == ':')
			{
				cont++;
			}
			pos++;
			if(cont == 2)break;
		}

		if(cont < 2)
		{
			pos = 0;
		}

		string ttt;

		for(int i = pos ; i < sss.size() ; i++)
		{
			ttt += sss[i];
		}

		vvv.push_back(convert(ttt));
	}

	assert(vvv.size() == original.size());

	buscador BQ;

	while(1)
	{
		vector<pair<long long,int>> ind;

		string cad_patron;

		getline(cin,cad_patron);

		vector<string> patron = convert(cad_patron);

		int maydist = patron.size()*3;

		for(int i = 0 ; i < vvv.size() ; i++)
		{
			long long punt = -1e18;

			for(int j = 0 ; j < vvv[i].size() ; j++)
			{
				vector<string> vtt;
				for(int x = 0 ; x < maydist ; x++)
				{
					if(j+x < vvv[i].size())
					{
						vtt.push_back(vvv[i][j+x]);
						punt = max(punt, BQ.puntaje(vtt, patron));
					}
				}
			}
			
			ind.push_back({punt,i});
		}

		sort(ind.rbegin(), ind.rend());

		cout << '\n';

		for(int i = 0 ; i < min((int)ind.size(), 5) ; i++)
		{
			cout << original[ind[i].second] << '\n';
			cout << '\n';
		}
	}


    return 0;
}