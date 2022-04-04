import java.util.Random;

/*

Name : Zach Pownell
Description : QuickSort sorting algorithm written in Java.

 */

public class QuickSort {


    static int[] ourArray = new int[20];


    // Add Array Elements method to add 20 random elements ranging from 0-100.
    static void addArrayElements() {

        for (int i = 0 ; i < ourArray.length ; i ++) {

            ourArray[i] = new Random().nextInt(100);

        }

    }


    // Swap method to swap two elements in an array.
    static void swap(int[] array, int i, int j) {

        // Assign temp to element at array[i]. Assign array[i] to array[j], and array[j] to temp (previous array[i]).
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;

    }


    // Partition method.
    static int partition(int[] array, int low, int high) {

        int pivot = array[high];
        int i = (low - 1);

        for (int j = low ; j <= high ; j ++) {

            if (array[j] < pivot) {

                i ++;
                swap(array, i, j);

            }

        }

        swap(array, i + 1, high);
        return (i + 1);

    }


    // Our main Quick Sort function.
    static void quickSort(int[] array, int low, int high) {

        if (low < high) {

            int partitionIndex = partition(array, low, high);
            quickSort(array, low, partitionIndex - 1);
            quickSort(array, partitionIndex + 1, high);

        }

    }


    // Print Array method to print our array that is being called.
    static void printArray(int[] array) {

        for (int i : array) System.out.print(i + " ");
        System.out.println();

    }


    public static void main(String[] args) {

        // Add our random elements.
        addArrayElements();

        // Print our unsorted array.
        System.out.println("Unsorted Array: " );
        printArray(ourArray);

        // Let's call the quickSort method to sort our array.
        quickSort(ourArray, 0, ourArray.length - 1);

        // Print our sorted array.
        System.out.println("Sorted Array using QuickSort: ");
        printArray(ourArray);

    }


}
