#include <stdio.h>
#include <string.h>

// Function to split the IP address and extract network ID and host ID
void splitIPAddress(char ip[])
{
    char ipAddress[20];
    strcpy(ipAddress, ip); // Copy the input IP address to another string for manipulation

    // Separate IP address and network bits
    char ipAddressPart[16];
    int networkBits = 0;
    int i = 0;
    int j = 0;
    while (ipAddress[i] != '/')
    { // Extract IP address part before '/'
        ipAddressPart[j] = ipAddress[i];
        i++;
        j++;
    }
    ipAddressPart[j] = '\0';
    i++;
    while (ipAddress[i] != '\0')
    { // Extract network bits after '/'
        networkBits = networkBits * 10 + (ipAddress[i] - '0');
        i++;
    }

    // Separate IP address into octets
    int octet1, octet2, octet3, octet4;
    sscanf(ipAddressPart, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    // Calculate network ID and host ID
    unsigned int networkID = (octet1 << 24) | (octet2 << 16) | (octet3 << 8) | octet4;
    unsigned int hostID = networkID & ((1 << (32 - networkBits)) - 1);
    networkID = networkID & (~hostID);
    // Print the results
    printf("\nNetwork ID: %d.%d.%d.%d\n", (networkID >> 24) & 255, (networkID >> 16) & 255, (networkID >> 8) & 255, networkID & 255);
    printf("Host ID: %d.%d.%d.%d\n", (hostID >> 24) & 255, (hostID >> 16) & 255, (hostID >> 8) & 255, hostID & 255);
}
int main()
{
    char ipAddress[20];
    printf("Enter IP address in x.y.z.t/n format: ");
    scanf("%s", ipAddress);                                  // Read the IP address from the user
    splitIPAddress(ipAddress);                               // Call the function to split and calculate network ID and host ID
    printf("\nName: Satheesh Dheeraj\nReg No: 21BCE2418\n"); // Print author's name and registration number
    return 0;
}
