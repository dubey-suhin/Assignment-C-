#include <iostream>
using namespace std;

class str{
    string s;
public:
    str(){
        s = "";
    }
    str(string s){
        this->s = s;
    }
    str operator+=(const str &s){
        this->s = this->s + s.s;
        return *this;
    }
    void display(){
        cout << s << endl;
    }
};

int main(){
    string s1, s2;
    cout << "Enter String 1: ";
    cin >> s1;
    cout << "Enter String 2: ";
    cin >> s2;
    str S1(s1), S2(s2);

    cout << "S1 :";
    S1.display();
    cout << "S2 :";
    S2.display();
  
    str S3= S1 += S2;
    cout << "\nS3= S1 += S2 :";
    S3.display();
    return 0;
}
