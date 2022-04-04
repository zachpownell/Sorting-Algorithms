from random import randrange

#
# Name : Zach Pownell
# Description : BubbleSort sorting algorithm written in Python.
#


our_array = []


# Add Array Elements method to add 20 random elements ranging from 0-100.
def add_array_elements():

    for i in range(20):
        our_array.append(randrange(100))


# Our main Bubble Sort method. Will iterate through given array and swap when needed.
def bubble_sort(array):

    # Assigning the length of our array.
    length = len(array)

    # Let's iterate through all elements in the array.
    for i in range(length - 1):

        # Let's now iterate through the array from 0 to length - i - 1.
        for j in range(0, length - i - 1):

            # If the element found is greater than the next element, swap.
            if array[j] > array[j + 1]:

                array[j], array[j + 1] = array[j + 1], array[j]


# Add our random elements.
add_array_elements()

print("Unsorted Array: ")
print(our_array)

bubble_sort(our_array)

print("Sorted Array using BubbleSort: ")
print(our_array)
