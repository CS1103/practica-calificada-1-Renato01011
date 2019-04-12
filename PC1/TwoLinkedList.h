//
// Created by ruben on 4/12/19.
//

#ifndef PC1_TWOLINKEDLIST_H
#define PC1_TWOLINKEDLIST_H

#include <string>

namespace UTEC {

    struct Node {
        Node(int _Value);
        int Value;
        Node* next;
    };

    class TwoLinkedList {
    private:
        bool is_combined = false;
        Node* head1;
        Node* head2;
        Node* tail1;
        Node* tail2;
        Node* tail;

    public:
        TwoLinkedList();
        ~TwoLinkedList();
        void push_back1(int Value);
        void push_back2(int Value);
        std::string merge(int Value);
        bool is_merged();
        std::string getlist(int Condition);
        Node* search(int Value);
        void save(std::string file_name);
        void load(std::string file_name);

    };

}

#endif //PC1_TWOLINKEDLIST_H
