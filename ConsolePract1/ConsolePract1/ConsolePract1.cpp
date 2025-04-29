#include <iostream>
#include "Figures.h"
#include "Animals.h"
#include "Employees.h"
#include "Auto.h"
#include "Accounts.h"
#include "Media.h"
#include "Persons.h"
#include "Books.h"
#include "Applience.h"
#include "Games.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    int que;

    cout << "Введите номер задания (от 1 до 10): ";
    cin >> que;

    switch (que)
    {
    case 1: shapeDemo(); break;
    case 2: animalDemo(); break;
    case 3: employeeDemo(); break;
    case 4: vehicleDemo(); break;
    case 5: accountDemo(); break;
    case 6: mediaDemo(); break;
    case 7: personDemo(); break;
    case 8: bookDemo(); break;
    case 9: applianceDemo(); break;
    case 10: gameDemo(); break;
    default:
        break;
    }
}