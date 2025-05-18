
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dodajPredmet(string predmet, string student, const vector<string> &studenti, vector<vector<string>> &predmeti)
{

	for (int i = 0; i < studenti.size(); i++)
	{

		if (studenti[i] == student)
		{
			predmeti[i].push_back(predmet);
			cout << "Dodajemo predmet!" << endl;
		}
	}
}

int brojStudenataNaPredmetu(string predmet, const vector<vector<string>> &p)
{

	int brojac = 0;

	for (int i = 0; i < p.size(); i++)
	{

		for (int j = 0; j < p[i].size(); j++)
		{

			if (p[i][j] == predmet)
				brojac++;
		}
	}

	return brojac;
}

void studentiNaPredmetu(string predmet, const vector<string> &studenti, const vector<vector<string>> &predmeti)
{

	for (int i = 0; i < predmeti.size(); i++)
	{

		for (int j = 0; j < predmeti[i].size(); j++)
		{

			if (predmeti[i][j] == predmet)
				cout << studenti[i] << endl;
		}
	}
}

int main()
{

	vector<string> studenti;
	vector<vector<string>> predmeti;

	while (true)
	{
		string s;

		cout << "Unesite ime studenta: "; // Unijeti: S1, S2, kraj
		getline(cin, s);

		if (s == "kraj")
			break;

		studenti.push_back(s);
	}

	for (int i = 0; i < studenti.size(); i++)
	{
		vector<string> p;

		cout << endl
			 << "------------------------------" << endl;
		cout << "Unesite predmete za studenta: " << studenti[i] << endl;

		while (true)
		{
			string x;

			cout << "Unesite predmet: ";
			getline(cin, x);

			if (x == "kraj")
			{
				break;
			}

			p.push_back(x);
		}

		predmeti.push_back(p);
	}

	cout << endl
		 << "------------------------------" << endl;

	cout << endl
		 << "Prije dodavanja predmeta P2 studentu S1." << endl
		 << endl;
	cout << "Studenti na predmetu P2: " << endl;
	studentiNaPredmetu("P2", studenti, predmeti);
	cout << endl;
	cout << "Broj studenata na predmetu P2: " << endl
		 << brojStudenataNaPredmetu("P2", predmeti) << endl
		 << endl;

	cout << "------------------------------" << endl
		 << endl;

	dodajPredmet("P2", "S1", studenti, predmeti);
	cout << endl
		 << "------------------------------" << endl;

	cout << endl
		 << "Nakon dodavanja predmeta P2 studentu S1." << endl
		 << endl;
	cout << "Studenti na predmetu P2: " << endl;
	studentiNaPredmetu("P2", studenti, predmeti);
	cout << endl;
	cout << "Broj studenata na predmetu P2: " << endl
		 << brojStudenataNaPredmetu("P2", predmeti) << endl;

	return 0;
}
