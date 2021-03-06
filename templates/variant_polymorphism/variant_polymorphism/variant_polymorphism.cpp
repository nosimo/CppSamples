// variant_polymorphism.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <variant>
#include <string>
#include <vector>
#include <memory>

struct Base {
public:
    Base() :  _str() {}
    virtual ~Base() {}

    std::string GetString() const { return _str; }
    // non virtual
    void Run() { _str = "Base"; }

protected:
    std::string _str;
};

struct DerivedA : public Base {
public:
    void Run() { _str = "DerivedA"; }
};

struct DerivedB : public Base {
public:
    void Run() { _str = "DerivedB"; }
};

class Holder {
public:
    template<class T>
    explicit Holder(const T& oth) { _value = oth; }

public:
    Base& GetBase() {
        return std::visit([](auto&& x) -> Base& { return static_cast<Base&>(x); }, _value);
    }
    std::string GetString() { return GetBase().GetString(); }

    void Run() {
        std::visit([](auto&& x) { x.Run(); }, _value);
    }

private:
    using VariantType = std::variant<Base, DerivedA, DerivedB>;
    VariantType _value;

};


int main()
{
    using HolderPtr = std::unique_ptr<Holder>;
    using HolderArray = std::vector<HolderPtr>;

    HolderArray arr;
    arr.emplace_back(std::make_unique<Holder>(Holder(Base{})));
    arr.emplace_back(std::make_unique<Holder>(Holder(DerivedA{})));
    arr.emplace_back(std::make_unique<Holder>(Holder(DerivedB{})));

    for (HolderArray::iterator itr = arr.begin(); itr != arr.end(); ++itr) {
        HolderPtr& ptr = (*itr);
        ptr->Run();
        std::cout << ptr->GetString() << std::endl;
    }

    return 0;
}

