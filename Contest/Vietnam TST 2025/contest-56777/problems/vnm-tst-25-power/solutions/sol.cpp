#include <bits/stdc++.h>
using namespace std;

struct opt
{
    char c;
    int i, j, k;

    void print ()
    {
        cout << c << ' ' << i << ' ' << j << ' ' << k << '\n';
    }
};

vector <opt> opt_list;

void ad (int i, int j, int k)
{
    opt_list.push_back ({'+', i, j, k});
}

void mu (int i, int j, int k)
{
    opt_list.push_back ({'*', i, j, k});
}

int print_all ()
{
    cout << opt_list.size () << '\n';
    for (auto i: opt_list) i.print ();
    return 0;
}

void pw (int i, int j, int tmp)
{
    if (j == 1) return;
    if (j % 2 == 0)
    {
        mu (i, i, i);
        pw (i, j / 2, tmp);
        return;
    }

    mu (i, i, tmp);
    j --;

    for (int x = 1; x <= 14; x ++)
    {
        if (j & (1 << x))
        {
            mu (i, tmp, i);
            j -= (1 << x);
        }
        if (j > 0) mu (tmp, tmp, tmp);
    }

    return;
}

int vp (int i, int j)
{
    int ans = 0;
    while (i % j == 0)
    {
        i /= j;
        ans ++;
    }

    return ans;
}

bool lt (int i, int j)
{
    while (i % j == 0) i /= j;
    return (i == 1);
}

const int MAX = 2e4 + 5;
int prime[MAX];

int main ()
{
    if (fopen ("PBML.inp", "r"))
    {
        freopen ("PBML.inp", "r", stdin);
        freopen ("PBML.out", "w", stdout);
    }

    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n;
    cin >> n;

    if (n == 1) return print_all ();
    if (n == 2)
    {
        ad (1, 1, 2);
        mu (2, 2, 2);
        return print_all ();
    }
    if (n < 23)
    {
        for (int i = 2; i <= n; i ++)
            ad (1, i - 1, i);

        for (int i = 3; i <= n; i ++)
            pw (i, i, 2);

        ad (1, 1, 2);
        mu (2, 2, 2);

        return print_all ();
    }

    int last_p = 1, cur_dif = 2;
    vector <int> p_list = {1};
    prime[1] = 1;

    for (int i = 2; i <= n; i ++)
    {
        if (prime[i] == 0)
        {
            for (int j = i; j <= n; j += i)
                prime[j] = i;

            int dif = i - last_p;

            if (dif >= cur_dif)
                for (; cur_dif <= dif; cur_dif ++)
                    if (prime[cur_dif] != cur_dif)
                        ad (1, (1 + (prime[cur_dif - 1] != cur_dif - 1)) * (cur_dif - 1), 2 * cur_dif);

            ad (last_p, (1 + (prime[dif] != dif)) * dif, i);

            p_list.push_back (i);
            last_p = i;
        }
    }

    /*
    for (int i = 3; i <= cur_dif * 2; i ++)
        if (prime[i] != i) mu (1, 1, i);
            */

    for (int i = n; i >= 3; i --)
    {
        if (prime[i] == i)
        {
            int next_p = upper_bound (p_list.begin (), p_list.end (), i) - p_list.begin ();
            next_p = p_list[next_p];

            pw (i, i, 8);

            for (int x = i; x <= n; x *= i)
            {
                pw (x, vp (x, i), 8);
                if (x > n / 3) break;

                int last_cell = x, gap = 0, prev_gap = 0;
                mu (x, x, 8);

                if (x != i and x * (i + 2) <= n) mu (8, 8, 14);
                if (x == i and x * (3 * i + 2) <= n) mu (8, 8, 14);

                for (int j = 3; j * x <= n; j += 2)
                {
                    if (prime[x * j] == i)
                    {
                        if (vp (j, i) == 0 or (x == i and lt (j, i)))
                        {
                            if (gap == 0) mu (8, last_cell, x * j);
                            else mu (14, last_cell, x * j);
                            gap = 0;

                            last_cell = x * j;
                        }
                        else gap = 1;
                    }
                    else
                    {
                        if (vp (j, i) == 0)
                        {
                            if (gap == 0) mu (8, last_cell, i - 1);
                            else mu (14, last_cell, i - 1);
                            gap = 0;
                            mu (i - 1, x * j, x * j);
                            last_cell = i - 1;
                        }
                        else gap = 1;
                    }
                }

                continue;
            }
        }
    }

    ad (1, 1, 2);

    for (int i = 4; i <= n; i += 2)
        ad (i - 2, i - 2, i);

    for (int i = 2; i <= n; i += 2)
    {
        if (i > 2) mu (i / 2, i, i);
        mu (i, i, i);
    }

    return print_all ();
}
