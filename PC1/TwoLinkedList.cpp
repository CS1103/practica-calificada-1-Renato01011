//
// Created by ruben on 4/12/19.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "TwoLinkedList.h"
namespace UTEC {

    Node::Node(int _Value){

        Value = _Value;
        next = nullptr;

    }

    TwoLinkedList::TwoLinkedList() {

        head1 = nullptr; head2 = nullptr; tail = nullptr; tail1 = nullptr; tail2 = nullptr;

    }

    TwoLinkedList::~TwoLinkedList() {

        for (Node *i = head1; i != tail1->next;) {
            Node* Temp = i;
            i = i->next;
            delete Temp;
            Temp = nullptr;
        }
        for (Node *i = head2; i != nullptr;) {
            Node* Temp = i;
            if(i == tail) {delete i; i = nullptr;}
            else {
                i = i->next;
                delete Temp;
                Temp = nullptr;
            }
        }

    }

    void TwoLinkedList::push_back1(int Value) {
        Node* NewNode = new Node(Value);
        if(head1 == nullptr && tail1 == nullptr) {
            head1 = NewNode;
            head1->next = tail1;
            tail1 = NewNode;
        }
        else if (is_combined) {
            tail->next = NewNode;
            tail = NewNode;
        }
        else {
            tail1->next = NewNode;
            tail1 = NewNode;
        }
    }

    void TwoLinkedList::push_back2(int Value) {
        Node* NewNode = new Node(Value);
        if(head2 == nullptr && tail2 == nullptr) {
            head2 = NewNode;
            head2->next = tail1;
            tail2 = NewNode;
        }
        else if (is_combined) {
            tail->next = NewNode;
            tail = NewNode;
        }
        else {
            tail2->next = NewNode;
            tail2 = NewNode;
        }

    }

    std::string TwoLinkedList::merge(int Value) {

        if(is_combined) {
            return "Operación duplicada";
        }
        else {
            Node* NewNode = new Node(Value);
            tail1->next = NewNode;
            tail2->next = NewNode;
            tail = NewNode;
            is_combined = true;
            return "Operación Exitosa";
        }

    }

    bool TwoLinkedList::is_merged() {

        if(is_combined) {return true;}
        else {return false;}

    }

    std::string TwoLinkedList::getlist(int Condition) {
        std::string Return;
        if(Condition == 1) {
            for(Node* i = head1; i != tail1->next; i = i->next){
                Return += std::to_string(i->Value) + " ";
            }
            return Return;
        }
        else if(Condition == 2) {
            for(Node* i = head2; i != tail2->next; i = i->next){
                Return += std::to_string(i->Value) + " ";
            }
            return Return;
        }
        else if(Condition == 0) {
            if(!is_combined) {return Return;}
            else {
                for(Node* i = tail1->next; i != tail; i = i->next){
                    Return += std::to_string(i->Value) + " ";
                }
                Return += std::to_string(tail->Value) + " ";
                return Return;
            }
        }

    }

    Node* TwoLinkedList::search(int Value) {

        for(Node* i = head1; i != tail; i = i->next) {
            if(i->Value == Value) {return i;}
        }
        for(Node* i = head2; i != tail; i = i->next) {
            if(i->Value == Value) {return i;}
        }
        if(Value == tail->Value) {return tail;}
        else {return nullptr;}

    }

    void TwoLinkedList::save(std::string file_name) {

        std::ofstream Archivo(file_name);
        if(!Archivo.is_open()) {std::cout << "ERROR: Archivo Output no se pudo abrir";}
        std::string Return;

        for(Node* i = head1; i != tail1->next; i = i->next){
            Archivo << std::to_string(i->Value) + ",";
        }
        Archivo << std::endl;
        for(Node* i = head2; i != tail2->next; i = i->next){
            Archivo << std::to_string(i->Value) + ",";
        }
        Archivo << std::endl;
        for(Node* i = tail2->next; i !=tail; i = i->next)
            Archivo << std::to_string(i->Value) + ",";
        Archivo << std::to_string(tail->Value) + ",";
    }

    void TwoLinkedList::load(std::string file_name) {

        std::fstream Archivo;
        Archivo.open(file_name);
        std::string Value_first_list;
        std::string Value_second_list;
        std::string Value_third_list;
        std::stringstream First_list;
        std::stringstream Second_list;
        std::stringstream Third_list;
        std::string WordTemp;
        int intTemp;

        getline(Archivo, Value_first_list, '\n');
        getline(Archivo, Value_second_list, '\n');
        getline(Archivo, Value_third_list, '\n');


        First_list.str(Value_first_list);
        Second_list.str(Value_second_list);
        Third_list.str(Value_third_list);

        while(First_list.good()) {
            getline(First_list, WordTemp, ',');
            intTemp = atoi(WordTemp.c_str());
            std::cout << intTemp;
            push_back1(intTemp);
        }

        while(Second_list.good()) {
            getline(Second_list, WordTemp, ',');
            intTemp = atoi(WordTemp.c_str());
            push_back2(intTemp);
        }

        getline(Third_list, WordTemp, ',');
        intTemp = atoi(WordTemp.c_str());
        merge(intTemp);

        while(Third_list.good()) {
            getline(Third_list, WordTemp, ',');
            intTemp = atoi(WordTemp.c_str());
            push_back1(intTemp);
        }

    }


}