/*
 * 1. Продемонстрировать различные уровни инкапсуляции данных (указать комментарием):
 *  a. Отсутствие инкапсуляции (public свойства)
 *  b. Инкапсуляция с помощью set/get
 *  c. Инкапсуляция с помощью специализированных протоколов/методов
 *  d. Инкапсуляция за счёт абстракций
 *
 * p.s. использовать механизмы исключений, если нарушается инвариант или не соблюдаются пост/пред-условия
 *
 * 2. Продемонстрировать различные варианты инкапсуляции поведения
 *  a. За счёт позднего связывания
 *  b. Замена поведения (тут тоже используется позднее связывание)
 *  c. Расширения поведения (тут тоже используется позднее связывание)
 
 
 */
#include <iostream>


class Univer{
private:
	unsigned short rau, commissions;
	std::string name;

public:
	bool Para; //Отсутствие инкапсуляции (public свойства)
	Univer(bool para){
		Para = para;
	}
	
	void setRau(unsigned short rrau){ //Инкапсуляция с помощью set/get
		rau = rrau;
	}
	
	std::string getStudentName() const{
		return name;
	};
	
	virtual void HeGetCom(unsigned short com){ //За счёт позднего связывания
		commissions = com;
		std::cout << commissions << std::endl;
	}
	
	void Commissions(){ //расширение поведения
		std::cout << getStudentName() << " gave away commissions: ";
		HeGetCom(commissions);
	}

	virtual void StudentInfo(){
		std::cout << getStudentName();
	}
	
};

class Student: public Univer{ //Инкапсуляция за счёт абстракций
private:
	unsigned short Age, Weight, Height, Rau, Commissions;
public:
	Student(unsigned short age, unsigned short weight, unsigned short height,
	            unsigned short rauu, unsigned short com) : Univer(Para){
		Age = age;
		Weight = weight;
		Height = height;
		Rau = rauu;
		Commissions = com;
	}
	
	unsigned short getAge() const {
		return Age;
	}
	
	unsigned short getWeight() const {
		return Weight;
	}
	
	unsigned short getHeight() const {
		return Height;
	}
	
	void PlusRau(){ // Инкапсуляция с помощью специализированных протоколов/методов
		Rau++;
	}
	
	void PlusCom(){
		Commissions++;
	}
	
	void StudentInfo() override{ //Замена поведения
		std::cout << "Возраст:" << getAge() << " " << "Вес:" << getWeight() << " " << "Рост:" << getHeight() << " " <<
		          "РАУ:" << Rau << " " << "Комиссии:" << Commissions << std::endl;
	}
};

//Функция для абстракции
void getInfo(Univer &Player_name) {
	Player_name.StudentInfo();
}

int main(){
	Student Nikita(10, 1, 180, 0, 2);
	Student Igor(11, 70, 180, 4, 0);
	getInfo(Nikita);
	getInfo(Igor);
	
	
	Igor.PlusRau();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	Nikita.PlusCom();
	
	Nikita.PlusRau();
	Igor.PlusCom();
	Igor.PlusCom();
	
	Nikita.StudentInfo();
	
	Igor.StudentInfo();
	
	return 0;
}