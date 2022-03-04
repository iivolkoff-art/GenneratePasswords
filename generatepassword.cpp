#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;


class PassGen{
private:
    int numOfSmallChars;
    int numOfBigChars;
    int numOfNumbers;
    int numOfSmallCharsRus;
    int numOfBigCharsRus;
    char* password;

public:
    int displayMessage()
    {
        int passLenght;
        int numOfPasswords;
        char* filename = new char[20];
        char txt = 'txt';

        cout << "Введеные даные должны быть 0 < X < 11" << endl;
        cout << "Введите длину пароля для генерации: ";
        cin >> passLenght;
        if (passLenght < 1 || passLenght > 10)
        {
            cout << "Ошибка ввода данных, попробуйте еще раз" << endl;
            return 0;
        }

        cout << "Введите количество паролей для генерации: ";
        cin >> numOfPasswords;
        if (numOfPasswords < 1 || numOfPasswords > 10)
        {
            cout << "Ошибка ввода данных, попробуйте еще раз" << endl;
            return 0;
        }

        cout << "Будет сгенерировано паролей: " << numOfPasswords << "." << endl;
        cout << endl;
        cout << "Введите имя файла для записи(указать расширенние, например .txt): ";
        cin >> filename;

        ofstream outFile(filename);

        auto start = high_resolution_clock::now();

        for (int k = 0; k < numOfPasswords; k++)
        {
            for (int i = 0; i < passLenght; ++i) 
            {

                numOfChars(passLenght);
                passGenerator(passLenght);

                outFile << password[i];
            }
            outFile << endl;
        }

        auto end = high_resolution_clock::now();
        duration<float> duraction = end - start;

        outFile.close();

        cout << "Пароли успешно сгенерированы и записаны в файл " << filename << "" << endl;
        cout << "Время генерации: " << duraction.count() << " секунд" << endl;
    }


    void passGenerator(int passLenght)
    {
        password = new char[passLenght];

        for (int i = 0; i < numOfNumbers; ++i)
        {
            password[i] = char(rand() % 10 + 48);
        }

        for (int i = numOfNumbers; i < numOfNumbers + numOfBigChars; ++i) 
        {
            password[i] = char(rand() % 26 + 65);
        }

        for (int i = numOfNumbers + numOfBigChars; i < numOfNumbers + numOfBigChars + numOfSmallChars; ++i)
        {
            password[i] = char(rand() % 26 + 97);
        }

        for (int i = numOfNumbers + numOfBigChars + numOfSmallChars; i < numOfNumbers + numOfBigChars + numOfSmallChars + numOfBigCharsRus; ++i)
        {
            password[i] = char(rand() % 31 + 192);
        }

        for (int i = numOfNumbers + numOfBigChars + numOfSmallChars + numOfBigCharsRus; i < passLenght; ++i)
        {
            password[i] = char(rand() % 31 + 223);
        }
    }


    void numOfChars(int passLenght)
    {
        numOfSmallChars = rand() % passLenght;
        numOfBigChars = rand() % passLenght - numOfSmallChars;
        numOfSmallCharsRus = rand() % passLenght - numOfSmallChars - numOfBigChars;
        numOfBigCharsRus = rand() % passLenght - numOfSmallChars - numOfBigChars - numOfSmallCharsRus;
        numOfNumbers = passLenght - numOfSmallChars - numOfBigChars - numOfSmallCharsRus - numOfBigCharsRus;
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    PassGen pass;
    pass.displayMessage();
}