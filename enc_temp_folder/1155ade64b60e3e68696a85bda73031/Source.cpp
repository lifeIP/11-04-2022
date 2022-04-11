#include <string.h>
#include <iostream>

namespace ct {
	enum colors { Orange, White, Black, Gray, Other };
	class Cat
	{
	private:
		char* name;
		colors color;
		double weight=0;
		char sex;

		void addMas(char* nameCat) {
			int sizeName = strlen(nameCat);
			name = new char[sizeName+1];
			name[sizeName] = 0;
			for (int i = 0; i < strlen(nameCat); i++) {
				name[i] = nameCat[i];
			}
		}
	public:
		Cat(char* nameCat, ct::colors colorCat, char sex, double weight) {
			addMas(nameCat);
			color = colorCat;
			this->weight = weight;
			this->sex = sex;
		}
		void getDATAcat() {
			std::cout << name << std::endl;
			std::cout << color << std::endl;
			std::cout << sex << std::endl;
			std::cout << weight << std::endl;
		}
		void getThis() {
			std::cout << this << std::endl;
		}

		~Cat() {
			delete[] name;
		}

	protected:
	};
}

int main() {
	std::cout << "Cats!!!" << std::endl;
	char name1[] = "Murzik\0";
	char name2[] = "Doggy\0";
	char name3[] = "Dog\0";

	ct::Cat cat1(name1, ct::Orange, 'M', 5);
	ct::Cat cat2(name2, ct::Black, 'G', 156.25);
	ct::Cat cat3(name3, ct::White, 'G', 21.565);
	
	std::cout << "" << std::endl;
	std::cout << "Cat1" << std::endl;
	cat1.getDATAcat();
	cat1.getThis();

	std::cout << "" << std::endl;
	std::cout << "Cat2" << std::endl;
	cat2.getDATAcat();
	cat2.getThis();

	cat3.~Cat();
	std::cout << "" << std::endl;
	std::cout << "Cat3" << std::endl;
	cat3.getDATAcat();
	cat3.getThis();
}