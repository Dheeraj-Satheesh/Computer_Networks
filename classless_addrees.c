#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    unsigned int address;
    int subnet_mask;
} IPNetwork;
void getClasslessAddressInfo(IPNetwork network)
{
    unsigned int address_octets[4];
    for (int i = 0; i < 4; i++)
    {
        address_octets[i] = (network.address >> (24 - (8 * i))) & 255;
    }
    // Calculate subnet mask
    unsigned int subnet_mask = 0xFFFFFFFF << (32 - network.subnet_mask);
    unsigned int subnet_octets[4];
    for (int i = 0; i < 4; i++)
    {
        subnet_octets[i] = (subnet_mask >> (24 - (8 * i))) & 255;
    }
    // Calculate network ID and host ID
    unsigned int network_id = network.address & subnet_mask;
    unsigned int host_id = network.address & ~subnet_mask;
    printf("Network ID: %d.%d.%d.%d\n", network_id >> 24, (network_id >> 16) & 255, (network_id >> 8) & 255, network_id & 255);
    printf("Host ID: %d.%d.%d.%d\n", host_id >> 24, (host_id >> 16) & 255, (host_id >> 8) & 255, host_id & 255);
}
int main()
{
    IPNetwork network;
    char ip_address_str[16];
    int subnet_mask;
    printf("Enter IP Address and Subnet Mask (format: x.y.z.t n): ");
    scanf("%s%c%d", ip_address_str,&subnet_mask);
    // Parse IP address string to unsigned integer
    unsigned int ip_address = 0;
    char *token = strtok(ip_address_str, ".");
    int octet_index = 0;
    while (token != NULL && octet_index < 4)
    {
        int octet = atoi(token);
        if (octet >= 0 && octet <= 255)
        {
            ip_address |= octet << (24 - (8 * octet_index));
        }
        else
        {
            printf("Invalid IP Address\n");
            return 0;
        }
        token = strtok(NULL, ".");
        octet_index++;
    }
    network.address = ip_address;
    network.subnet_mask = subnet_mask;
    getClasslessAddressInfo(network);
    return 0;
}
