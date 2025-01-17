#include <iostream>
#include <bitset>
#include <vector>

#include "MyString.cpp"
#include "AbstractClass.cpp"

#define TabSize 10

//Zadania które wykona³em s¹ czêœci¹ Samsung R&D Tech Guide C++ link poni¿ej: 
//https://samsungrd.pl/files/resources/Samsung_C_Tech_Guide.pdf

//1.
//Napisz nastêpuj¹cy program :
//
//     W funkcji main zadeklaruj
//     10 - elementow¹ tablicê liczb ca³kowitych.
//     Napisz funkcjê, do której przeka¿esz tê tablicê
//     i do ka¿dego jej elementu dodasz 1.
//     Wypisz tablicê przed i po wywo³aniu funkcji

//2.
//Zadeklaruj 64 - bitow¹ zmienn¹
//ca³kowitoliczbow¹ i zdefiniuj jej dowoln¹ wartoœæ :
//	 Wypisz na ekran wszystkie bity tej liczby.
//	 Zmieñ 41. bit na przeciwny.

//3.
//Napisz w³asn¹ klasê string :
//	Nie u¿ywaj elementów z biblioteki standardowej.
//	Klasa powinna mieæ mo¿liwoœæ utworzenia obiektu na
//	podstawie przekazanej sta³ej znakowej.
//	Klasa powinna mieæ metodê zwracaj¹c¹ d³ugoœæ napisu.
//	Klasa powinna mieæ operator indeksowy zwracaj¹cy /
//	zmieniaj¹cy podan¹ literê.
//	Klasa powinna mieæ metodê / operator pozwalaj¹cy na
//	dodanie kolejnych znaków do napisu.
//	Powinny zostaæ zdefiniowane operatory strumieniowe,
//	które pozwol¹ wypisywaæ obiekty na ekran / do pliku

//4.
//Zadeklaruj klasê abstrakcyjn¹ :
//	Napisz dwie klasy pochodne, które bêd¹ przeci¹¿aæ
//	metodê wirtualn¹.
//	Zaprezentuj polimorficzne wywo³ywanie tej metody.


void add_one_to_table(int []);
int main()
{
    std::cout << "Zad 1\n";
	std::cout << "Before add:";
	int table[TabSize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int t : table) {
		std::cout << t << " ";
	}
	std::cout << std::endl;

	add_one_to_table(table);

	std::cout << "After add:";

	for (int t : table) {
		std::cout << t << " ";
	}
	std::cout << std::endl;

	std::cout << "Funkcja przyjmuje referencje do pierwszej wartosci tablicy, z tego powodu niemozliwe jest okreslenie jej wielosci w ramach funkcji. W moim rozwiazaniu wykorzystalem #define do globalnego ustalenia wielkosci tablicy, jednak dla roznych wielosci tablic lepszym rozwiazaniem byloby dodanie parametru okreslajacego wielkosc tablicy przy wywolywaniu funkcji.";
	std::cout << std::endl;

	std::cout << "Zad 2"<< std::endl;

	std::bitset<64> bit(2432412457567351235);

	std::cout << "before flip:" << std::endl;
	std::cout << bit;

	std::cout << std::endl;
	bit.flip(41);

	std::cout << "after flip:" << std::endl;
	std::cout << bit << std::endl;


	std::cout << "Zad 3" << std::endl;
	MyString mystring("Hello World");

	std::cout << mystring << std::endl;

	mystring += "!";

	for (int i = 0; i < mystring.get_len(); i++){
		std::cout << mystring[i];
	}
	std::cout << std::endl;

	std::cout << "Zad 4"<< std::endl;
	std::vector<Ex4::MyAbstractClass*> ListOfAbstractClasses;

	Ex4::OneClass oneclass[] = {
		Ex4::OneClass(),
		Ex4::OneClass(),
		Ex4::OneClass(),
	};
	Ex4::TwoClass twoclass[] = {
		Ex4::TwoClass(),
		Ex4::TwoClass(),
		Ex4::TwoClass(),
	};

	for (int i = 0; i < 3; i++) {
		ListOfAbstractClasses.push_back(&oneclass[i]);
		ListOfAbstractClasses.push_back(&twoclass[i]);
	}

	for (auto element : ListOfAbstractClasses) {
		element->ExecuteSomething();
		element->Simpler();
	}
}

void add_one_to_table(int tab[]) {

	for (int i = 0; i < TabSize; i++) {
		tab[i]++;
	}
}