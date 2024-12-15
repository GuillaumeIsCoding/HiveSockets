/**
* @date 2024-12-15
* @author guillaumeIsCoding
* @file SocketsTypes.h
*/
#pragma once
#include "hvpch.h"

namespace hive::sockets
{
    #ifdef ISTEAMNETWORKINGUTILS
    /**
     *
     */
    using NetworkingUtils = ISteamNetworkingUtils;
    #else
    using NetworkingUtils = void;
    #endif

    #ifdef ISTEAMNETWORKINGSOCKETS
    /**
     *
     */
    using NetworkingSockets = ISteamNetworkingSockets;
    #else
    using NetworkingSockets = void;
    #endif

    #ifdef STEAMNETWORKINGTYPES
    /**
     *
     */
    using ListenSocket = HSteamListenSocket;

    /**
     *
     */
    using AddressIP = SteamNetworkingIPAddr;

    /**
     *
     */
    using Connection = HSteamNetConnection;

    /**
     *
     */
    using ConnectionInfo = SteamNetConnectionInfo_t;

    /**
     *
     */
    using ConfigInfo = SteamNetworkingConfigValue_t;

    /**
     *
     */
    using Message = SteamNetworkingMessage_t;

    /**
     *
     */
    using Result = EResult;

    /**
     *
     */
    using PollGroup = HSteamNetPollGroup;
    #else
    using ListenSocket = uint32_t;

    struct AddressIP {

    };

    using Connection = uint32;

    struct ConnectionInfo {

    };

    struct ConfigInfo {

    };

    struct Message {

    };

    enum Result {

    };
    #endif

}

