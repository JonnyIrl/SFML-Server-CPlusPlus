#include "ExtraIncludes.h"
#include "PacketType.h"
#include <iostream>
#include <list>
using namespace std;

int CheckHowManyPlayersConnected();
sf::IpAddress ipAddress = "127.0.0.1";
sf::UdpSocket listener;
unsigned short port = 5300;
unsigned short newClientPort = 5300;
//list<sf::IpAddress> connectedClientsIP;
//list<unsigned short> connectedClientsPORT;
//list<string> connectedClientsNAME;
list<string> historyMessages;
sf::SocketSelector selector;
void BeginListening();
void ReceivePacket();
//void BroadcastToClients(sf::Packet packet);
//bool AddNewClient(string IPAddress, unsigned short PORT, string Name);
//bool CheckClientExists(string IPADDRESS, unsigned short PORT, string NAME);
void SendPacket(string msg, PacketType type);
bool running = true;
bool connected = false;
string message, name;
bool replied = false;
int messagesCount = 0;
bool nobodyConnected = false;
bool p1, p2, p3, p4, p5, p6, p7, p8;
string ipFromPacket, nameFromPacket;
unsigned short portFromPacket;

//New Stuff


int CheckHowManyPlayersConnected()
{
	//If player 1 == false then nobody is connected.
	if (!p1)
	{
		return 0;
	}

	else if (!p2)
	{
		return 1;
	}

	else if (!p3)
	{
		return 2;
	}

	else if (!p4)
	{
		return 3;
	}

	else if (!p5)
	{
		return 4;
	}

	else if (!p6)
	{
		return 5;
	}

	else if (!p7)
	{
		return 6;
	}

	else if (!p8)
	{
		return 7;
	}

	else
		return 8;
}
void AddNewPlayerConnected()
{
	if (!p1)
	{
		p1 = true;
	}

	else if (!p2)
	{
		p2 = true;
	}

	else if (!p3)
	{
		p3 = true;
	}

	else if (!p4)
	{
		p4 = true;
	}

	else if (!p5)
	{
		p5 = true;
	}

	else if (!p6)
	{
		p6 = true;
	}

	else if (!p7)
	{
		p7 = true;
	}

	else if (!p8)
	{
		p7 = true;
	}
}

int main()
{
	p1 = false;
	p2 = p3 = p4 = p5 = p6 = p7 = p8 = p1;

	if (listener.bind(5300) == sf::Socket::Done)
	{
		cout << "Socket bound" << endl;
		connected = true;
	}

	while (running)
	{
		if (connected)
		ReceivePacket();
	}

	system("PAUSE");
	return 0;
}

//void BroadcastToClients(sf::Packet packet)
//{
//	for (int i = 0; i != connectedClientsIP.size(); i++)
//	{
//		//Point at the specific point of the list.
//		list<sf::IpAddress>::iterator ipIT = connectedClientsIP.begin();
//		advance(ipIT, i);
//		//list<string>::iterator nameIT = connectedClientsNAME.begin();
//		//advance(ipIT, i);
//		list<unsigned short>::iterator portIT = connectedClientsPORT.begin();
//		advance(ipIT, i);
//
//		sf::Socket::Status status = listener.send(packet, *ipIT, *portIT);
//		switch (status)
//		{
//		case sf::Socket::Done:
//		{
//			cout << "Broadcast has been sent successfully" << endl;
//			++messagesCount;
//			cout << "COUNT = " << messagesCount << endl;
//			replied = true;
//		}
//		break;
//		case sf::Socket::Disconnected:
//			std::cout << " has been disconnected\n";
//			break;
//
//		default:
//			;
//		}
//
//	}
//
//}

