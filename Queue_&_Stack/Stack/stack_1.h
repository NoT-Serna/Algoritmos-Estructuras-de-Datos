#ifndef STACK_H
#define STACK_H

#include <vector>
#include <list>
#include <memory>

template <typename ValueType>
class StackImpl {
public:
    virtual ~StackImpl() = default;
    virtual void push(const ValueType& value) = 0;
    virtual ValueType pop() = 0;
    virtual ValueType top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual size_t size() const = 0;
};

template <typename ValueType>
class ArrayStack : public StackImpl<ValueType> {
private:
    std::vector<ValueType> arrayImpl;
public:
    void push(const ValueType& value) override {
        arrayImpl.push_back(value);
    }
    ValueType pop() override {
        ValueType value = arrayImpl.back();
        arrayImpl.pop_back();
        return value;
    }
    ValueType top() const override {
        return arrayImpl.back();
    }
    bool isEmpty() const override {
        return arrayImpl.empty();
    }
    size_t size() const override {
        return arrayImpl.size();
    }
};

template <typename ValueType>
class ListStack : public StackImpl<ValueType> {
private:
    std::list<ValueType> listImpl;
public:
    void push(const ValueType& value) override {
        listImpl.push_back(value);
    }
    ValueType pop() override {
        ValueType value = listImpl.back();
        listImpl.pop_back();
        return value;
    }
    ValueType top() const override {
        return listImpl.back();
    }
    bool isEmpty() const override {
        return listImpl.empty();
    }
    size_t size() const override {
        return listImpl.size();
    }
};

template <typename ValueType>
class Stack {
private:
    std::unique_ptr<StackImpl<ValueType>> impl;
public:
    enum class ImplementationType {
        ARRAY_IMPL,
        LIST_IMPL
    };

    Stack(ImplementationType type = ImplementationType::ARRAY_IMPL) {
        if (type == ImplementationType::ARRAY_IMPL) {
            impl = std::make_unique<ArrayStack<ValueType>>();
        } else {
            impl = std::make_unique<ListStack<ValueType>>();
        }
    }

    void push(const ValueType& value) {
        impl->push(value);
    }

    ValueType pop() {
        return impl->pop();
    }

    ValueType top() const {
        return impl->top();
    }

    bool isEmpty() const {
        return impl->isEmpty();
    }

    size_t size() const {
        return impl->size();
    }
};

#endif // STACK_H
