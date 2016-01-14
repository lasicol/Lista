#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Element
{
	
	//int num;
	

public:
	string text;
	Element *nastepny;
	Element(string tekst)
	{
		text = tekst;
		nastepny = NULL;
	}
};
class Lista 
{
	Element *pierwszy;  // wskaŸnik na pocz¹tek listy
public:
	void dodaj_osobe(string tekst);
	void usun_osobe(int nr);
	void wyswietl_liste();
	string iteracja(int nr);
	Lista();
};

void Lista::dodaj_osobe(string tekst)
{
	Element *nowa = new Element(tekst);
	Element *temp = pierwszy; 

	//temp = pierwszy;

	if (pierwszy == NULL)
		pierwszy = nowa;
	else
	{
		while (temp->nastepny != NULL)
		{
			temp = temp->nastepny;
		}

		temp->nastepny = nowa;
		nowa->nastepny = NULL;
	}

}


void Lista::wyswietl_liste()
{
	// wskaznik na pierszy element listy
	Element *temp = pierwszy;

	// przewijamy wskazniki na nastepne elementy
	while (temp!=NULL)
	{
		cout << "Tekst: " << temp->text << endl;
		temp = temp->nastepny;
	}
}

void Lista::usun_osobe(int nr)
{
	Element *temp = pierwszy;
	Element *temp2;
	int i = 0;

	if (nr == 1)
	{
		pierwszy = temp->nastepny;
	}
	else if (nr>1)
	{
		i = 1;
		while ((temp->nastepny != NULL))
		{	
			if (i + 1 == nr)
				break;
			else
			{
				temp = temp->nastepny;
				i++;
			}
		}
		//if(1/*nr != i + 1*/)
		//{
		//	cout << "Nie ma tylu elementow" << endl;
		//}
		if (temp->nastepny->nastepny == NULL)
		{
			temp->nastepny = NULL;
		}
		else
		{
			temp->nastepny = temp->nastepny->nastepny;
		}
	}

}
string Lista::iteracja(int nr)
{
	Element *temp = pierwszy;
	Element *temp2;
	int i = 0;
	int blok = 0;
	if (nr == 1)
	{
		//cout << pierwszy->text << endl;
		return pierwszy->text;
	}
	else if (nr>1)
	{
		i = 1;
		while ((temp->nastepny != NULL))
		{
			if (i == nr)
			{
				//cout << temp->text << endl;
				return temp->text;
				blok = 1;
				break;
			}
			else
			{
				temp = temp->nastepny;
				i++;
			}
			
		}
		if (blok == 0 && i == nr)
		{
			//cout << temp->text << endl;
			return temp->text;
		}
	}
}


Lista::Lista() {
	pierwszy = NULL;       // konstruktor
}

int main()
{
	Lista * baza = new Lista();
	
	baza->dodaj_osobe("alody1");
	baza->dodaj_osobe("klody2");
	baza->dodaj_osobe("clody3");
	baza->dodaj_osobe("zlody3");
	baza->dodaj_osobe("blody3");
	//cout << baza->iteracja(3) << endl;
	/*baza->usun_osobe(3);
	baza->iteracja(3);
	baza->wyswietl_liste();*/

	
	string lol1;
	string lol2, temp;
	bool sort = false;
	int max_i = 1;



	for (int j = 5; j > 0;j--)
	{
		
		max_i = 1;
		sort = true;

		for (int i = 1; i < j; i++)
		{
			lol1 = baza->iteracja(max_i);
			lol2 = baza->iteracja(i+1);
			if (lol1.compare(lol2) == 1)
			{
				max_i = i + 1;
			}
		
		}

		//cout << max_i << endl;
		
		temp = baza->iteracja(max_i);
		baza->usun_osobe(max_i);
		baza->dodaj_osobe(temp);

		
	}
	baza->wyswietl_liste();

	system("PAUSE");
	return 0;
}