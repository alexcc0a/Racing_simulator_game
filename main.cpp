#include <iostream>
#include <Windows.h>
#include <vector>
#include "air_vehicle.h"
#include "all_terrain_boots.h"
#include "broom.h"
#include "camel.h"
#include "carpet_plane.h"
#include "centaur.h"
#include "DistanceError.h"
#include "CountError.h"
#include "eagle.h"
#include "ground_vehicle.h"
#include "speed_camel.h"
#include "vehicle.h"
#include "print_registrated.h"
#include "check_unique.h"
#include "print_registrated.h"
#include "print_race_results.h"
#include "print_choice.h"
#include "print_vc_name.h"
#include "check_distance.h"



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cmd_continue =0;
	std::cout << "����� ���������� � �������� ���������!" << '\n';
	do {
			std::cout << "1. ����� ��� ��������� ����������" << '\n'
			<< "2. ����� ��� ���������� ����������" << '\n'
			<< "3. ����� ��� ��������� � ���������� ����������" << '\n'
			<< "�������� ��� �����: " << std::endl;
		int race_type_cmd;
		std::cin >> race_type_cmd;
		int distance;
		std::cout << "������� ����� ��������� (������ ���� ������������): ";
		std::cin >> distance;
		
		try {
			checkDistance(distance);
			std::cout << "������ ���� ���������������� ���� �� ��� ������������ ��������" << '\n'
				<< "1. ���������������� ���������" << '\n'
				<< "�������� ��������: ";
			int cmd_registrate;
			std::cin >> cmd_registrate;
			std::vector <Vehicle*> vehicles;
			int cmd_choice = 0;
			int size = 0;
			bool unique = true;
			if (race_type_cmd == 1) {

				print_choice(race_type_cmd, distance);
				do {
					print_vehicle_name();
					std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
					std::cin >> cmd_choice;
					switch (cmd_choice) {
					case 1:
					{Vehicle* terrainBoots = new AllTerrainBoots();
					if (check_unique(vehicles, terrainBoots))
					{
						vehicles.push_back(terrainBoots);
					}
					}break;
					case 3:
					{Vehicle* camel = new Camel();
					if (check_unique(vehicles, camel))
					{
						vehicles.push_back(camel);
					};
					}break;
					case 4:
					{Vehicle* centaur = new Centaur();
					if (check_unique(vehicles, centaur))
					{
						vehicles.push_back(centaur);
					};
					}break;
					case 6:
					{Vehicle* speedCamel = new SpeedCamel();
					if (check_unique(vehicles, speedCamel)) {
						vehicles.push_back(speedCamel);
					};

					}break;
					case 0: if (vehicles.size() < 2) {
						std::cout << "������ ���� ���������������� ���� �� ��� ������������ ��������!" << std::endl;
						cmd_choice = 1;
						continue;
					}
						  else { break; };
					default: std::cout << "������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
					}

					print_registrated(vehicles);

					if (cmd_choice == 0) {
						std::cout << "\n1. ���������������� ���������" << '\n'
							<< "2. ������ �����" << '\n'
							<< "�������� ��������: ";
						int cmd = 0;
						std::cin >> cmd;
						if (cmd != 2) {
							cmd_choice = 1;
							continue;
						}
						else {
							printRaceResults(vehicles, distance);
							break;
						}
					}
				} while (cmd_choice != 0);
			}
			if (race_type_cmd == 2) {

				print_choice(race_type_cmd, distance);
				do {
					print_vehicle_name();
					std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
					std::cin >> cmd_choice;
					switch (cmd_choice) {
					case 2:
					{Vehicle* broom = new Broom();
					if (check_unique(vehicles, broom))
					{
						vehicles.push_back(broom);
					};
					}break;
					case 5:
					{Vehicle* eagle = new Eagle();
					if (check_unique(vehicles, eagle))
					{
						vehicles.push_back(eagle);
					};

					}break;
					case 7:
					{Vehicle* carpet = new CarpetPlane();
					if (check_unique(vehicles, carpet))
					{
						vehicles.push_back(carpet);
					};

					}break;
					case 0: if (vehicles.size() < 2) {
						std::cout << "������ ���� ���������������� ���� �� ��� ������������ ��������!" << std::endl;
						cmd_choice = 1;
						continue;
					}
						  else { break; };
					default: std::cout << "������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
					}
					print_registrated(vehicles);

					if (cmd_choice == 0) {
						std::cout << "\n1. ���������������� ���������" << '\n'
							<< "2. ������ �����" << '\n'
							<< "�������� ��������: ";
						int cmd = 0;
						std::cin >> cmd;
						if (cmd != 2) {
							cmd_choice = 1;
							continue;
						}
						else {
							printRaceResults(vehicles, distance);
							break;
						}
					}
				} while (cmd_choice != 0);
			}

			if (race_type_cmd == 3) {
				print_choice(race_type_cmd, distance);
				do {
					print_vehicle_name();
					std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
					std::cin >> cmd_choice;
					switch (cmd_choice) {
					case 1:
					{Vehicle* terrainBoots = new AllTerrainBoots();
					if (check_unique(vehicles, terrainBoots))
					{
						vehicles.push_back(terrainBoots); //������ � ������ ������ � vehicles[0] ����������, ���� �� ������
					}
					}break;

					case 2:
					{Vehicle* broom = new Broom();
					if (check_unique(vehicles, broom))
					{
						vehicles.push_back(broom);
					};
					}break;
					case 3:
					{Vehicle* camel = new Camel();
					if (check_unique(vehicles, camel))
					{
						vehicles.push_back(camel);
					};
					}break;
					case 4:
					{Vehicle* centaur = new Centaur();
					if (check_unique(vehicles, centaur))
					{
						vehicles.push_back(centaur);
					};
					}break;
					case 5:
					{Vehicle* eagle = new Eagle();
					if (check_unique(vehicles, eagle))
					{
						vehicles.push_back(eagle);
					};

					}break;
					case 6:
					{Vehicle* speedCamel = new SpeedCamel();
					if (check_unique(vehicles, speedCamel)) {
						vehicles.push_back(speedCamel);
					};

					}break;
					case 7:
					{Vehicle* carpet = new CarpetPlane();
					if (check_unique(vehicles, carpet))
					{
						vehicles.push_back(carpet);
					};

					}break;
					case 0: if (vehicles.size() < 2) {
						std::cout << "������ ���� ���������������� ���� �� ��� ������������ ��������!" << std::endl;
						cmd_choice = 1;
						continue;
					}
						  else { break; };
					default: std::cout << "������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
					}
					print_registrated(vehicles);

					if (cmd_choice == 0) {
						std::cout << "\n1. ���������������� ���������" << '\n'
							<< "2. ������ �����" << '\n'
							<< "�������� ��������: ";
						int cmd = 0;
						std::cin >> cmd;
						if (cmd != 2) {
							cmd_choice = 1;
							continue;
						}
						else {
							printRaceResults(vehicles, distance);
							break;
						}
					}
				} while (cmd_choice != 0);
			}
			std::cout << "\n1. �������� ��� ���� �����" << '\n'
				<< "2. �����" << '\n';
			std::cin >> cmd_continue;
		}
		catch (DistanceError& ex) {
			std::cout << ex.what() << "\n������� ��������� ��� ���!" << std::endl;
		}

		
	} while (cmd_continue != 2);
	
	return 0;
}