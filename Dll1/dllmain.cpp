// dllmain.cpp : Defines the entry point for the DLL application.

#include "mem.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <math.h>

const char* vehicle_ids[212] = {
    "LANDSTAL",
    "IDAHO",
	 "BUFFALO",
	 "LINERUN",
	 "PEREN",
	 "SENTINEL",
	 "DUMPER",
	 "FIRETRUK",
	 "TRASH",
	 "STRETCH",
	 "MANANA",
	 "INFERNUS",
	 "VOODOO",
	 "PONY",
	 "MULE",
	 "CHEETAH",
	 "AMBULAN",
	 "LEVIATHN",
	 "MOONBEAM",
	 "ESPERANT",
	 "TAXI",
	 "WASHING",
	 "BOBCAT",
	 "MRWHOOP",
	 "BFINJECT",
	 "HUNTER",
	 "PREMIER",
	 "ENFORCER",
	 "SECURICA",
	 "BANSHEE",
	 "PREDATOR",
	 "BUS",
	 "RHINO",
	 "BARRACKS",
	 "HOTKNIFE",
	 "ARTICT1",
	 "PREVION",
	 "COACH",
	 "CABBIE",
	 "STALLION",
	 "RUMPO",
	 "RCBANDIT",
	 "ROMERO",
	 "PACKER",
	 "MONSTER",
	 "ADMIRAL",
	 "SQUALO",
	 "SEASPAR",
	 "MOPED",
	 "TRAM",
	 "ARTICT2",
	 "TURISMO",
	 "SPEEDER",
	 "REEFER",
	 "TROPIC",
	 "FLATBED",
	 "YANKEE",
	 "GOLFCART",
	 "SOLAIR",
	 "TOPFUN",
	 "SEAPLANE",
	 "BIKE",
	 "MOPED",
	 "FREEWAY",
	 "RCBARON",
	 "RCRAIDER",
	 "GLENDALE",
	 "OCEANIC",
	 "DIRTBIKE",
	 "SPARROW",
	 "PATRIOT",
	 "QUADBIKE",
	 "COASTGRD",
	 "DINGHY",
	 "HERMES",
	 "SABRE",
	 "RUSTLER",
	 "ZR350",
	 "WALTON",
	 "REGINA",
	 "COMET",
	 "BMX",
	 "BURRITO",
	 "CAMPER",
	 "MARQUIS",
	 "BAGGAGE",
	 "DOZER",
	 "MAVERICK",
	 "COASTMAV",
	 "RANCHER",
	 "FBIRANCH",
	 "VIRGO",
	 "GREENWOO",
	 "CUPBOAT",
	 "HOTRING",
	 "SANDKING",
	 "BLISTAC",
	 "POLMAV",
	 "BOXVILLE",
	 "BENSON",
	 "MESA",
	 "RCGOBLIN",
	 "HOTRING",
	 "HOTRING",
	 "BLOODRA",
	 "RANCHER",
	 "SUPERGT",
	 "ELEGANT",
	 "JOURNEY",
	 "CHOPPERB",
	 "MTB",
	 "BEAGLE",
	 "CROPDUST",
	 "STUNT",
	 "PETROL",
	 "RDTRAIN",
	 "NEBULA",
	 "MAJESTIC",
	 "BUCCANEE",
	 "SHAMAL",
	 "HYDRA",
	 "FCR900",
	 "NRG500",
	 "HPV1000",
	 "CEMENT",
	 "TOWTRUCK",
	 "FORTUNE",
	 "CADRONA",
	 "FBITRUCK",
	 "WILLARD",
	 "FORKLIFT",
	 "TRACTOR",
	 "COMBINE",
	 "FELTZER",
	 "REMINGTN",
	 "SLAMVAN",
	 "BLADE",
	 "FREIGHT",
	 "STREAK",
	 "VORTEX",
	 "VINCENT",
	 "BULLET",
	 "CLOVER",
	 "SADLER",
	 "FIRETRUK",
	 "HUSTLER",
	 "INTRUDER",
	 "PRIMO",
	 "CARGOBOB",
	 "TAMPA",
	 "SUNRISE",
	 "MERIT",
	 "UTILITY",
	 "NEVADA",
	 "YOSEMITE",
	 "WINDSOR",
	 "MTRUCK_A",
	 "MTRUCK_B",
	 "URANUS",
	 "JESTER",
	 "SULTAN",
	 "STRATUM",
	 "ELEGY",
	 "RAINDANC",
	 "RCTIGER",
	 "FLASH",
	 "TAHOMA",
	 "SAVANNA",
	 "BANDITO",
	 "FREIFLAT",
	 "CSTREAK",
	 "KART",
	 "MOWER",
	 "DUNE",
	 "SWEEPER",
	 "BROADWAY",
	 "TORNADO",
	 "AT400",
	 "DFT30",
	 "HUNTLEY",
	 "STAFFORD",
	 "BF400",
	 "NEWSVAN",
	 "TUG",
	 "PETROTR",
	 "EMPEROR",
	 "WAYFARE",
	 "EUROS",
	 "HOTDOG",
	 "CLUB",
	 "FREIFLAT",
	 "ARTICT3",
	 "ANDROM",
	 "DODO",
	 "RCCAM",
	 "LAUNCH",
	 "POLICE_LA",
	 "POLICE_SF",
	 "POLICE_VG",
	 "POLRANGER",
	 "PICADOR",
	 "SWATVAN",
	 "ALPHA",
	 "PHOENIX",
	 "GLENDALE",
	 "SADLER",
	 "BAGBOXA",
	 "BAGBOXB",
	 "STAIRS",
	 "BOXBURG",
	 "FARM_TR1",
	 "UTIL_TR1"
};

