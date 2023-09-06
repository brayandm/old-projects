#include <bits/stdc++.h>

using namespace std;

struct buscador
{
    const int oo = 1e9;
    const long double median = 10.0;
    vector<string> informacion;
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
    long long puntaje(string s1, string s2)
    {
        vector<string> v1;
        vector<string> v2;
        s1 += '_';
        s2 += '_';
        string temp;
        for(int i = 0 ; i < s1.size() ; i++)
        {
            if(s1[i] != '_')temp += s1[i];
            else
            {
                v1.push_back(temp);
                temp = "";
            }
        }
        for(int i = 0 ; i < s2.size() ; i++)
        {
            if(s2[i] != '_')temp += s2[i];
            else
            {
                v2.push_back(temp);
                temp = "";
            }
        }
        int N = v1.size();
        int M = v2.size();
        if(N > M)
        {
            swap(N,M);
            swap(v1,v2);
        }
        vector<vector<long long>> vect(N);
        for(int i = 0 ; i < N ; i++)vect[i].resize(M);
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < M ; j++)
            {
                long double tam = max(v1[i].size(),v2[j].size());
                long double sum = (v1[i].size() + v2[j].size())/2.0;
                long double prop = (1.0-((long double)edit_distance(v1[i],v2[j]))/tam);
                long double cost = (median + sum)*prop - (long double)(abs(i-j));
                if(cost < 0)cost = 0;
                vect[i][j] = cost*1000000.0;
            }
        }
        return max_assignment<long long> (vect);
    }
    bool is_esp(char c)
    {
        if(c == ' ' || c == '\t')return true;
        return false;
    }
    void convert(string &cad)
    {
        string temp;
        for(int i = 0 ; i < cad.size() ; i++)
        {
            if(i && is_esp(cad[i]) && !is_esp(cad[i-1]))
            {
                temp += '_';
            }
            else if(!is_esp(cad[i]))
            {
                temp += tolower(cad[i]);
            }
        }
        if(temp.size() && temp.back() == '_')temp.pop_back();
        cad = temp;
    }
    void add(string cad)
    {
        convert(cad);
        if(cad.size())
        {
            informacion.push_back(cad);
        }
    }
    string buscar(string cad)
    {
        convert(cad);
        if(!cad.size())return "";
        vector<pair<long long,int>> vect;
        for(int i = 0 ; i < informacion.size() ; i++)
        {
            vect.push_back({puntaje(cad,informacion[i]),i});
        }
        sort(vect.begin(),vect.end());
        reverse(vect.begin(),vect.end());
        if(!vect.size())return "";
        return informacion[vect[0].second];
    }
};
