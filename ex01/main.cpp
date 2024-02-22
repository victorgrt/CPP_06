#include "Serializer.hpp"

 int main()
{
	//Creation de Data
	Data	*data = new Data;
	data->name = "Correcteur de fou";
	data->age = 18;

	std::cout << YELLOW << "Data at starting point : " << RESET << std::endl;
	std::cout << data->name << std::endl;
	std::cout << data->age << std::endl;
	std::cout << "\n";

	//Serialisation de data dans test
	uintptr_t test = Serializer::serialize(data);

	std::cout << YELLOW << "Comparaison des adresses :" << RESET << std::endl;
	std::cout << &test << std::endl;
	std::cout << &data << "\n" << std::endl;

	std::cout << YELLOW << "Comparaison des \"valeurs\" :" << RESET << std::endl;
	std::cout << test << std::endl;
	std::cout << data << "\n" << std::endl;

	//Affichage des donnees dans test apres deserialisation (uintptr -> data)
	std::cout << YELLOW << "Data from test after deserialize : " << RESET << std::endl;
	std::cout << Serializer::deserialize(test)->name << std::endl;
	std::cout << Serializer::deserialize(test)->age << std::endl;
	std::cout << "\n";

	//Creation de newData qui est test deserialise
	Data	*newData = Serializer::deserialize(test);

	std::cout << YELLOW << "Data in newData : " << RESET << std::endl;
	std::cout << "Name from newData : " << newData->name << std::endl;
	std::cout << "Age from newData : " << newData->age << std::endl; 
	std::cout << "Adresse of newData : " << &newData << std::endl;
	std::cout << "\n";

	//On modifie data et tout a changer
	data->name = "omg j'aime le correcteur";
	data->age = 999;
	std::cout << YELLOW << "Data after modif : " << RESET << std::endl;
	std::cout << "data name de base :" << data->name << std::endl;
	std::cout << "data age de base : " << data->age << std::endl;
	std::cout << "test name : " <<Serializer::deserialize(test)->name << std::endl;
	std::cout << "test age : " << Serializer::deserialize(test)->age << std::endl;
	std::cout << "newData name : " << (newData)->name << std::endl;
	std::cout << "newData age : " << (newData)->age << std::endl;

	delete data;
	return 0;
}
