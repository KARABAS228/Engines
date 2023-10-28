#include<iostream>
#include<math.h>
#include<cstring>
#include<string.h>
#include<windows.h>
#include<vector>
#include<random>
#include<cmath>


class Transport {
public:
	Transport() {};


	void SetName(std::string NewName) {
		name = NewName;
	}
	std::string GetName() {
		return name;
	}

	virtual ~Transport() {};
private:
	std::string name;
};

class HumanPower :public Transport {
public:

	HumanPower() = default;
	void HumanPowerSound()const {
		std::cout << "бззззззззззз" << std::endl;
	}
	virtual void HumanPowerMove()const {
		std::cout << "топ топ топ, очень тяжело" << std::endl;
	}
};
class Electro :public Transport {
public:
	Electro() = default;
	void ElectroSound()const {
		std::cout << "бззззззззззз" << std::endl;
	}
	virtual void ElectroMove() {

	}

private:
};
class GasEngine {
public:
	GasEngine() = default;
	void GasEngineSound()const {
		std::cout << "бжжжжжжжжжжжжжж" << std::endl;
	}
	virtual void GasEngineMove()const {}
};


class ElectroBike :virtual public Transport, public Electro, public HumanPower {
public:
	void ElectroMove() override {
		while (MoveChoice != 1 || MoveChoice != 2)
		{
			std::cout << "ехать на электродвигателе: 1\nкрутить педали: 2" << std::endl;
			//std::cin >> MoveChoice;
			if (MoveChoice == 1)
			{
				ElectroSound();
			}
			else if (MoveChoice == 2)
			{
				HumanPowerSound();
			}
			else
			{
				std::cerr << "ошибка! выберите снова!" << std::endl;
			}
		}
	}
private:
	int MoveChoice = 1;
};
class ElectroCar :virtual public Transport, public Electro {
public:
	void ElectroMove() override {
		std::cout << "машинка экологично на электричестве " << std::endl;
		ElectroSound();
	}
private:
};
class ElectroScooter :virtual public Transport, public Electro, public HumanPower {
public:

	void ElectroMove()override {
		while (MoveChoice != 1 || MoveChoice != 2)
		{
			std::cout << "ехать на электродвигателе: 1\nкрутить педали: 2" << std::endl;
			//std::cin >> MoveChoice;
			if (MoveChoice == 1)
			{
				ElectroSound();
			}
			else if (MoveChoice == 2)
			{
				HumanPowerSound();
			}
			else
			{
				std::cerr << "ошибка! выберите снова!" << std::endl;
			}
		}
	}


private:
	int MoveChoice = 1;
};

class OrdinaryBike :virtual public Transport, public HumanPower {
public:
	void HumanPowerMove()const override {
		std::cout << "педальки крутятся";
		HumanPowerSound();
	}
};
class OrdinaryCar :virtual public Transport, public HumanPower {
public:
	void HumanPowerMove()const override {
		std::cout << "бедолага тяне рикшу ";
		HumanPowerSound();
	}
};
class OrdinaryScooter :virtual public Transport, public HumanPower {
	void HumanPowerMove()const override {
		std::cout << "на самокате ";
		HumanPowerSound();
	}
};

class GasEngineBike :virtual public Transport, public GasEngine {
	void GasEngineMove()const override {
		std::cout << "злой не экологичный мотоцикл делает ";
		GasEngineSound();
	}
};
class GasEngineCar :virtual public Transport, public GasEngine {
	void GasEngineMove()const override {
		std::cout << "злая бензиновая машинка делает ";
		GasEngineSound();
	}
};
class GasEngineScooter :virtual public Transport, public GasEngine {
	void GasEngineMove()const override {
		std::cout << "очень сомнительный и не понятный бензиновый самокат делает ";
		GasEngineSound();
	}
};




int main() {

	ElectroBike* elBike = new ElectroBike();
	ElectroCar* elCar = new ElectroCar();
	ElectroScooter* elScooter = new ElectroScooter();

	OrdinaryBike* OrdBike = new OrdinaryBike();
	OrdinaryCar* OrdCar = new OrdinaryCar();
	OrdinaryScooter* OrdScooter = new OrdinaryScooter();

	GasEngineBike* GEBike = new GasEngineBike();
	GasEngineCar* GECar = new GasEngineCar();
	GasEngineScooter* GEScooter = new GasEngineScooter();

	std::vector <Transport*> trt;
	trt.push_back(elBike);
	trt.push_back(elCar);
	trt.push_back(elScooter);

	trt.push_back(OrdBike);
	trt.push_back(OrdCar);
	trt.push_back(OrdScooter);

	trt.push_back(GEBike);
	trt.push_back(GECar);
	trt.push_back(GEScooter);


	return 0;
}