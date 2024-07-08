#include <iostream>
#include "Vector.h"
#include <vector>

int main() {

    Vector<int> v1;
    for (int j = 0; j < 10; ++j) {
        v1.push_back(j);
    }


    Vector<int> vInitSize(3);
    for (int j = 0; j < 10; ++j) {
        vInitSize.push_back(j);
    }
    std::cout << "\nporownanie rozmiaru i pojemnosci, v1 i vInitSize\n" << v1.size() << " " << v1.capacity() <<
            "  |  " << vInitSize.size() << " " << vInitSize.capacity() << std::endl;


    std::cout << "\nvInitSize przed insert x3\n";
    for (const auto& el : vInitSize){std::cout << el << " ";}
    vInitSize.insert(3, 21);
    std::cout << "\nvInitSize po insert\n";
    for (const auto& el : vInitSize){std::cout << el << " ";}
    vInitSize.insert(vInitSize.begin() + 3, 27);
    std::cout << "\n";
    for (const auto& el : vInitSize){std::cout << el << " ";}
    vInitSize.insert(3, 37);
    std::cout << "\n";
    for (const auto& el : vInitSize){std::cout << el << " ";}

    std::cout << "\nrozmiar i pojemnosc vInitSize: " << vInitSize.size() << " " << vInitSize.capacity() << std::endl;


    auto found1 = vInitSize.find(2136);
    auto found2 = vInitSize.find(21);
    if (found1 != nullptr) {std::cout << "\n found1: " << *found1 << "\n";}
    if (found2 != nullptr) {std::cout<< "\n found2: " << *found2 << "\n";}

    std::cout << "\nvInitSize przed erase \n";
    for (const auto& el : vInitSize){std::cout << el << " ";}
    vInitSize.erase(vInitSize.find(6));
    std::cout << "\nvInitSize po erase \n";
    for (const auto& el : vInitSize){std::cout << el << " ";}
    vInitSize.erase(vInitSize.begin()+3);
    std::cout << "\n";
    for (const auto& el : vInitSize){std::cout << el << " ";}
    vInitSize.erase(3);
    std::cout << "\n";
    for (const auto& el : vInitSize){std::cout << el << " ";}
    //vInitSize.erase(vInitSize.begin()+11); // vInitSize.begin()+11 = end() więc error

    std::cout << "\nrozmiar i pojemnosc vInitSize: " << vInitSize.size() << " " << vInitSize.capacity() << std::endl;

    //spr iter
    //for (const auto& el : vInitSize) { el *= 2;} //error
    for (auto& el : vInitSize) { el *= 2;}

    vInitSize.clear();
    std::cout << "\nvInitSize po clear \n";
    for (const auto& el : vInitSize){std::cout << el << " ";}
    std::cout << "\nrozmiar i pojemnosc vInitSize: " << vInitSize.size() << " " << vInitSize.capacity() << std::endl;

    Vector<Vector<int>> v2d;
    for (int i = 0; i < 10; ++i) {
        Vector<int> temp;
        for (int j = 0; j < 10; ++j) {
            temp.push_back(i+j);
        }
        v2d.push_back(temp);
    }


    std::cout << "\nv2d przed pop_back i erase(5)\n";
    for (const auto& v : v2d) {
        for (const auto& el : v) { std::cout << el << " ";}
        std::cout  << "\n";
    }

    v2d.erase(5);
    v2d.pop_back();

    std::cout << "\nv2d po pop_back i erase(5)\n";
    for (const auto& v : v2d) {
        for (const auto& el : v) { std::cout << el << " ";}
        std::cout  << "\n";
    }




    //Dodatkowe
    vInitSize.pop_back();
    std::cout << "\nv1 przed pop_back\n";
    for (const auto& el : v1) { std::cout << el << " ";}
    v1.pop_back();
    std::cout << "\nv1 po pop_back\n";
    for (const auto& el : v1) { std::cout << el << " ";}
    std::cout << "\nv1 at(1): " << v1.at(1);
//    std::cout << "\nv1 at(27): " << v1.at(27); //Index out of range



    //Testowanie działania

    {
        std::cout << "\ncapacity i size\n";
        std::vector<int> v;
        Vector<int> v1;
        for (int i = 0; i < 15; ++i){
            //std::cout << v.capacity() << " " << v.size() << std::endl;
            std::cout << v1.capacity() << " " << v1.size() << std::endl;
            v.push_back(27+i);
            v1.push_back(27+i);
        }
        //std::cout << v1.at(2000) << std::endl; //terminate called after throwing an instance of 'std::out_of_range'
        //  what():  Index out of range
        std::cout << v1[15] << std::endl;

        //Vector<int> vCopied;
        //vCopied = v1;
        Vector<int> vCopied(v1);

        if (v1 == vCopied) std::cout << "coping and == OK\n";
        v1.push_back(2137);
        if (v1 == vCopied) std::cout << "== NOT OK\n";
        if (v1 != vCopied) std::cout << "!= OK\n";

        for (int i = 0; i < 10; ++i) {
            std::cout << vCopied[i] << " ";
        }
        std::cout << "\n";

        std::cout  << "Move\n";
        //Vector<int> vMove = std::move(v1);
        Vector<int> vMove;
        vMove = std::move(v1);
        for (int i = 0; i < 11; ++i) {
            std::cout << vMove[i] << " ";
            //std::cout << v1[i] << "\n"; //error, OK
        }
        std::cout << "\n";

        std::cout << "auto loop\n";
        for (auto i : vMove) {
            std::cout << i << " ";
        }
        std::cout << "\n";

        std::cout << "vMove przed pop\n";
        for (auto i : vMove) {
            std::cout << i << " ";
        }
        std::cout << "\n";

        vMove.pop_back();
        std::cout << "vMove po pop, i potem pop wszystko\n";
        for (auto i : vMove) {
            std::cout << i << " ";
            vMove.pop_back();
        }
        std::cout << "\n";

        std::cout << vMove.capacity() << " " << vMove.size() << std::endl;
        std::cout << v.capacity() << " " << v.size() << std::endl;

        std::cout << "v przed inset\n";
        for (auto i : v) {std::cout << i << " ";}
        std::cout << "\n";

        std::cout << v.capacity() << " " << v.size() << std::endl;
        v.insert(v.begin()+2, 7);
        v.insert(v.begin()+2, 8);
        std::cout << v.capacity() << " " << v.size() << std::endl;
        std::cout << "v po inset\n";
        for (auto i : v) {std::cout << i << " ";}\
        std::cout << "\n";

        std::cout << vCopied.capacity() << " " << vCopied.size() << std::endl;
        vCopied.push_back(11);
        std::cout << "\nvCopied przed inset\n";
        for (auto i : vCopied) {std::cout << i << " ";}
        vCopied.insert(7, 8);
        std::cout << "\nvCopied po inset\n";
        for (auto i : vCopied) {std::cout << i << " ";}

        std::cout << "\n" << vCopied.capacity() << " " << vCopied.size() << std::endl;
        vCopied.insert(3, 2);
        std::cout << vCopied.capacity() << " " << vCopied.size() << std::endl;
        std::cout << "\nvCopied po insetv2\n";
        for (auto i : vCopied) {std::cout << i << " ";}
        vCopied.insert(vCopied.begin() + 3, 1);
        std::cout << "\nvCopied po inset it\n";
        for (auto i : vCopied) {std::cout << i << " ";}

        //v.clear();
        //for (auto i : v) {std::cout << i << " ";}
        //std::cout << "\n" << v.capacity() << " " << v.size() << std::endl;

        //std::cout << "\n";
        //for (auto i : v) {std::cout << i << " ";}
        //std::cout << "\n" << v.capacity() << " " << v.size() << std::endl;
        //v.erase(v.begin()+16);
        //for (auto i : v) {std::cout << i << " ";}
        //std::cout << "\n" << v.capacity() << " " << v.size() << std::endl;


        std::cout << "\nvCopied po erese it\n";
        std::cout << "\n" << vCopied.capacity() << " " << vCopied.size() << std::endl;
        vCopied.erase(vCopied.begin()+2);
        for (auto i : vCopied) {
            std::cout << i << " ";
        }
        std::cout << "\n" << vCopied.capacity() << " " << vCopied.size() << std::endl;

        vCopied.erase(vCopied.find(33));
        for (auto i : vCopied) {
            std::cout << i << " ";
        }

        std::cout << "\n" << vCopied.capacity() << " " << vCopied.size() << std::endl;
        vCopied.clear();
        for (auto i : vCopied) {
            std::cout << i << " ";
        }
        std::cout << "\n" << vCopied.capacity() << " " << vCopied.size() << std::endl;
    }

    return 0;
}
