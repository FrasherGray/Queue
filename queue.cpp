#include "queue.hpp"
#include <iostream>

bool Ring::isEmpty() const
{
    if (head == tail && messageQueue[head].destination == -1)
    {
        return true;
    }
    return false;
}

bool Ring::isFull() const
{
    if (head == tail && messageQueue[head].destination != -1)
    {
        return true;
    }
    return false;
}

bool Ring::changeLength(bool isHead)
{
    if (isHead)
    {
        if (head == 5)
        {
            head = 0;
        }
        else
        {
            head += 1;
        }
        return true;
    }
    if (tail == 5)
    {
        tail = 0;
    }
    else
    {
        tail += 1;
    }
    return true; //technically useless, but you have talked about how you hate void functions
}

bool Ring::printMessageData(const Message *messageToPrint) const
{
    std::cout << "Destination: " << messageToPrint->destination << ", Message: " << messageToPrint->payload[0] << messageToPrint->payload[1]
               << messageToPrint->payload[2] << messageToPrint->payload[3] << messageToPrint->payload[4] << messageToPrint->payload[5] << "\n";
}

bool Ring::enqueue(Message &messageToAdd)
{
    if (isFull())
    {
        return false;
    }
    messageQueue[tail] = messageToAdd;
    changeLength(false);
    return true;
}

bool Ring::dequeue(Message &packageMessage)
{
    if (isEmpty())
    {
        return false;
    }
    packageMessage = messageQueue[head];
    messageQueue[head].destination = -1;
    changeLength(true);
    return true;
}

bool Ring::echo() const
{
    int length, finalIValue, fullQueueBuffer = 0;
    getLength(length);
    finalIValue = (head + length) % 6;
    if (isFull())
    {
        printMessageData(&messageQueue[finalIValue]);
        if (head == 5)
        {
            fullQueueBuffer -= 5;
        }
        else
        {
            fullQueueBuffer++;
        }
    }
    for (int i = (head + fullQueueBuffer); i != finalIValue; i++)
    {
        printMessageData(&messageQueue[i]);
        if (i == 5)
        {
            i = -1;
        }
    }
    std::cout << "Position of Head: " << head << ", Position of Tail: " << tail << "\n";
    return true;
}

bool Ring::getLength(int &lengthHolder) const
{
    if (isFull())
    {
        lengthHolder = 6;
    }
    else
    {
        lengthHolder = 0;
        if (!isEmpty())
        {
            for (int i = head; i != tail; i++)
            {
                lengthHolder += 1;
                if (i == 5)
                {
                    i = -1;
                }
            }
        }
    }
    return true;
}

bool Ring::getHead(Message &willBeHead)
{
    if (isEmpty())
    {
        return false;
    }
    willBeHead = messageQueue[head];
    return true;
}

bool Ring::getTail(Message &willBeTail)
{
    if (isEmpty())
    {
        return false;
    }
    willBeTail = messageQueue[(tail - 1)];
    return true;
}
