#include "mbed.h"

#define NTP_DEFULT_NIST_SERVER_ADDRESS "2.pool.ntp.org"
#define NTP_DEFULT_NIST_SERVER_PORT 123

class NTPClient {
    public:
        explicit NTPClient(NetworkInterface *interface = NULL);
        void set_server(char* server, int port);
        time_t get_timestamp(int timeout = 15000);
        void network(NetworkInterface *interface);

    private:
        NetworkInterface *iface;
        char* nist_server_address;
        int nist_server_port;

        uint32_t ntohl(uint32_t num);
};
