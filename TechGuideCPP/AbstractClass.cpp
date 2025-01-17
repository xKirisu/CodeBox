#include<iostream>
//4.
//Zadeklaruj klasê abstrakcyjn¹ :
//	Napisz dwie klasy pochodne, które bêd¹ przeci¹¿aæ
//	metodê wirtualn¹.
//	Zaprezentuj polimorficzne wywo³ywanie tej metody.
namespace Ex4 {
	class MyAbstractClass {
	public:
		virtual void ExecuteSomething() {
			std::cout << "Default ";
		}
		virtual void Simpler() = 0;
	};
	class OneClass : public MyAbstractClass {
	public:
		OneClass() {

		}
		void ExecuteSomething() override
		{
			MyAbstractClass::ExecuteSomething();
			std::cout << "Klasa 1" << std::endl;
		}
		void Simpler() {
			std::cout << "Hello World!" << std::endl;
		}
	};
	class TwoClass : public MyAbstractClass {
	public:
		TwoClass() {

		}
		void ExecuteSomething() override
		{
			MyAbstractClass::ExecuteSomething();
			std::cout << "Klasa 2" << std::endl;
		}
		void Simpler() {
			std::cout << "Good Morning World!" << std::endl;
		}
	};

}
