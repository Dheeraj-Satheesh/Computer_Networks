/*204
170
240
195
*/
#include <stdio.h>
unsigned char generateChecksum(const unsigned char* data, int length)
{
    unsigned int sum = 0;  // Use an unsigned int to accommodate larger values
    int i;

    for (i = 0; i < length; i++)
    {
        sum += data[i];
    }
    unsigned int actualSum = sum;  // Store the actual sum before wrapping
    while (sum > 255)  // Wrap the sum if it is greater than 255
    {
        sum = (sum & 0xFF) + (sum >> 8);  // Add the carry bits to the sum
    }
    printf("Sum (Decimal): %u\n", actualSum);  // Print the actual sum
    printf("Sum (Binary): ");
    printBinary(actualSum,32);  // Print binary representation up to 32 bits
    printf("\n");
    return (unsigned char)sum;  // Convert back to unsigned char before returning
}
void printBinary(unsigned int num, int numBits)
{
    int i;
    int startPrinting = 0; // Flag to determine when to start printing
    for (i = numBits - 1; i >= 0; i--)
    {
        if ((num >> i) & 1)
        {
            startPrinting = 1; // Set flag when the first non-zero bit is encountered
        }
        if (startPrinting)
        {
            printf("%d", (num >> i) & 1);
        }
    }
}
unsigned char calculateOnesComplement(unsigned char num)
{
    return ~num;
}
int main()
{
    unsigned char data[100];
    int dataLength;
    printf("Enter the number of elements: ");
    scanf("%d", &dataLength);
    printf("Enter the elements (decimal):\n");
    for (int i = 0; i < dataLength; i++)
    {
        scanf("%u", &data[i]);
    }
    unsigned char sum = generateChecksum(data, dataLength);
    unsigned char checksum = calculateOnesComplement(sum);
    printf("Checksum (Decimal): %u\n", checksum);
    printf("Checksum (Binary): ");
    printBinary(checksum,8);  // Print binary representation up to 8 bits
    printf("\n");
    return 0;
}
