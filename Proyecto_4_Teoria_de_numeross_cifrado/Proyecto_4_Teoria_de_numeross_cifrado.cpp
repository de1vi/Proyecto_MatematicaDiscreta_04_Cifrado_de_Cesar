#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:',.<>?/ ";

// Función para calcular el MCD (Máximo Común Divisor)
int mcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// Función para calcular el inverso modular de a respecto a m
int inversoModular(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return 1; 
}


string cifrarCesar(const string& mensaje, int a, int b, int mod) {
    string cifrado = "";
    cout << "\n=========  PROCESO DE CIFRADO  =========\n";

    for (char letra : mensaje) {
        size_t pos = alfabeto.find(letra);
        if (pos != string::npos) {
            int nuevaPos = (a * pos + b) % mod;
            cifrado += alfabeto[nuevaPos];
            cout << "Caracter: '" << letra << "' (x=" << pos << ") => y=("
                << a << "*" << pos << " + " << b << ") mod " << mod
                << " = " << nuevaPos << " => '" << alfabeto[nuevaPos] << "'\n";
        }
        else {
            cifrado += letra;
        }
    }
    cout << "============================================\n";
    cout << "Mensaje cifrado final: " << cifrado << endl;
    return cifrado;
}


string descifrarCesar(const string& mensajeCifrado, int a, int b, int mod) {
    string descifrado = "";
    int a_inv = inversoModular(a, mod);

    cout << "\n=========  PROCESO DE DESCIFRADO  =========\n";
    cout << "Inverso modular de a (" << a << ") mod " << mod << " = " << a_inv << "\n";

    for (char letra : mensajeCifrado) {
        size_t pos = alfabeto.find(letra);
        if (pos != string::npos) {
            int nuevaPos = (a_inv * (pos - b + mod)) % mod;
            descifrado += alfabeto[nuevaPos];
            cout << "Caracter: '" << letra << "' (y=" << pos << ") => x=("
                << a_inv << "*(" << pos << "-" << b << ")) mod " << mod
                << " = " << nuevaPos << " => '" << alfabeto[nuevaPos] << "'\n";
        }
        else {
            descifrado += letra;
        }
    }
    cout << "==============================================\n";
    cout << "Mensaje descifrado final: " << descifrado << endl;
    return descifrado;
}


void mostrarMenu() {
    system("cls");
    cout << "\n";
    cout << "=====================================================\n";
    cout << "           🔢  CIFRADO DE CESAR EXTENDIDO  🔢\n";
    cout << "=====================================================\n";
    cout << "   [1]  Cifrar mensaje\n";
    cout << "   [2]  Descifrar ultimo mensaje\n";
    cout << "   [3]  Salir\n";
    cout << "=====================================================\n";
    cout << "   Elige una opcion: ";
}

int main() {
    string mensaje, cifrado, descifrado;
    int a, b;
    int opcion = 0;
    int mod = alfabeto.length();

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1:
            cout << "\nIngrese un mensaje: ";
            getline(cin, mensaje);

            // Validar valor de 'a'
            do {
                cout << "Ingrese el valor de a (numero primo o coprimo con " << mod << "): ";
                cin >> a;

                if (mcd(a, mod) != 1) {
                    cout << "\n❌ Error: El valor de 'a' no es coprimo con " << mod << ".\n";
                    cout << "   Intente con otro valor que NO sea multiplo de 7 ni de 13.\n\n";
                }

            } while (mcd(a, mod) != 1);

            cout << "Ingrese el valor de b (desplazamiento): ";
            cin >> b;
            cin.ignore();

            cifrado = cifrarCesar(mensaje, a, b, mod);
            break;

        case 2:
            if (cifrado.empty()) {
                cout << "\n⚠️  No hay mensaje cifrado aun.\n";
            }
            else {
                descifrado = descifrarCesar(cifrado, a, b, mod);
            }
            break;

        case 3:
            cout << "\n👋 Gracias por usar el cifrador extendido. Hasta pronto!\n";
            return 0;

        default:
            cout << "\n❌ Opcion invalida.\n";
        }

        cout << "\nPresione ENTER para continuar...";
        cin.ignore();
    } while (opcion != 3);

    return 0;
}
