#include <iostream>
#include <string>
using namespace std;

// Función para cifrar usando el algoritmo de César
string cifrarCesar(const string& mensaje, int k) {
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cifrado = "";

    for (char letra : mensaje) {
        char letraMayus = toupper(letra); 
        size_t pos = alfabeto.find(letraMayus);

        if (pos != string::npos) {
            // Aplicamos desplazamiento modular
            int nuevaPos = (pos + k) % alfabeto.length();
            cifrado += alfabeto[nuevaPos];
        }
        else {
            // Si no es letra, se deja tal cual (espacios, números, etc)
            cifrado += letra;
        }
    }

    return cifrado;

}

// Función para descifrar usando el algoritmo de César
string descifrarCesar(const string& mensajeCifrado, int k) {
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string descifrado = "";

    for (char letra : mensajeCifrado) {
        char letraMayus = toupper(letra);
        size_t pos = alfabeto.find(letraMayus);

        if (pos != string::npos) {
            // Usamos suma con (longitud - k) para retroceder
            int nuevaPos = (pos - k + alfabeto.length()) % alfabeto.length();
            descifrado += alfabeto[nuevaPos];
        }
        else {
            descifrado += letra;
        }
    }

    return descifrado;
}




int main() {
    string mensaje;
    int clave; 

    cout << "Ingrese un mensaje: ";
    getline(cin, mensaje);
    
    //Ingresar clave de desplazamiento para el cifrado.
    cout << "Ingrese la clave (numero de desplazamiento): ";
    cin >> clave;

    string resultado = cifrarCesar(mensaje, clave);
    cout << "Mensaje cifrado: " << resultado << endl;

    return 0;
}

//Probando commit

