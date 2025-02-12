#include "CreatePlayerMessage.h"
#include <iostream>

void CreatePlayerMessage::Process()
{
    // Appel de la fonction Deserialize pour traiter les donn�es
    // Assurez-vous de fournir les bonnes donn�es en entr�e � la fonction
    std::vector<uint8_t> data;  // Remplacez cela par les donn�es re�ues
    Deserialize(data);

    // Affichage du playerId apr�s la d�s�rialisation
    std::cout << "Player ID: " << playerId << std::endl;
}

std::vector<uint8_t> CreatePlayerMessage::Serialize()
{
    // Impl�mentation de la s�rialisation (exemple simple avec un entier)
    std::vector<uint8_t> data;
    data.push_back(static_cast<uint8_t>(playerId >> 24));
    data.push_back(static_cast<uint8_t>(playerId >> 16));
    data.push_back(static_cast<uint8_t>(playerId >> 8));
    data.push_back(static_cast<uint8_t>(playerId));

    return data;
}

void CreatePlayerMessage::Deserialize(const std::vector<uint8_t>& data)
{
    // D�s�rialisation de l'ID du joueur depuis les donn�es
    if (data.size() >= 4)
    {
        playerId = (static_cast<int>(data[0]) << 24) |
            (static_cast<int>(data[1]) << 16) |
            (static_cast<int>(data[2]) << 8) |
            static_cast<int>(data[3]);
    }
}
