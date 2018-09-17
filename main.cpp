//
//  main.cpp
//  CircularLinkedList
//
//  Created by Kevin Nguyen on 9/11/18.
//  Copyright © 2018 Kevin Nguyen. All rights reserved.
//

#include <iostream>

template<class T>
struct node {
    T data;
    node<T> *next;
};

template<class T>
class list {
    private:
        node<T> *head;
        node<T> *tail;
    public:
        list();
//        ~list();
        void add(T input);
        void deleteAtPosition(int id);
        void print();
        int count();
};

template<class T>
list<T>::list() {
    head = nullptr;
    tail = head;
}

//template<class T>
//list<T>::~list() {
//    node<T> *current;
//    current = new node<T>;
//    while(head) {
//        current = head->next;
//        delete head;
//        head = current;
//    }
//}

template <class T>
void list<T>::add(T input) {
    node<T> *newNode = new node<T>;
    newNode = new node<T>;
    newNode->data = input;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        node<T> *temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next= head;
    }

}

template<class T>
void list<T>::print() {
    node<T> *current;
    current = head;
    if (head == nullptr) {
        std::cout << "empty";
        return;
    } else {
        do {
            std::cout << current->data;
            current = current->next;
        } while (current != head);
    }
    
}

template <class T>
int list<T>::count() {
    node<T> *current;
    current = head;
    int count = 0;

    if (head != nullptr) {
        do {
            current = current->next;
            count++;
        } while (current != head);
    }
    return count;
}

template<class T>
void list<T>::deleteAtPosition(int position) {
    node<T> *current;
    node<T> *previous;
    // if the node is empty
    if (head == nullptr) {
        return;
    }
    current = head;
    // if the their is only one element in the list
    if(current->next == head) {
        head = nullptr;
        free(current);
        return;
    }
    // if their is more than one element in the list
    int count = 0;
    do {
        previous = current;
        current = current->next;
        count++;
    } while (count != position);
    previous->next = current->next;
    delete current;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    list<char> myList;
    std::string input = "Computer Science";
    for (int i = 0; i < input.length(); i++) {
        myList.add(input.at(i));
        
    }
    int counter = myList.count();
    std::cout << counter << std::endl;
    int count = 0;
    while(counter > 1) {
        for (int i = 1; i < myList.count(); i += 1) {
            myList.deleteAtPosition(i);
        }
        counter = myList.count();
        count++;
    }
    
    if(counter == 1) {
        myList.deleteAtPosition(0);
        count++;
    }
    
    myList.print();
    std::cout << "\n";

    std::cout << "iterations " << count <<  std::endl;

}
