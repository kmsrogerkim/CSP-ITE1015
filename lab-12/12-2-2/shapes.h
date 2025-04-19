#ifndef __SHAPES_H__
#define __SHAPES_H__
#include <iostream>
using namespace std;

template <class T>
class Node 
{
public:
    T data;
    Node<T>* next;
};

template <class T>
class List 
{
    private:
        Node<T>* head;
    public:
        List() 
        { 
            head = nullptr; // Initialize the head to nullptr
        }
        ~List() 
        { 
            // Destructor implementation to free memory
            Node<T>* current = head;
            while (current != nullptr) 
            {
                Node<T>* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
        List(T* arr, int n_nodes) 
        { 
            // Create a list with n_nodes
            head = nullptr;
            Node<T>* tail = nullptr;

            for (int i = 0; i < n_nodes; ++i) 
            {
                Node<T>* newNode = new Node<T>();
                newNode->data = arr[i];
                newNode->next = nullptr;

                if (head == nullptr) 
                {
                    head = newNode; // First node
                    tail = newNode; // Tail points to the first node
                } 
                else 
                {
                    tail->next = newNode; // Link new node
                    tail = newNode; // Move tail to the new node
                }
            }
        }

        void insert_at(int idx, const T& data) 
        { 
            Node<T>* new_node = new Node<T>();
            new_node->data = data;
            if (idx == 0) 
            {
                new_node->next = head;
                head = new_node;
                return;
            }

            Node<T>* node = head; 
            // untill previous 
            for (int i = 0; i < idx - 1; i++)
            {
                node = node->next;
            }

            new_node->next = node->next;
            node->next = new_node;
        }

        void remove_at(int idx) 
        { 
            if (idx < 0 || head == nullptr) return; // Invalid index or empty list

            Node<T>* node = head; 
            if (idx == 0) 
            {
                head = head->next;
                delete node;
                return;
            }

            Node<T>* previous_node = nullptr;
            for (int i=0; i < idx; i++)
            {
                previous_node = node;
                node = node->next; 
            }  
            previous_node->next = node->next;
            delete node;
        }

        void pop_back() 
        { 
            if (head->next == nullptr) 
            {
                delete head; 
                head = nullptr;
                return;
            }

            Node<T>* node = head; 
            Node<T>* previous_node;
            while (node->next)
            {
                previous_node = node;
                node = node->next;
            }
            previous_node->next = nullptr;
            delete node;
        }

        void push_back(const T& val) 
        { 
            Node<T>* new_node = new Node<T>();
            new_node->data = val;
            new_node->next = nullptr;
            if (head == nullptr) 
            {
                head = new_node; // List was empty
                return;
            }

            Node<T>* node = head; 
            while (node->next)
            {
                node = node->next;
            }
            node->next = new_node;
        }

        void pop_front() 
        { 
            Node<T>* new_head = head->next;
            delete head;
            head = new_head;
        }

        void push_front(const T& val) 
        { 
            Node<T>* new_head = new Node<T>();
            new_head->next = head;
            new_head->data = val;
            head = new_head;
        }

        template <class U>
        friend std::ostream& operator<<(std::ostream& out, List<U>& rhs);
};

template <class T>
ostream& operator<< (ostream& out, List<T>& rhs)
{
    Node<T>* current = rhs.head; 
    while (current != nullptr) 
    {
        out << current->data; // Output the data of the current node
        
        current = current->next; // Move to the next node

        if (current != nullptr) 
        {
            out << ","; // Add a comma if there are more nodes
        }
    }
    return out; // Return the output stream
};
#endif