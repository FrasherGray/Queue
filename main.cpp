#include <iostream>
#include <string>
#include "queue.hpp"

using namespace std;

bool enterNewMessage(Message&);

int main()
{
    Ring ringQueue;
    char input = ' ';
    do
    {
        std::cout << "Type 'q' to quit, 'e' to enqueue a new message, 'd' to dequeue a message, and 'p' to print all queue data.\n";
        std::cin.get(input);
        std::cin.ignore(INT_MAX, '\n');
        if (input == 'e')
        {
            Message newMessage;
            enterNewMessage(newMessage);
            if (ringQueue.enqueue(newMessage))
            {
                std::cout << "Message enqueued successfully.\n";
            }
            else
            {
                std::cout << "Queue is full, cannot enqueue.\n";
            }
        }
        else if (input == 'd')
        {
            Message receivingMessage;
            if (ringQueue.dequeue(receivingMessage))
            {
                std::cout << "Dequeued successfully.\n";
            }
            else
            {
                std::cout << "No message to dequeue.\n";
            }
        }
        else if (input == 'p')
        {
            ringQueue.echo();
        }
        else if (input == 'q'){}
        else
        {
            std::cout << "Invalid input!\n";
        }
    } while (input != 'q');
    return 0;
}


bool enterNewMessage(Message &newMessage)
{
    int dest = 0;
    std::string message;
    while (dest < 1 || dest > 99)
    {
        std::cout << "Enter in the destination for the new message (between 1 and 99, inclusive):\n";
        std::cin >> dest;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }
    newMessage.destination = dest;
    std::cout << "Enter in new message: ";
    std::getline(std::cin, message);
    for (int i = 0; i < 6; i++)
    {
        try
        {
            newMessage.payload[i] = message.at(i);
        }
        catch(exception)
        {
            newMessage.payload[i] = ' ';
        }
    }
    return true;
}
