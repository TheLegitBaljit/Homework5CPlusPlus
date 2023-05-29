#include "doctest.h"
#include "sources/MagicalContainer.hpp"


TEST_CASE("Removing elements from the MagicalContainer") {
    // Create a container with some elements
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    // Remove an element
    container.removeElement(1);

    // Check the size of the container
    CHECK(container.size() == 2);

    // Check the elements in the container using an ascending iterator
    MagicalContainer::AscendingIterator it(container); // create an iterator for the container
    CHECK(*it == 2); ++it;
    CHECK(*it == 3); ++it;
}

// Test case for iterating over the MagicalContainer with SideCrossIterator
TEST_CASE("Iterating over the MagicalContainer with SideCrossIterator") {
// Create a container with some elements
MagicalContainer container;
container.addElement(1);
container.addElement(2);
container.addElement(3);
container.addElement(4);
container.addElement(5);

// Create a side cross iterator
    MagicalContainer::SideCrossIterator it(container); // create an iterator for the container

// Check the order of the elements
CHECK(*it == 1); ++it;
CHECK(*it == 5); ++it;
CHECK(*it == 2); ++it;
CHECK(*it == 4); ++it;
CHECK(*it == 3); ++it;

// Check that the iterator reaches the end
CHECK(it == MagicalContainer::SideCrossIterator(container, container.size()));
}

// Test case for iterating over the MagicalContainer with PrimeIterator
TEST_CASE("Iterating over the MagicalContainer with PrimeIterator") {
// Create a container with some elements
MagicalContainer container;
container.addElement(5);
container.addElement(2);
container.addElement(4);
container.addElement(1);
container.addElement(3);

// Create a prime iterator
    MagicalContainer::PrimeIterator it(container); // create an iterator for the container

// Check the order of the elements
CHECK(*it == 2); ++it;
CHECK(*it == 3); ++it;
CHECK(*it == 5); ++it;

// Check that the iterator reaches the end
CHECK(it == MagicalContainer::PrimeIterator(container, container.size()));
}

// Test case for comparing iterators of the same type
TEST_CASE("Comparing iterators of the same type") {
// Create a container with some elements
MagicalContainer container;
container.addElement(1);
container.addElement(2);
container.addElement(3);
container.addElement(4);
container.addElement(5);

// Create some iterators of different types
    MagicalContainer::AscendingIterator it1(container); // points to 1
    MagicalContainer::AscendingIterator it2(container, 2); // points to 3
    MagicalContainer::SideCrossIterator it3(container); // points to 1
    MagicalContainer::SideCrossIterator it4(container, 4); // points to 3
    MagicalContainer::PrimeIterator it5(container); // points to 2
    MagicalContainer::PrimeIterator it6(container, 3); // points to 5

// Check the equality and inequality operators
CHECK(it1 == it1);
CHECK(it1 != it2);
CHECK(it3 == it3);
CHECK(it3 != it4);
CHECK(it5 == it5);
CHECK(it5 != it6);

// Check the less than and greater than operators
CHECK(it1 < it2);
CHECK(it2 > it1);
CHECK(it3 < it4);
CHECK(it4 > it3);
CHECK(it5 < it6);
CHECK(it6 > it5);
}

