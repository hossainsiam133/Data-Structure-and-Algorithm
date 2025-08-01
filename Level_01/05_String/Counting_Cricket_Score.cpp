#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string s;
    int n = 0;
    float over;
    while (n < t)
    {
        cin >> s;
        int l = s.size();
        int tempin = l / 6;
        over = (float)tempin + (float)(l % 6) / 10;
        int run = 0, wicket = 0;
        for (int i = 0; i < l; i++)
        {
            switch (s[i])
            {
            case '1':
            {
                run++;
                break;
            }
            case '2':
            {
                run = run + 2;
                break;
            }
            case '3':
            {
                run = run + 3;
                break;
            }
            case '4':
            {
                run = run + 4;
                break;
            }
            case '5':
            {
                run = run + 5;
                break;
            }
            case '6':
            {
                run = run + 6;
                break;
            }
            case 'W':
            {
                wicket++;
                break;
            }
            }
        }
        if (over > 1.0)
        {
            printf("%.1f Overs ", over);
        }
        else
            printf("%.1f Over ", over);
        if (run > 1)
        {
            cout << run << " Runs ";
        }
        else
            cout << run << " Run ";
        if (wicket > 1)
        {
            cout << wicket << " Wickets.";
        }
        else
            cout << wicket << " Wicket.";
        cout << endl;
        n++;
    }
    return 0;
}