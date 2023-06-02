#include "MagicalContainer.hpp"

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
        : container(&container), index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container, size_t index)
        : container(&container), index(index) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : container(other.container), index(other.index) {}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if(this->container!=other.container)
        throw std::runtime_error("They are not pointing to the same container");
    if(this != &other) {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return this->index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return this->index < other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return this->index > other.index;
}

int MagicalContainer::AscendingIterator::operator*() {
    return (*container).container[index];
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    if(index>this->container->size()-1)
        throw std::runtime_error("Out of bounds");
    ++index;
    return *this;
}

// Definitions for begin and end functions for MagicalContainer
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
    return AscendingIterator(*(this->container),0);
}


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
    return AscendingIterator(*(this->container), (*container).size());
}