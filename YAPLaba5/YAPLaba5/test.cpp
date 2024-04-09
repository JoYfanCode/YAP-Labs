#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class ColorRGB
{
private:
    double red;
    double green;
    double blue;

public:

    ColorRGB()     //����������� �� ���������
    {
        red = 0;
        green = 0;
        blue = 0;
    }

    ColorRGB(int red, int green, int blue)      // ����������� ������������� 
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    ColorRGB(const ColorRGB& other)       // ����������� �����������
    {
        red = other.red;
        green = other.green;
        blue = other.blue;
    }

    ~ColorRGB()     // ���������� 
    {

    }

    friend ifstream& operator>>(ifstream& in, ColorRGB& color) // ���������� ��������� �����
    {
        in >> color.red >> color.green >> color.blue;
        return in;
    }

    friend ofstream& operator<<(ofstream& out, const ColorRGB& color)  // ���������� ��������� ������
    {
        out << color.red << ' ' << color.green << ' ' << color.blue << endl;
        return out;
    }

    bool operator==(const ColorRGB& color)
    {
        return (red == color.red && green == color.green && blue == color.blue);
    }

    void operator=(const ColorRGB& color)
    {
        red = color.red;
        green = color.green;
        blue = color.blue;
    }

    ColorRGB operator+(const ColorRGB& other) const         // �������� ������
    {
        return ColorRGB(red + other.red, green + other.green, blue + other.blue);
    }

    ColorRGB operator-(const ColorRGB& other) const     // ��������� ������
    {
        return ColorRGB(red - other.red, green - other.green, blue - other.blue);
    }

    void intoSRGB()     // ������� � ������ �������� ������������ (SRGB)
    {
        double RED = red / 255.0;
        double GREEN = green / 255.0;
        double BLUE = blue / 255.0;

        if (RED > 0.04045)
            RED = pow((RED + 0.055) / 1.055, 2.4);
        else
            RED = RED / 12.92;

        if (GREEN > 0.04045)
            GREEN = pow((GREEN + 0.055) / 1.055, 2.4);
        else
            GREEN = GREEN / 12.92;

        if (BLUE > 0.04045)
            BLUE = pow((BLUE + 0.055) / 1.055, 2.4);
        else
            BLUE = BLUE / 12.92;

        red = static_cast<int>((RED * 255.0) + 0.5);
        green = static_cast<int>((GREEN * 255.0) + 0.5);
        blue = static_cast<int>((BLUE * 255.0) + 0.5);
    }

};

/*
int main()
{
    int key;
    ifstream f_input("input.txt");
    ofstream f_output("output.txt");

    f_input >> key;

    switch (key)
    {
    case 1:          // ����������� �� ���������
    {
        ColorRGB color;
        f_output << color;
        break;
    }
    case 2:          // ����������� �������������
    {
        int red, green, blue;
        f_input >> red >> green >> blue;
        ColorRGB color(red, green, blue);
        f_output << color;
        break;
    }
    case 3:         // ����������� �����������
    {
        ColorRGB color;
        f_input >> color;
        ColorRGB color2(color);
        f_output << color2;
        break;
    }

    case 4:      // �������� ==
    {
        ColorRGB color, color2;
        f_input >> color >> color2;
        if (color == color2)
            f_output << "Equal";
        else
            f_output << "Not equal";
        break;
    }
    case 5:         // �������� ������������ =
    {
        ColorRGB color, color2;
        f_input >> color;
        color2 = color;
        f_output << color2;
        break;
    }
    case 6:         // �������� ������
    {
        ColorRGB color, color2;
        f_input >> color >> color2;
        f_output << color + color2;
        break;
    }
    case 7:      // ��������� ������
    {
        ColorRGB color, color2;
        f_input >> color >> color2;
        f_output << color - color2;
        break;
    }
    case 8:      // ������� � ������ �������� ������������ (SRGB)
    {
        ColorRGB color;
        f_input >> color;
        color.intoSRGB();
        f_output << color;
        break;
    }
    }
    f_input.close();
    f_output.close();

    return 0;
}
*/