DWORD WINAPI parseCommandsThread(HMODULE hModule)
{
    std::ifstream testFile("tasscript.txt");
    std::string line;

    while (getline(testFile, line)) {

        std::string command;
        std::string param1;
        std::string param2;
        std::string param3;

        std::replace(line.begin(), line.end(), ',', ' ');

        std::stringstream ss(line);

        ss >> command;
        ss >> param1;
        ss >> param2;
        ss >> param3;

        if (command == "a")
        {
            std::cout << "e";
            Sleep(5000);
            std::cout << "ee";
        }
    }

    ExitThread(0);
    return 0;
}

inline std::string getCurrentDateTime(std::string s) {
    time_t now = time(0);
    struct tm  tstruct;
    char  buf[80];
    tstruct = *localtime(&now);
    if (s == "console")
        strftime(buf, sizeof(buf), "(%X) ", &tstruct);
    else if (s == "file")
        strftime(buf, sizeof(buf), "taslog-%d-%m-%Y %X.txt", &tstruct);

    return std::string(buf);
};


DWORD WINAPI myThread(HMODULE hModule)
{
    AllocConsole();
    FILE* f1 = new FILE;
    freopen_s(&f1, "CONOUT$", "w", stdout);
	std::cout << "Vehicle Pool Info 1.5\n-------------------------\nPlease read the readme.";


	bool running = false;
	int speed = 1000; // sleep time for while loop

    while (true)
    {
		if (running)
		{
			system("cls");

			std::cout << "Vehicle Pool Info 1.5\n-------------------------\n";

			// appropriate stuff
			int a_array[24] = {};
			int i_array[24] = {};
			for (int i = 0; i < 24; i++)
			{
				int appropriates = 0xC0E9F6 + 0x2 * i;
				int inappropriates = 0xC0E9C8 + 0x2 * i;
				short ap = *(short*)appropriates;
				short in = *(short*)inappropriates;
				if (ap != 65535)
				{
					a_array[i] = ap;
				}
				if (in != 65535)
				{
					i_array[i] = in;

				}

			}
			std::cout << "Appropriate: ";
			for (int i = 0; i < 24; i++)
			{
				int x = a_array[i];
				if (x > 0)
				{
					std::cout << vehicle_ids[a_array[i]-400] << ", ";
				}
			}
			std::cout << "\n";
			
			std::cout << "Inappropriate: ";
			for (int i = 0; i < 24; i++)
			{
				int x = i_array[i];
				if (x > 0)
				{
					std::cout << vehicle_ids[i_array[i]-400] << ", ";
				}
			}
			std::cout << "\n\n";


			// model stuff
			int pool = *(int*)0xB74494;
			int array_addr = *(int*)pool;
			int free_addr = *(int*)pool + 0x4;
			int top = *(int*)pool + 0xC;

            for (int i = 0; i < 110; i++)
            {
				if (array_addr == 0)
				{
					std::cout << std::fixed << std::setprecision(4) << "n/a\n";
				}
				else
				{
					int my_vehicle = array_addr + 0xA18 * i;
					int cj_vehicle = my_vehicle + 0x36;

					int vehicle_pos = my_vehicle + 0x14;
					int pos = *(int*)vehicle_pos;

					int pos_x = pos + 0x30;
					int pos_y = pos + 0x34;
					int pos_z = pos + 0x38;
					float *x = (float*)pos_x;
					float *y = (float*)pos_y;
					float *z = (float*)pos_z;
					if (x != (float*)0x00B74270)
					{
						int vehicle_id = my_vehicle + 0x22;
						short my_index = *(short*)vehicle_id;
						if (my_index > 0 && my_index < 1000)
						{
							if (i == ((*(short*)0xa489ec & 0xFF00) >> 8))
							{
								std::cout << "VG: ";
							}
							else if(*(char*)cj_vehicle == 2)
							{
								std::cout << "CJ: ";
							}
							else
							{
								std::cout << i << ": ";
							}
							std::cout << std::fixed << std::setprecision(4) << vehicle_ids[my_index - 400] << " [" << *x << ", " << *y << ", " << *z << "]" << "\n";
						}
					}

				}

            }

        }
		else
		{
			if (*(int*)0xB74494)
			{
				system("cls");
				running = true;
				speed = 300;
			}
		}

        Sleep(speed);
    }

    fclose(f1);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)myThread, hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

