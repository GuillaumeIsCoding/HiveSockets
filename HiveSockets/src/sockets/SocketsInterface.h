/**
 * @date 2024-12-15
 * @author guillaumeIsCoding
 * @file SocketsInterface.h
 */
#pragma once
#include "hvpch.h"
#include "SocketsTypes.h"

namespace hive::sockets
{
 class Sockets {
 public:
    Sockets();
    virtual ~Sockets();

    /**
     *
     * @param localAddress
     * @param options
     * @param config
     * @return
     */
    virtual ListenSocket createListenSocket( const AddressIP &localAddress, int options, const ConfigInfo *config );

    /**
     *
     * @param address
     * @param options
     * @param config
     * @return
     */
    virtual Connection connectByIPAddress( const AddressIP &address, int options, const ConfigInfo *config );

    /**
     *
     * @param connection
     * @return
     */
    virtual Result acceptConnection( Connection connection );

    /**
     *
     * @param listenSocket
     * @return
     */
    virtual bool closeListenSocket( ListenSocket listenSocket );

    /**
     *
     * @param connection
     * @param data
     * @param cbData
     * @param sendFlags
     * @param outMessageNumber
     * @return
     */
    virtual Result sendMessageToConnection( Connection connection, const void *data, uint32_t cbData, int sendFlags, int64 *outMessageNumber);

    /**
     *
     * @param messagesNumber
     * @param messages
     * @param outMessageNumberOrResult
     */
    virtual void sendMessage( int messagesNumber, Message *const *messages, int64 *outMessageNumberOrResult );

    /**
     * 
     * @param allocateBuffer 
     * @return 
     */
    virtual Message* allocateMessage( int allocateBuffer );

    /**
     *
     * @param connection
     * @return
     */
    virtual Result flushMessagesOnConnection( Connection connection );

    /**
     * 
     * @param connection
     * @param outMessages 
     * @param maxMessages 
     * @return 
     */
    virtual int receiveMessagesOnConnection( Connection connection, Message** outMessages, int maxMessages );
 private:
     static NetworkingSockets* createNetworkingSockets() noexcept;
     static NetworkingUtils* createNetworkingUtils() noexcept;
 private:
     NetworkingSockets* m_sockets;
     NetworkingUtils* m_utils;
 };

}

