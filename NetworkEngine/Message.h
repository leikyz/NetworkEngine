//#ifndef MESSAGE_H
//#define MESSAGE_H
//
//#include <vector>
//#include <cstdint>
//
//struct Message 
//{
//    virtual ~Message() = default;
//
//    // Identifiant unique du message
//    const int id;
//
//    // Constructeur pour initialiser l'ID
//    explicit Message(int messageId) : id(messageId) {}
//
//    // S�rialisation : Convertit le message en un tableau de bytes
//    virtual std::vector<uint8_t> Serialize() const = 0;
//
//    // D�s�rialisation : Remplit l'objet avec les donn�es re�ues
//    virtual void Deserialize(const std::vector<uint8_t>& data) = 0;
//};
//
//#endif // MESSAGE_H
