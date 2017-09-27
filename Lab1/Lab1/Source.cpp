#include "Net.h"
#include <iostream>

using namespace std;

#define SERVER "127.0.0.1"

struct Player
{
	char* ip = SERVER;
	int port;
};

int __cdecl main(int argc, char **argv)
{
	Net Network;

	Network.initialise();

	Player playerA;
	playerA.port = 28000;

	Player playerB;
	playerB.port = 28001;

	string UserInput = "";

	bool messageReceived = false;
	char message[200] = "World";

	cin >> UserInput;

	if (UserInput == "A" || UserInput == "a")
	{
		Network.setupUDP(playerA.port, playerA.ip);

		Network.sendData(playerB.ip, playerB.port, message);
	}

	
	if (UserInput == "B" || UserInput == "b")
	{
		Network.setupUDP(playerB.port, playerB.ip);

		Network.sendData(playerB.ip, playerB.port, message);
	}

	while (!messageReceived)
	{
		if (Network.receiveData(message))
		{
			cout << message << endl;
			messageReceived = true;
		}
	}

	system("Pause");

	return 0;
}