#include "Message.h"
#include "../Server/ClientManager.h"


struct CreateClientMessage : public Message
{
    static constexpr int ID = 1;

    std::string ipAddress;

    int getId() const override { return ID; }

    std::vector<uint8_t>& serialize(std::vector<uint8_t>& buffer) const override
    {
        buffer.clear();  // Vider le buffer avant de s�rialiser

        // S�rialiser l'ID (en 4 octets)
        int id = getId();
        buffer.resize(sizeof(id) + ipAddress.size() + 1);  // +1 pour le caract�re '\0'

        std::memcpy(buffer.data(), &id, sizeof(id));  // Copier l'ID dans le buffer

        // S�rialiser l'adresse IP (cha�ne de caract�res avec '\0' � la fin)
        std::memcpy(buffer.data() + sizeof(id), ipAddress.c_str(), ipAddress.size() + 1);  // Inclut '\0' de fin de cha�ne

        return buffer;
    }


    void deserialize(const std::vector<uint8_t>& buffer) override
    {
        // D�s�rialisation de l'entier (qui est au d�but du buffer)
        int value;
        std::memcpy(&value, buffer.data(), sizeof(int));

        // D�s�rialisation de l'adresse IP (� partir de la position apr�s l'entier)
        std::string ipAddress;
        size_t offset = sizeof(int);  // L'adresse IP commence apr�s l'entier
        for (size_t i = offset; i < buffer.size(); ++i) {
            if (buffer[i] == '\0') {
                break;  // Fin de la cha�ne
            }
            ipAddress.push_back(static_cast<char>(buffer[i]));
        }

        // Ajouter l'adresse IP au ClientManager
       // ClientManager::addClient(ipAddress);

        // Affichage pour le d�bogage
        std::cout << "[CreateClientMessage] Received: " << std::endl;
        std::cout << "Value: " << value << ", IP Address: " << ipAddress << std::endl;
    }


    void process() const override
    {
       /* ClientManager::addClient(ipAddress);*/
        std::cout << "[CreateClientMessage] Received: " << std::endl;
    }
};