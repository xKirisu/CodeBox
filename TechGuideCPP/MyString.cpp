#include <ostream>

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

class MyString {
protected:
	char* stringtable;
	int length;

public:
	MyString(const char *chars) {
		if (chars == nullptr) {
			stringtable = nullptr;
			length = 0;
		}
		else {
			length = calc_length(chars);
			stringtable = new char[length + 1];

			for (int i = 0; i < length; i++) {
				stringtable[i] = chars[i];
			}

			stringtable[length] = '\0';
		}
	}

	~MyString() {
		if (stringtable != nullptr) {
			delete[] stringtable;
		}
	}

	int get_len() const {
		return length;
	}
	int calc_length(const char* new_c) {
		int x = 0;
		while (new_c[x] != '\0') {
			x++;
		}
		return x;
	}
	bool add_next(const char* new_c) {
		int old_length = length;
		int new_length = calc_length(new_c) + length;

		char* newtable = new char[new_length + 1];

		for (int i = 0; i < old_length; i++) {
			newtable[i] = stringtable[i];
		}

		for (int i = 0; i < calc_length(new_c); i++) {
			newtable[old_length + i] = new_c[i];
		}

		newtable[new_length] = '\0';
		length = new_length;

		delete[] stringtable;
		stringtable = newtable;

		return true;
	}


	const char* get_stringtable() const {
		return stringtable;
	}

	void operator +=(const char* new_c) {
		add_next(new_c);
	}

	char& operator[](int n) {
		if (n < 0 || n >= length) {
			throw std::out_of_range("Index out of range");
		}

		return stringtable[n];
	}

	friend std::ostream& operator<<(std::ostream& os, const MyString& mystring);
};

std::ostream& operator<<(std::ostream& os, const MyString& mystring) {
	os << mystring.get_stringtable();
	return os;
}