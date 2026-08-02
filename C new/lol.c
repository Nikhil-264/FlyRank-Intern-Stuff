#include <stdio.h>
#include <windows.h> // for Sleep()

int main()
{
    Sleep(4000); // wait for 4 seconds
    int count = 0;
    while (count <= 100)
    {
        printf("I will win %d\n", count);
        // Simulate pressing the "Enter" key
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = VK_RETURN;
        input.ki.dwFlags = 0;
        SendInput(1, &input, sizeof(INPUT));
        Sleep(100); // wait for a short time to avoid spamming too quickly
        count++;
    }
    return 0;
}