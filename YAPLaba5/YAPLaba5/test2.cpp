#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Fraction {
    int numerator; // ���������
    int denominator; // �����������
        
public:

    void simplify() { // ����� ���������� �����
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        if (abs(numerator) < 2) return;
        /*cout << numerator << "/" << denominator << endl;*/
        int gcd = getGCD(abs(numerator), denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    // ������������
    Fraction(int nominator, int denominator) : numerator(nominator), denominator(denominator) {
        if (this->denominator == 0) throw logic_error("Division by zero.");
        simplify();
    }

    Fraction() : numerator(0), denominator(1) {}
    Fraction(const Fraction& other) : numerator(other.getNominator()), denominator(other.getDenominator()) {} // ����������� �����������
    Fraction(int value) : numerator(value), denominator(1) {}
 
    ~Fraction() {} // ����������

    // �������
    int getNominator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // ����� �������. �������������
    double dfraction() { double num = numerator, den = denominator; return (num / den); }

    // ������������
    int compareTo(const Fraction& other) const {
        return numerator * other.denominator - denominator * other.numerator;
    }

    // ����� ����. ������ ���������
    static int getGCD(int a, int b) {
        while (a != b)
            if (a > b) a -= b; else b -= a;
        return a;
    }

    //  ������ ����� � ���� � ���� � �������
    friend ofstream& operator << (ofstream& ofs, const Fraction& fraction) { // �����
        ofs << fraction.getNominator() << '/' << fraction.getDenominator();
        return ofs;
    }

    friend ifstream& operator >> (ifstream& ifs, Fraction& fraction) { // ����
        ifs >> fraction.numerator >> fraction.denominator;
        return ifs;
    }

    // � �����. �������� ����
    friend Fraction operator-(const Fraction& a) {return Fraction(-a.numerator, a.denominator);}

    friend Fraction operator+(const Fraction& a, const Fraction& b) {
        int commonDenominator = a.denominator * b.denominator;
        int commonNominator = a.numerator * b.denominator + b.numerator * a.denominator;
        return Fraction(commonNominator, commonDenominator);
    }

    friend Fraction operator-(const Fraction& a, const Fraction& b) {return a + -b; }
    friend Fraction operator*(const Fraction& a, const Fraction& b) { return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);}
    friend Fraction operator/(const Fraction& a, const Fraction& b) { return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);}
};

// ���������� ������� ����������
bool operator==(const Fraction& a, const Fraction& b) { 
    return a.compareTo(b) == 0; }

bool operator<(const Fraction& a, const Fraction& b) { 
    return a.compareTo(b) < 0; }

bool operator>(const Fraction& a, const Fraction& b) { 
    return a.compareTo(b) > 0; }

bool operator<=(const Fraction& a, const Fraction& b) { 
    return a.compareTo(b) <= 0; }

bool operator>=(const Fraction& a, const Fraction& b) { 
    return a.compareTo(b) >= 0; }

char returner(const Fraction a, const Fraction b){ // ��������� ��������������� ������� ��� ����������� �����
    if (a == b) {
        return '=';
    }
    else if (a < b) {
        return '<';

    }else {

        return '>';
    }
}

// ������� ���������� �����
void methodology(ifstream& ifs_fin, ofstream& ofs_out) {
    char op;
    ifs_fin >> op;

    Fraction a;
    ifs_fin >> a;
    switch (op) {
    case '+': {
        Fraction b;
        ifs_fin >> b;
        ofs_out << (a + b);
        break;
    }
    case '-': {
        Fraction b;
        ifs_fin >> b;
        ofs_out << (a - b);
        break;
    }

    case '*': {
        Fraction b;
        ifs_fin >> b;
        ofs_out << (a * b);
        break;
    }
    case '/': {
        Fraction b;
        ifs_fin >> b;
        ofs_out << (a / b);
        break;
    }
    case '>': {
        Fraction b;
        ifs_fin >> b;
        ofs_out << a << " " << returner(a, b) << " ";
        ofs_out << b;
        break;
    }
    case 'e': {
        Fraction b;
        ifs_fin >> b;

        if (a > b) {
            ofs_out << a << " >= ";
            ofs_out << b;
        }
        else {

            ofs_out << a << " <= ";
            ofs_out << b;
        }
        break;
    }
    case 'd': {
  
        ofs_out << a.dfraction();
        break;
    }
    case 's': {
        a.simplify();
        ofs_out << a;
        break;
    }
    case 'r': {
        ofs_out << a;
        break;
    }
    }

}

int main()
{
   // ������ ������� � ����������� �� � ����������� ������
    ifstream ifs_fin("input.txt");
    ofstream ofs_out("output.txt");

   // ���������� ���� �������
    methodology(ifs_fin, ofs_out);

   // � ��������� �����
    ifs_fin.close();
    ofs_out.close();

}