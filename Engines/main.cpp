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
		std::cout << "������������" << std::endl;
	}
	virtual void HumanPowerMove()const {
		std::cout << "��� ��� ���, ����� ������" << std::endl;
	}
};
class Electro :public Transport {
public:
	Electro() = default;
	void ElectroSound()const {
		std::cout << "������������" << std::endl;
	}
	virtual void ElectroMove() {

	}

private:
};
class GasEngine {
public:
	GasEngine() = default;
	void GasEngineSound()const {
		std::cout << "���������������" << std::endl;
	}
	virtual void GasEngineMove()const {}
};


class ElectroBike :virtual public Transport, public Electro, public HumanPower {
public:
	void ElectroMove() override {
		while (MoveChoice != 1 || MoveChoice != 2)
		{
			std::cout << "����� �� ����������������: 1\n������� ������: 2" << std::endl;
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
				std::cerr << "������! �������� �����!" << std::endl;
			}
		}
	}
private:
	int MoveChoice = 1;
};
class ElectroCar :virtual public Transport, public Electro {
public:
	void ElectroMove() override {
		std::cout << "������� ���������� �� ������������� " << std::endl;
		ElectroSound();
	}
private:
};
class ElectroScooter :virtual public Transport, public Electro, public HumanPower {
public:

	void ElectroMove()override {
		while (MoveChoice != 1 || MoveChoice != 2)
		{
			std::cout << "����� �� ����������������: 1\n������� ������: 2" << std::endl;
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
				std::cerr << "������! �������� �����!" << std::endl;
			}
		}
	}


private:
	int MoveChoice = 1;
};

class OrdinaryBike :virtual public Transport, public HumanPower {
public:
	void HumanPowerMove()const override {
		std::cout << "�������� ��������";
		HumanPowerSound();
	}
};
class OrdinaryCar :virtual public Transport, public HumanPower {
public:
	void HumanPowerMove()const override {
		std::cout << "�������� ���� ����� ";
		HumanPowerSound();
	}
};
class OrdinaryScooter :virtual public Transport, public HumanPower {
	void HumanPowerMove()const override {
		std::cout << "�� �������� ";
		HumanPowerSound();
	}
};

class GasEngineBike :virtual public Transport, public GasEngine {
	void GasEngineMove()const override {
		std::cout << "���� �� ����������� �������� ������ ";
		GasEngineSound();
	}
};
class GasEngineCar :virtual public Transport, public GasEngine {
	void GasEngineMove()const override {
		std::cout << "���� ���������� ������� ������ ";
		GasEngineSound();
	}
};
class GasEngineScooter :virtual public Transport, public GasEngine {
	void GasEngineMove()const override {
		std::cout << "����� ������������ � �� �������� ���������� ������� ������ ";
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