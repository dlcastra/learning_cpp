#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

//Funkcja do wprowadzania parametrów funkcji kwadratowej
void input_parameters(double &a, double &b, double &c) {
    cout << "Enter the coefficient of x^2: ";
    cin >> a;
    cout << "Enter the coefficient of x: ";
    cin >> b;
    cout << "Enter the constant term: ";
    cin >> c;
}

//Funkcja pozwalająca sprawdzić, czy funkcja jest kwadratowa
double check_QE(double a){
    if (a == 0){
        cout << "Not a quadratic function" << endl;
        return 1;
    }
    else {
        cout << "Quadratic function" << endl;
    }
}

//Funkcja sprawdzająca kierunek paraboli
double parabola(double a){
    if (a > 0){
        cout << "The arrows of the parabola point upwards" << endl;
    }
    else if (a < 0) {
        cout << "The arrows of the parabola point downward" << endl;
    }
    else{return 1;}
}

//Funkcja sprawdza czy funkcja jest kwadratowa i ile ma korzeni
double root_and_roots(double a, double b, double c, double &x1, double &x2){
    double discriminant = b*b - 4*a*c;

    if (a == 0){return 1;}
    if (discriminant > 0){
        // Równanie ma dwa różne pierwiastki
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Discriminant has two roots:" << endl;
        cout << "First root is: " << x1 << endl;
        cout << "Second root is: " << x2 << endl;
        return 0;
    }
    else if (discriminant == 0){
        // Równanie ma jeden podwójny pierwiastek
        x1 = -b / (2 * a);
        cout << "Discriminant has one root:" << endl;
        cout << "The root of the discriminant is: " << x1 << endl;
        return 0;
    }
    else{
        // Równanie nie ma rozwiązań w zbiorze liczb rzeczywistych
        cout << "Discriminant cannot be below zero" << endl;
        return 1;
    }
}


char str_compound(char str1[100], char str2[100]){
    cout << strcat(str1,str2);
}


int main(){
    double a, b, c, x1, x2;
    char first_line[100], second_line[100];
    input_parameters(a,b,c);
    check_QE(a);
    parabola(a);
    root_and_roots(a, b, c,x1,x2);

    cout << "Enter first line: ";
    cin >> first_line;
    cout << "Enter second line: ";
    cin >> second_line;

    //Przykład zastosowania wskaźnika do funkcji.
    //Funkcję, operującą na ciągach znaków, połącz ciągi znaków w jeden ciąg.
    char (*function_str_compound)(char first_str[100], char second_str[100]) = &str_compound;
    char compound = (function_str_compound)(first_line, second_line);
    cout << compound;
}