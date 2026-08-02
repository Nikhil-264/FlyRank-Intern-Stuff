// An Internet Protocol address (IP address) is a numerical label assigned to each device connected
// to a computer network that uses the Internet Protocol for communication. Internet Protocol version
// 4 (IPv4) defines an IP address as a 32-bit number. IP addresses are written and displayed in
// standard notations, such as 172.16.254.1, where the 32-bit number is broken into 4 bytes, separated
// by dots, and each byte is written in decimal. For example, the IP address 172.16.254.1 consists of
// the four decimal numbers, 172, 16, 254, and 1. The corresponding 32-bit binary address is:

// 10101100 00010000 11111110 00000001

// For a hierarchical implementation of the internet, the IP address is viewed as a concatenation of a
// network address and a host address. For example, if the most significant 18 bits are treated as the
// network address, then the remaining 14 bits give us the host address. In this case, for the IP address
// 172.16.254.1, we have the following:

// IP Address: 10101100 00010000 11111110 00000001
// Network Address: 10101100 00010000 11000000 00000000
// Host Address: 00000000 00000000 00111110 00000001

// This network address (in standard notation) is 172.16.192.0, and the host address is 0.0.62.1.
// Write a program that does the following:
// (a) It reads an IP address (such as 144.16.192.44) and prints the binary 32-bit address with a blank
// space separating each byte. [5 marks]
// (b) It reads the network address (in standard notation) from the command-prompt, and then prints
// the network address and host address (in standard notation) corresponding to the IP address
// read earlier.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decimaltobinary(int decimal)
{
    char *binary = (char *)malloc(9 * sizeof(char));
    // itoa(decimal, binary, 2);: This line converts the decimal number to a binary string using the itoa function. The itoa function takes three arguments: the decimal value to convert (decimal), the character array to store the result (binary), and the base of the conversion, which is 2 for binary
    itoa(binary, decimal, 2);
    // memmove(binary + 1, binary, len + 1);: This line moves the characters in the binary string one position to the right. It uses the memmove function to safely move the characters, including the null terminator.
    for (int i = strlen(binary); i < 8; i++)
    {
        memmove(binary + 1, binary, strlen(binary) + 1);
        binary[0] = '0';
    }
    return binary;
}

int main(int argc, char const *argv[])
{
    printf("Enter the IP address is usual : ");
    char IPaddress[16];
    scanf("%s", &IPaddress);
    return 0;
}