//bool AddNewClient(string IPADDRESS, unsigned short PORT, string NAME)
//{
//	
//	std::cout << "INSIDE ADD NEW CLIENT CODE " << endl << endl;
//	//returns false if the client doesnt exist already..
//	if (!CheckClientExists(ipFromPacket, portFromPacket, nameFromPacket))
//	{
//		//Need to increment the ports by 1 so if theres more than 1 person playing on the same local network that
//		//They will receive the update message aswell.
//		if (!p1)
//		{
//			cout << "INSIDE P1" << endl;
//			newClientPort = 5300;
//			connectedClientsIP.push_back(IPADDRESS);
//			connectedClientsPORT.push_back(newClientPort);
//			connectedClientsNAME.push_back(NAME);
//			p1 = true;
//			return p1;
//		}
//
//		//If theres only 1 person connected then
//		else if (!p2)
//		{
//			cout << "INSIDE P2" << endl;
//			newClientPort = 5301;
//			connectedClientsIP.push_back(IPADDRESS);
//			connectedClientsPORT.push_back(newClientPort);
//			connectedClientsNAME.push_back(NAME);
//			p2 = true;
//			return p2;
//		}
//
//		//If theres only 2 people connected then
//		else if (!p3)
//		{
//			cout << "INSIDE P3" << endl;
//			newClientPort = 5302;
//			connectedClientsIP.push_back(IPADDRESS);
//			connectedClientsPORT.push_back(newClientPort);
//			connectedClientsNAME.push_back(NAME);
//			p3 = true;
//			return p3;
//		}
//
//		//If theres only 3 people connected then
//		else if (!p4)
//		{
//			cout << "INSIDE P4" << endl;
//			newClientPort = 5303;
//			connectedClientsIP.push_back(IPADDRESS);
//			connectedClientsPORT.push_back(newClientPort);
//			connectedClientsNAME.push_back(NAME);
//			p4 = true;
//			return p4;
//		}
//
//		//If theres only 4 people connected then
//		else if (!p5)
//		{
//			cout << "INSIDE P5" << endl;
//			newClientPort = 5304;
//			connectedClientsIP.push_back(IPADDRESS);
//			connectedClientsPORT.push_back(newClientPort);
//			connectedClientsNAME.push_back(NAME);
//			p5 = true;
//			return p5;
//		}
//
//		//If theres only 5 people connected then
//		else if (!p6)
//		{
//			cout << "INSIDE P6" << endl;
//			newClientPort = 5305;
//			connectedClientsIP.push_back(IPADDRESS);
//			connectedClientsPORT.push_back(newClientPort);
//			connectedClientsNAME.push_back(NAME);
//			p6 = true;
//			return p6;
//		}
//
//		//If theres only 6 people connected then
//		else if (!p7)
//		{
//			cout << "INSIDE P7" << endl;
//			newClientPort = 5306;
//			connectedClientsIP.push_back(IPADDRESS);
//			connectedClientsPORT.push_back(newClientPort);
//			connectedClientsNAME.push_back(NAME);
//			p7 = true;
//			return p7;
//		}
//
//		//If theres only 7 people connected then
//		else if (!p8)
//		{
//			cout << "INSIDE P8" << endl;
//			newClientPort = 5307;
//			connectedClientsIP.push_back(IPADDRESS);
//			connectedClientsPORT.push_back(newClientPort);
//			connectedClientsNAME.push_back(NAME);
//			p8 = true;
//			return p8;
//		}
//	}
//
//}

