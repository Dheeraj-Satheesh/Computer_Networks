#include <stdio.h>

void printBinary(unsigned int num, int numBits)
{
    for (int i = numBits - 1; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

unsigned char generateChecksum(const unsigned char *data, int length)
{
    unsigned int sum = 0; // Use an unsigned int to accommodate larger values
    int i;
    for (i = 0; i < length; i++)
    {
        sum += data[i]; // Accumulate the sum of the data elements
    }
    unsigned int actualSum = sum;             // Store the actual sum before wrapping
    printf("\nSum (Decimal): %u\n", actualSum); // Print the actual sum
    printf("Sum (Binary): ");
    printBinary(actualSum,10); // Print binary representation up to 8 bits
    if (sum > 255)              // Wrap the sum if it is greater than 255
    {
        sum = (sum & 0xFF) + (sum >> 8); // Add the carry bits to the sum
        printf("\nWrapped Sum (Decimal): %u\n", sum); // Print the wrapped sum
        printf("Wrapped Sum (Binary): ");
        printBinary(sum,8); // Print binary representation of the wrapped sum
        return (unsigned char)sum;
    }
    else
    {
        return (unsigned char)sum; // Convert back to unsigned char before returning
    }
}

unsigned char calculateOnesComplement(unsigned char num)
{
    return ~num; // Perform bitwise complement to calculate the one's complement
}

int main()
{
    unsigned char data[100];
    int dataLength;
    printf("Enter the number of elements: ");
    scanf("%d", &dataLength); // Read the number of elements from the user
    printf("Enter the elements (decimal):\n");
    for (int i = 0; i < dataLength; i++)
    {
       scanf("%u", (unsigned int *)(&data[i])); // Read each element from the user
    }
    unsigned char sum = generateChecksum(data, dataLength); // Calculate the sum of the elements
    unsigned char checksum = calculateOnesComplement(sum);  // Calculate the one's complement checksum
    printf("\nChecksum (Decimal): %u\n", checksum);           // Print the checksum in decimal format
    printf("Checksum (Binary): ");
    printBinary(checksum, 8); // Print binary representation up to 8 bits
    printf("\n");
    return 0;
}
