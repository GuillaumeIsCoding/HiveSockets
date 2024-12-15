//
// Created by guill on 2024-12-15.
//
#include "SocketsInterface.h"

namespace hive::sockets
{
    NetworkingSockets *Sockets::createNetworkingSockets() noexcept {
        return SteamNetworkingSockets();
    }

    NetworkingUtils* Sockets::createNetworkingUtils() noexcept {
        return SteamNetworkingUtils();
    }

    Sockets::Sockets()
        : m_sockets(nullptr), m_utils(nullptr)
    {
        m_sockets = createNetworkingSockets();
        m_utils = createNetworkingUtils();
    }

    Sockets::~Sockets() {
        delete m_sockets;
    }

    ListenSocket Sockets::createListenSocket(const AddressIP &localAddress, int options, const ConfigInfo *config) {
        return m_sockets->CreateListenSocketIP(localAddress, options, config);
    }

    Connection Sockets::connectByIPAddress(const AddressIP &address, int options, const ConfigInfo *config) {
        return m_sockets->ConnectByIPAddress(address, options, config);
    }

    Result Sockets::acceptConnection(Connection connection) {
        return m_sockets->AcceptConnection(connection);
    }

    bool Sockets::closeListenSocket(ListenSocket listenSocket) {
        return m_sockets->CloseListenSocket(listenSocket);
    }

    Result Sockets::sendMessageToConnection(Connection connection, const void *data, uint32_t cbData, int sendFlags, int64 *outMessageNumber) {
        return m_sockets->SendMessageToConnection(connection, data, cbData, sendFlags, outMessageNumber);
    }

    void Sockets::sendMessage(int messagesNumber, Message *const *messages, int64 *outMessageNumberOrResult) {
        return m_sockets->SendMessages(messagesNumber, messages, outMessageNumberOrResult);
    }

    Message *Sockets::allocateMessage(int allocateBuffer) {
        return m_utils->AllocateMessage(allocateBuffer);
    }

    Result Sockets::flushMessagesOnConnection(Connection connection) {
        return m_sockets->FlushMessagesOnConnection(connection);
    }

    int Sockets::receiveMessagesOnConnection(Connection connection, Message **outMessages, int maxMessages) {
        return m_sockets->ReceiveMessagesOnConnection(connection, outMessages, maxMessages);
    }
}