//Iterate through each of the connected clients and see if that person is already there.
//RETURN TRUE IF THE CLIENT IS ALREADY THERE
//bool CheckClientExists(string IPADDRESS, unsigned short PORT, string NAME)
//{
//	cout << "**** CHECK CLIENT METHOD ****" << endl << endl;;
//	//IF P1 = FALSE THEN NOBODY HAS JOINED SO DO FIRST CONNECTION
//	if (!p1)
//	{
//		cout << "NO PLAYER 1" << endl;
//		cout << "**** END CHECK CLIENT METHOD ****" << endl << endl;
//		return false;
//	}
//
//	if (IPADDRESS.find("192.168.0.50") != string::npos)
//	{
//		cout << "FOUND IP ADDRESS 192.168.0.50" << endl;
//		return true;
//	}
//	bool foundSameIP = false;
//	bool foundSamePORT = false;
//	bool foundSameNAME = false;
//
//	//Check to make sure a real ip was sent through, if not then dont do anything
//	if (IPADDRESS.size() <= 4)
//	{
//		return false;
//	}
//
//	for (list<sf::IpAddress>::const_iterator it = connectedClientsIP.begin(); it != connectedClientsIP.end(); it++)
//	{
//		if (IPADDRESS == it->toString())
//		{
//			foundSameIP = true;
//			break;
//		}
//	}
//
//	for (list<unsigned short>::const_iterator it = connectedClientsPORT.begin(); it != connectedClientsPORT.end(); it++)
//	{
//		if (PORT == *it)
//		{
//			foundSamePORT = true;
//			break;
//		}
//	}
//
//	for (list<string>::const_iterator it = connectedClientsNAME.begin(); it != connectedClientsNAME.end(); it++)
//	{
//		if (NAME == *it)
//		{
//			foundSameNAME = true;
//			break;
//		}
//	}
//
//	//This client has already been connected/already added to the list of connected clients.
//	if (foundSameIP && foundSameNAME && foundSamePORT)
//	{
//		cout << "RETURNING TRUE" << endl;
//		return true;
//	}
//
//	//Else the client doesnt exist 
//	else
//	{
//		cout << "RETURNING FALSE - CLIENT DOES NOT EXIST" << endl;
//		return false;
//	}
//
//}


void ReceivePacket()
{
	sf::Packet packet;
	sf::Socket::Status status = listener.receive(packet, ipAddress, port);
	string clientName;
	string clientIP;
	string testName;// = "Jonny";
	string testMessage;
	unsigned short clientPort;

	switch (status)
	{
	case sf::Socket::Done:
		PacketType type;
		packet >> type;// >> clientIP >> clientName >> clientPort;

		//INITIAL CONNECTION RESPONSE 
		if (type == INITIAL_CONNECT_DATA)
		{
			while (!replied)
			{
				SendPacket(message, type);
			}
			replied = false;
			packet.clear();
			break;
		}
		else if (type == GENERAL_MSG)
		{
			packet >> testMessage >> testName;
			std::cout << testName << ": " << testMessage << "\n";
			historyMessages.push_back(testName + ": " + testMessage);
			while (!replied)
			{
				SendPacket(message, type);
				replied = true;
				break;
			}
			replied = false;
			packet.clear();
		}
		break;

	case sf::Socket::Disconnected:
		std::cout << " has been disconnected\n";
		break;

	default:
		replied = false;
		;
	}
}
void SendPacket(string msg, PacketType type)
{
	if (!replied)
	{
		sf::Packet packet;
		//*****************************************************************************************************************
		if (type == INITIAL_CONNECT_DATA)
		{
			string name;
			sf::Packet packet;
			packet << SERVER_REPLY_MSG;


			sf::Socket::Status status = listener.send(packet, ipAddress, port);
			switch (status)
			{
			case sf::Socket::Done:
			{
				cout << "Client connected!" << endl << endl;
				replied = true;
			}
			break;
			case sf::Socket::Disconnected:
				std::cout << " has been disconnected\n";
				break;

			default:
				;
			}
		}

		//*****************************************************************************************************************
		else if (type == GENERAL_MSG)
		{
			//Sending a list through a packet.
			//Send the size and then each item through as a single string... Might cause problems when there is more than 10 messages etc...
			if (messagesCount >= 11)
			{
				//Dont let the messages overflow..
				historyMessages.pop_front();
			}
			packet << UPDATE_MSG << static_cast<sf::Uint32>(historyMessages.size());
			for (std::list<string>::const_iterator it = historyMessages.begin(); it != historyMessages.end(); ++it)
			{
				packet << *it;
			}



			sf::Socket::Status status = listener.send(packet, ipAddress, port);
			switch (status)
			{
			case sf::Socket::Done:
			{
				++messagesCount;
				cout << "COUNT = " << messagesCount << endl;
				replied = true;
			}
			break;
			case sf::Socket::Disconnected:
				std::cout << " has been disconnected\n";
				break;

			default:
				;
			}

		}

	}

}

//void Broadcast(PacketType type, const std::string & msg)
//{
//	/*for (Clients::iterator it = clients.begin(); it != clients.end(); ++it)
//	{
//		sf::Packet pack;
//		pack << type << msg;
//		it->first->send(pack);
//	}*/
//}
