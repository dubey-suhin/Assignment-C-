#include <iostream>
using namespace std;

class str
{
    string s;

public:
    str()
    {
        s = "";
    }
    str(string s)
    {
        this->s = s;
    }
    string concatenate(str s1)
    {
        return (s + s1.s);
    }
    bool compare(str s1)
    {
        bool f = false;
        if (s.size() == s1.s.size())
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == s1.s[i])
                {
                    f = true;
                }
                else
                {
                    f = false;
                    break;
                }
            }
        }
        return f;
    }
    void display(){
        cout << s << endl;
    }
};

int main()
{
    string s1, s2;
    cout << "Enter String 1: ";
    cin >> s1;
    cout << "Enter String 2: ";
    cin >> s2;
    str S1(s1), S2(s2);

    cout << "S1 :";
    S2.display();
    cout << "S2 :";
    S1.display();
    if (S1.compare(S2))
        cout << "Equal";
    else
        cout << "Not Equal";

    cout << "\nS1+S2 : " << S1.concatenate(S2);
    return 0;
}

