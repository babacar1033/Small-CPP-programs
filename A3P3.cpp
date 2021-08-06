#include <iostream>
#include <cmath>
using namespace std;

class IntSet
{
public:
	IntSet();
    const IntSet operator +(const IntSet& set2);
    const IntSet operator *(const IntSet& set2);
    const IntSet operator -(const IntSet& set2);
    void operator += (int n1);
    void operator -= (int n1);
    bool operator ==(const IntSet& set2);
    const IntSet operator !();
    bool operator <=(const IntSet& set2);
    friend ostream& operator <<(ostream& outputStream, const IntSet& set1);

private:
	bool arSet[100];
};

void arrSelect (char& arrOpt);
int arrInt (char arrOpt);

int main(){

    int option, n;
    IntSet sets[10];
    char a1, a2, a3, cont;

    do {
        cout << "Select an option: \n"
         << "1 - add numbers to a set\n"
         << "2 - remove numbers from a set\n"
         << "3 - form the union of two sets\n"
         << "4 - form the intersection of two sets\n"
         << "5 - form the difference of two sets\n"
         << "6 - determine if two sets are equal\n"
         << "7 - form the complement of a set\n"
         << "8 - determine if one set is a subset of another set\n"
         << "9 - display a set\n"
         << "10 - Exit\n";
         cin >> option;

        switch(option) {
            case 1:
                cout << "Add numbers to which sets ";
                arrSelect(a1);

                do {
                    cout << "Enter number to add: ";
                    cin >> n;
                    sets[arrInt(a1)] += n;

                    cout << "Add another (y or n): ";
                    cin >> cont;
                }while (cont == 'y' || cont == 'Y');
                break;
            case 2:
                cout << "Remove numbers from which sets ";
                arrSelect(a1);

                do {
                    cout << "Enter number to remove: ";
                    cin >> n;
                    sets[arrInt(a1)] -= n;

                    cout << "Remove another (y or n): ";
                    cin >> cont;
                }while (cont == 'y' || cont == 'Y');
                break;
            case 3:
                cout << "Set union - specify sets to use:\nFirst set: ";
                arrSelect(a1);
                cout << "Second set: ";
                arrSelect(a2);
                cout << "Result set: ";
                arrSelect(a3);
                sets[arrInt(a3)] = sets[arrInt(a1)] + sets[arrInt(a2)];
                break;
            case 4:
                cout << "Set intersection - specify sets to use:\nFirst set: ";
                arrSelect(a1);
                cout << "Second set: ";
                arrSelect(a2);
                cout << "Result set: ";
                arrSelect(a3);
                sets[arrInt(a3)] = sets[arrInt(a1)] * sets[arrInt(a2)];
                break;
            case 5:
                cout << "Set difference - specify sets to use:\nFirst set: ";
                arrSelect(a1);
                cout << "Second set: ";
                arrSelect(a2);
                cout << "Result set: ";
                arrSelect(a3);
                sets[arrInt(a3)] = sets[arrInt(a1)] - sets[arrInt(a2)];
                break;
            case 6:
                cout << "Set equality - specify sets to use:\nFirst set: ";
                arrSelect(a1);
                cout << "Second set: ";
                arrSelect(a2);
                if (sets[arrInt(a1)] == sets[arrInt(a2)]){
                    cout << "These sets are equal\n";
                }
                else {
                    cout << "These sets are not equal\n";
                }
                break;
            case 7:
                cout << "Set complement - specify sets to use:\nComplement set: ";
                arrSelect(a1);
                cout << "Result set: ";
                arrSelect(a2);
                sets[arrInt(a2)] = !sets[arrInt(a1)];
                break;
            case 8:
                cout << "Subsets - specify sets to compare:\nFirst set: ";
                arrSelect(a1);
                cout << "Second set: ";
                arrSelect(a2);
                if (sets[arrInt(a1)] <= sets[arrInt(a2)]){
                    cout << "\nThe first set is a subset of the second.";
                }
                else {
                    cout << "\nThe first set is not a subset of the second.";
                }
                break;
            case 9:
                cout << "Display set ";
       			arrSelect(a1);
       			cout << sets[arrInt(a1)];
                break;
            case 10:
                cout << "Bye" << endl;
                exit(1);
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    cout << endl;
    } while(option != 10);

    return 0;
}

IntSet::IntSet() {
    for (int i = 0; i < 100; i++){
        arSet[i] = 0;
    }
}

void arrSelect (char& arrOpt){
    cout << "(A, B, C, D, E, F, G, H, I, J)? : ";
    cin >> arrOpt;
}

void IntSet::operator +=(int n1){
    if (n1 < 0 || n1 > 99) {
		cout << "Invalid number!\n";
    }
	else {
		if (arSet[n1] == 1)
			cout << n1 << " is already in the set.\n";
		else
			arSet[n1] = 1;
    }
}

void IntSet::operator -= (int n1){
    if(n1 < 0 || n1 > 99){
        cout << "Invalid number!\n";
    }
    else {
        if (arSet[n1] == 0)
            cout << n1 << " is not in the set.\n";
        else
            arSet[n1] = 0;
    }
}

const IntSet IntSet::operator +(const IntSet& set2){
    IntSet set3;
	for (int i = 0; i < 100; i++)
	{
		if (arSet[i] || set2.arSet[i])
			set3.arSet[i] = 1;
	}
	return set3;
}

const IntSet IntSet::operator -(const IntSet& set2){
    IntSet set3;
	for (int i = 0; i < 100; i++)
	{
		if (arSet[i] || !set2.arSet[i])
			set3.arSet[i] = 1;
	}
	return set3;
}

const IntSet IntSet::operator *(const IntSet& set2){
    IntSet set3;
	for (int i = 0; i < 100; i++)
	{
		if (arSet[i] && set2.arSet[i])
			set3.arSet[i] = 1;
	}
	return set3;
}

const IntSet IntSet::operator !(){
    IntSet set3;
    for (int i = 0; i < 100; i++)
	{
		if (!arSet[i])
			set3.arSet[i] = 1;
	}
	return set3;
}

bool IntSet::operator ==(const IntSet& set2){
    bool tf = 1;
    for (int i = 0; i < 100; i++){
        if (arSet[i] != set2.arSet[i])
            tf = 0;
    }
    return tf;
}

bool IntSet::operator <=(const IntSet& set2){
    bool tf = 1;
    for (int i = 0; i < 100; i++){
        if (arSet[i] && !set2.arSet[i])
            tf = 0;
    }
    return tf;
}

ostream& operator <<(ostream& outputStream, const IntSet& set1){
    int i, n=0;

    for (i = 0; i < 100; i++){
        if (set1.arSet[i]) {
            n += 1;
        }
    }
	outputStream << "{";
	for (i = 0; i < 100; i++){
        if (set1.arSet[i]){
            outputStream << i;
                if (n > 1) {
                    outputStream << ", ";
                    n--;
                }
        }

	}
	outputStream << "}\n";

	return outputStream;
}

int arrInt (char arrOpt){
    switch (arrOpt){
        case 'A':
            return 0;
            break;
        case 'B':
            return 1;
            break;
        case 'C':
            return 2;
            break;
        case 'D':
            return 3;
            break;
        case 'E':
            return 4;
            break;
        case 'F':
            return 5;
            break;
        case 'G':
            return 6;
            break;
        case 'H':
            return 7;
            break;
        case 'I':
            return 8;
            break;
        case 'J':
            return 9;
            break;
        default:
            cout << "Invalid array." << endl;
            break;

    }
}
