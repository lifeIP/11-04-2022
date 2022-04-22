#include <string.h>
#include <iostream>





namespace pets {
	enum life_position { cheerful, sad, kind, angry, whatever };
	enum difficulty_in_training { very_difficult, difficult, normal, easy, very_easy };
	enum species_of_the_animal{ bird, fish, animal, insect };

	class Pet
	{
	public:
		Pet(int number_of_paws, pets::life_position, pets::difficulty_in_training difficulty, pets::species_of_the_animal species) {
			this->number_of_paws = number_of_paws;
			this->life_pos = life_pos;
			this->difficulty = difficulty;
			this->species = species;
		};

		void getData() const {
			std::cout<< number_of_paws <<std::endl;
			std::cout << life_pos << std::endl;
			std::cout << difficulty << std::endl;
			std::cout << species << std::endl;
		}

		bool operator ==(const Pet&) {
			if (this->species == species) return true;
			return false;
		}

		~Pet();

	private:
		int number_of_paws;
		life_position life_pos;
		difficulty_in_training difficulty;
		species_of_the_animal species;
	protected:
		const pets::Pet* find_whatever() {
			if (this->life_pos == whatever) {
				return this;
			}
			return nullptr;
		}
	};
}

namespace ct {
	enum colors { Orange, White, Black, Gray, Other };
	class Cat
	{
	private:
		char* name;
		colors color;
		double weight=0;
		char sex;
		int sizeName;

		void addMas(char* nameCat) {
			sizeName = strlen(nameCat);
			name = new char[sizeName+1];
			name[sizeName] = 0;
			for (int i = 0; i < strlen(nameCat); i++) {
				name[i] = nameCat[i];
			}
		}
	public:
		// normal constructor
		Cat(char* nameCat, ct::colors colorCat, char sex, double weight) {
			addMas(nameCat);
			color = colorCat;
			this->weight = weight;
			this->sex = sex;
		}

		//operator overloading
		Cat & operator ++() {
			weight++;
			return *this;
		}

		Cat& operator --() {
			weight--;
			return *this;
		}

		bool operator > (const Cat& M) {
			if (this->weight > weight) {
				return true;
			}
			return false;
		}
		
		bool operator < (const Cat& M) {
			if (this->weight > weight) {
				return false;
			}
			return true;
		}

		bool operator == (const Cat& M) {
			if (this->weight == weight) {
				return true;
			}
			return false;
		}

		operator int() {
			return this->weight;
		}

		operator double() {
			return this->weight;
		}

		operator char*() {
			return this->name;
		}


		// constructor copy
		Cat(const Cat& other) {
			this->color = other.color;
			this->weight = other.weight;
			this->sizeName = other.sizeName;
			this->sex = other.sex;
			this->name = new char[other.sizeName+1];
			int i = 0;
			for (; i < other.sizeName; i++) {
				this->name[i] = other.name[i];
			}
			this->name[i] = 0;
		}

		void getDATAcat() const{
			std::cout << name << std::endl;
			std::cout << color << std::endl;
			std::cout << sex << std::endl;
			std::cout << weight << std::endl;
		}
		void meows() const{
			std::cout << "meows" << std::endl;
		}
		void getThis() const {
			std::cout << this << std::endl;
		}

		~Cat() {
			std::cout << "Object was destroy!!! " << this << std::endl;
			delete[] name;
		}

	protected:
	};
}

void func(ct::Cat copyValue) {
	std::cout << "" << std::endl;
	std::cout << "Cat4" << std::endl;
	copyValue.getDATAcat();
	copyValue.getThis();
	copyValue.meows();
}



int main() {
	std::cout << "Cats!!!" << std::endl;
	char name1[] = { "Murzik\0" };
	char name2[] = {"Doggy\0"};
	char name3[] = { "Dog\0" };

	ct::Cat cat1(name1, ct::Orange, 'M', 5);
	ct::Cat cat2(name2, ct::Black, 'G', 156.25);
	ct::Cat cat3(name3, ct::White, 'G', 21.565);

/*	
	std::cout << "" << std::endl;
	std::cout << "Cat1" << std::endl;
	cat1.getDATAcat();
	cat1.getThis();
	cat1.meows();

	std::cout << "" << std::endl;
	std::cout << "Cat2" << std::endl;
	cat2.getDATAcat();
	cat2.getThis();
	cat2.meows();

	//cat3.~Cat();
	std::cout << "" << std::endl;
	std::cout << "Cat3" << std::endl;
	cat3.getDATAcat();
	cat3.getThis();
	cat3.meows();

	std::cout << "" << std::endl;
	std::cout << "Cat3" << std::endl;
	++cat3;
	cat3.getDATAcat();
	cat3.getThis();
	cat3.meows();
	func(cat1);
	std::cout << "\n\n\n" << (cat3 < cat2) << std::endl;
	std::cout << (cat3 > cat2) << std::endl;
	std::cout << (cat3 == cat2) << std::endl;
	std::cout << int(cat1) << std::endl;
*/
}

