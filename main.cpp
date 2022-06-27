#include <iostream>
#include <valarray>

using namespace std;

struct Pet {
    char Case;
    union {
        struct {char NicknameCat[10]; double Weight;} Cat;
        struct {char NicknameDog[10], Size[5];} Dog;
    };
    int Age;
};

Pet InPetInfo(char cs) {
    Pet pets;
    if (pets.Case = cs) {
        cout << "Nickname of cat: ";
        cin >> pets.Cat.NicknameCat;
        cout << "Age (months): ";
        cin >> pets.Age;
        cout << "Weight (kg) :";
        cin >> pets.Cat.Weight;
    } else {
        cout << "Nickname of dog: ";
        cin >> pets.Dog.NicknameDog;
        cout << "Age (months): ";
        cin >> pets.Age;
        cout << "Size (small, large): ";
        cin >> pets.Dog.Size;
    }
    return pets;
}

void OutPetInfo(Pet pets) {
    if (pets.Case) {
        cout << "Cat: " << pets.Cat.NicknameCat << " |" << pets.Age << " months | " << pets.Cat.Weight << " kg" << endl;
    } else {
        cout << "Dog: " << pets.Dog.NicknameDog << " |" << pets.Age << " months |" << pets.Dog.Size << endl;
    }
}

void DeleteInformation(Pet pets[], int number) {
    Pet pet {};
    pets[number - 1] = pet;
}

int main() {
    Pet DataBase[10],
    pet = { 0, {0, 0}, 0};
    int i, j;
    for (i = 0; i < sizeof(DataBase) / sizeof(Pet); i++)
        DataBase[i] = pet;
    while (1) {
        cout << "    Menu:" << endl
             << "1. Data entry." << endl
             << "2. Output of information about the pet." << endl
             << "3. Output of all information." << endl
             << "4. Deleting pet information." << endl
             << "5. Finish the work." << endl
             << ">";
        cin >> i;
        switch (i) {
            case 1:
                cout << "Pet Number: ";
                cin >> i;
                cout << "Variant (0 - dog, 1 - cat): ";
                cin >> j;
                DataBase[i] = InPetInfo(j);
                break;
            case 2:
                cout << "Pet Number: ";
                cin >> i;
                OutPetInfo(DataBase[i]);
                break;
            case 3:
                for (i = 0; i < sizeof(DataBase) / sizeof(Pet); i++)
                    if (DataBase[i].Age) {
                        cout << "Pet Number:" << i << endl;
                        OutPetInfo(DataBase[i]);
                    }
                break;
            case 4:
                cout << "Pet Number: ";
                cin >> i;
                DeleteInformation(&DataBase[i], i);
                break;
            case 5:
                return 0;
            default:
                cout << "Repeat the input, please." << endl;

        }
    }
}