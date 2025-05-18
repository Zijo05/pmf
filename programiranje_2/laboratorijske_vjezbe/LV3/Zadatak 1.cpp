#include <iostream>

using namespace std;

int main()
{

	char predmeti[50][50];
	char studenti[50][50];

	int br_p(0), br_s(0);

	cout << "Unesite broj predmeta: ";
	cin >> br_p;

	cout << "Unesite broj studenata: ";
	cin >> br_s;

	cin.ignore(10000, '\n');

	for (int i = 0; i < br_p; i++)
	{
		cout << "Unesite predmet: ";
		cin.getline(predmeti[i], 50);
	}

	for (int i = 0; i < br_s; i++)
	{
		cout << "Unesite ime studenta: ";
		cin.getline(studenti[i], 50);
	}

	int ocjene[50][50];
	for (int i = 0; i < br_s; i++)
	{
		cout << "Ocjene za studenta: " << studenti[i] << endl;

		for (int j = 0; j < br_p; j++)
		{
			cout << predmeti[j] << ": ";
			cin >> ocjene[i][j];
		}

		cout << endl
			 << "------------------------" << endl;
	}

	for (int i = 0; i < br_s; i++)
	{
		double suma(0);

		for (int j = 0; j < br_p; j++)
			suma += ocjene[i][j];

		cout << studenti[i] << " - prosjek: " << suma / br_p << endl;
	}

	for (int j = 0; j < br_p; j++)
	{
		double suma(0);

		for (int i = 0; i < br_s; i++)
			suma += ocjene[i][j];

		cout << predmeti[j] << " - prosjek " << suma / br_s << endl;
	}

	return 0;
}
