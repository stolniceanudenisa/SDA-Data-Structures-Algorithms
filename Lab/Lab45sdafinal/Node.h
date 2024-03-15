#pragma once
 
template <typename T>
class List;

template <class T>
class Node {
private:
    Node<T>* previous;
    T info;
    Node<T>* next;
public:
    Node(Node<T>* back, T info, Node<T>* next) : info(info), next(next), previous(back) {}
    Node(T info) : info(info) { next = nullptr, previous = nullptr; }
    T getInfo();
    friend class List<T>;
};

template<class T>
T Node<T>::getInfo() {
    return info;
}

 