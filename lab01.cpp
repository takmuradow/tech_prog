#include <iostream>

template <class T>
struct Node
{               
    T data;     
    Node *next; 

    Node(T value) : data(value), next(nullptr) {} 
};

template <class T>
class LinkedList
{
private:
    Node<T> *head; 

public:
    LinkedList() : head(nullptr) {}


    void addFirst(T value)
    {
        Node<T> *newNode = new Node<T>(value); 
        newNode->next = head;                  
        head = newNode;                        
    }

    
    void addByIndex(int index, T value)
    {
        if (index < 0)
        { 
            std::cout << "Индекс не должен быть отрицательным" << std::endl;
            return;
        }

        if (index == 0)
        { 
            addFirst(value);
            return;
        }

        Node<T> *newNode = new Node<T>(value); 
        Node<T> *cursor = head;               
        for (int i = 0; i < index - 1 && cursor != nullptr; i++)
        { 
            cursor = cursor->next;
        }

        if (cursor == nullptr)
        { 
            std::cout << "Индекс вышел за пределы списка" << std::endl;
            return;
        }

        newNode->next = cursor->next; 
        cursor->next = newNode;
    }

    
    void addLast(T value)
    {
        Node<T> *newNode = new Node<T>(value); 
        if (head == nullptr)
        { 
            head = newNode;
            return;
        }

        Node<T> *cursor = head; 
        while (cursor->next != nullptr)
        { 
            cursor = cursor->next;
        }

        cursor->next = newNode; 
    }

   
    void deleteFirst()
    {
        if (head == nullptr)
        { 
            std::cout << "Список пуст" << std::endl;
            return;
        }

        Node<T> *temp = head; 
        head = head->next;    
        delete temp;        
    }


    void deleteLast()
    {
        if (head == nullptr)
        {
            std::cout << "Список пуст" << std::endl;
            return;
        }

        if (head->next == nullptr)
        {                   
            delete head;    
            head = nullptr; 
            return;
        }

        Node<T> *cursor = head;
        while (cursor->next->next != nullptr)
        { 
            cursor = cursor->next;
        }

        delete cursor->next;    
        cursor->next = nullptr; 
    }

    
    void deleteAtIndex(int index)
    {
        if (index < 0)
        { 
            std::cout << "Индекс не должен быть отрицательным" << std::endl;
            return;
        }

        if (index == 0)
        { 
            deleteFirst();
            return;
        }

        Node<T> *cursor = head; 
        for (int i = 0; i < index - 1 && cursor != nullptr; i++)
        { 
            cursor = cursor->next;
        }

        if (cursor == nullptr || cursor->next == nullptr)
        { 
            std::cout << "Индекс вышел за пределы списка" << std::endl;
            return;
        }

        Node<T> *temp = cursor->next;       
        cursor->next = cursor->next->next; 
        delete temp;                         
    }

    
    void updateAtIndex(int index, T value)
    {
        if (index < 0)
        {
            std::cout << "Индекс не должен быть отрицательным";
            return;
        }

        Node<T> *cursor = head;
        for (int i = 0; i < index && cursor != nullptr; i++)
        { 
            cursor = cursor->next;
        }

        if (cursor == nullptr)
        {
            std::cout << "Индекс вышел за пределы списка" << std::endl;
            return;
        }

        cursor->data = value; 
    }

    
    T findByIndex(int index)
    {
        if (index < 0)
        {
            std::cout << "Индекс не должен быть отрицательным" << std::endl;
            return T();
        }

        Node<T> *cursor = head;
        for (int i = 0; i < index && cursor != nullptr; i++)
        { 
            cursor = cursor->next;
        }

        if (cursor == nullptr)
        {
            std::cout << "Индекс вышел за пределы списка" << std::endl;
            return T();
        }

        return cursor->data; 
    }
};

int main()
{
    LinkedList<int> list; 
    list.addFirst(7);      
    list.addLast(4);
    list.addLast(5); 
    list.addByIndex(1, 1);
    list.addByIndex(2, 10);

    
    std::cout << "Список: ";
    for (int i = 0; i < 4; i++)
    {
        std::cout << list.findByIndex(i) << " ";
    }
    std::cout << std::endl;

    list.updateAtIndex(1, 4); 
    list.deleteLast();        

    
    std::cout << "Новый список: ";
    for (int i = 0; i < 4; i++)
    {
        std::cout << list.findByIndex(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
