#include "MagicalContainer.hpp"

// Definitions for AscendingIterator
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
        : container(&container), index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container, size_t index)
        : container(&container), index(index) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
        : container(other.container), index(other.index) {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if(this->container!=other.container)
        throw std::runtime_error("They are not pointing to the same container");
    if(this != &other) {
        this->container = other.container;
        this->index = other.index;
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return this->index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return this->index < other.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return this->index > other.index;
}

int MagicalContainer::PrimeIterator::operator*() {
    return (*(*this->container).primes[index]);
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if(this->container->primes.size() == 0)
        throw std::runtime_error("Has no primes");
    if(index>this->container->primes.size()-1)
        throw std::runtime_error("Out of bounds");
    ++index;
    return *this;
}

// Definitions for begin and end functions for MagicalContainer
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
    return PrimeIterator((*this->container),0);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
    return PrimeIterator((*this->container), (*container).primes.size());
}