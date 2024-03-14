#ifndef QUEUE_HPP
#define QUEUE_HPP

struct Message
{
    int destination;
    char payload[6];
    Message()
    {
        destination = -1;
    }
};

class Ring
{
    int head = 0, tail = 0;
    Message messageQueue[6];
    bool isEmpty() const;
    bool isFull() const;
    bool changeLength(bool);
    bool printMessageData(const Message*) const;
public:
    bool enqueue(Message &);
    bool dequeue(Message &);
    bool echo() const;
    bool getLength(int &) const;
    bool getHead(Message &);
    bool getTail(Message &);
};

#endif // QUEUE_HPP
