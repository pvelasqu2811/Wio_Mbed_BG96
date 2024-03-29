// ----------------------------------------------------------------------------
// Copyright 2016-2019 ARM Ltd.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------------------------------------------------------

#ifndef _IOTHUB_MQTTS_NETWORK_H_
#define _IOTHUB_MQTTS_NETWORK_H_

#include "NetworkInterface.h"
#include "TLSSocket.h"

class MQTTNetwork {
public:
    MQTTNetwork(NetworkInterface* aNetwork) : network(aNetwork) {
        socket = new TLSSocket();
    }

    ~MQTTNetwork() {
        delete socket;
    }

    int read(unsigned char* buffer, int len, int timeout) {
        nsapi_size_or_error_t rc = 0;
        socket->set_timeout(timeout);
        rc = socket->recv(buffer, len);
        if (rc == NSAPI_ERROR_WOULD_BLOCK){
            // time out and no data
            // MQTTClient.readPacket() requires 0 on time out and no data.
            return 0;
        }
        return rc;
    }

    int write(unsigned char* buffer, int len, int timeout) {
        // TODO: handle time out
        return socket->send(buffer, len);
    }

    int connect(const char* hostname, int port, const char *ssl_ca_pem = NULL,
            const char *ssl_cli_pem = NULL, const char *ssl_pk_pem = NULL) {
        nsapi_error_t ret;

        ret = socket->open(network);
        if (ret != NSAPI_ERROR_OK) return ret;

        ret = socket->set_root_ca_cert(ssl_ca_pem);
        if (ret != NSAPI_ERROR_OK) return ret;

        if (ssl_cli_pem != NULL && ssl_pk_pem != NULL) {
            ret = socket->set_client_cert_key(ssl_cli_pem, ssl_pk_pem);
            if (ret != NSAPI_ERROR_OK) return ret;
        }

        return socket->connect(hostname, port);
    }

    int disconnect() {
        return socket->close();
    }

private:
    NetworkInterface* network;
    TLSSocket* socket;
};

#endif // _IOTHUB_MQTTS_NETWORK_H_
