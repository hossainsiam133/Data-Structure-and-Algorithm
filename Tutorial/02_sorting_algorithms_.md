# Chapter 2: Sorting Algorithms

Welcome back to our journey through Data Structures and Algorithms! In our [previous chapter on Stacks](01_stack_data_structure_.md), we learned about a special way to store data where the last item in is the first item out, like a stack of plates. Now, let's explore a different, but equally important, concept: **Sorting Algorithms**.

## What Problem Do Sorting Algorithms Solve?

Imagine your bookshelf is a complete mess! Books are scattered everywhere, not in any particular order. To find a specific book quickly, you'd probably want to arrange them, maybe by author name, title, or publication date. This act of arranging items into a specific sequence is exactly what **sorting algorithms** do in the world of computers!

Think of it like this:
*   You have a list of test scores, and you want to see who got the highest. You need to sort them from highest to lowest.
*   You're looking for a product on an online store, and you want to see the cheapest ones first. You sort by price, ascending.
*   You have a list of names, and you want them in alphabetical order.

Sorting algorithms are systematic ways to arrange items in a list (like numbers in an array or names in a list) into a specific order, either **ascending** (smallest to largest, A to Z) or **descending** (largest to smallest, Z to A).

## The Idea Behind Sorting

At its core, sorting is about putting things in order. Just like you have different ways to organize your books (by color, size, author), computers have different methods, or "algorithms," to sort data.

Let's start with a very simple and intuitive sorting method called **Bubble Sort**.

## Bubble Sort: A Gentle Introduction

Imagine you have a row of bubbles in a glass, each with a number written on it: `[5, 1, 4, 2]`. You want to sort them from smallest to largest.

Bubble Sort works by repeatedly stepping through the list, comparing adjacent items, and swapping them if they are in the wrong order. Think of it like lighter bubbles "bubbling up" to their correct position.

Let's sort `[5, 1, 4, 2]` in ascending order:

**First Pass:**
1.  Compare `5` and `1`. Is `5` greater than `1`? Yes. **Swap them.**
    List: `[1, 5, 4, 2]`
2.  Now compare `5` and `4`. Is `5` greater than `4`? Yes. **Swap them.**
    List: `[1, 4, 5, 2]`
3.  Next, compare `5` and `2`. Is `5` greater than `2`? Yes. **Swap them.**
    List: `[1, 4, 2, 5]`
    *Notice how the largest element, `5`, has "bubbled" to the end of the list after this pass. It's now in its correct sorted position.*

**Second Pass:** (We don't need to check `5` again, as it's sorted)
1.  Compare `1` and `4`. Is `1` greater than `4`? No. **Do nothing.**
    List: `[1, 4, 2, 5]`
2.  Compare `4` and `2`. Is `4` greater than `2`? Yes. **Swap them.**
    List: `[1, 2, 4, 5]`
    *Now `4` is in its correct place.*

**Third Pass:** (We don't need to check `4` or `5` again)
1.  Compare `1` and `2`. Is `1` greater than `2`? No. **Do nothing.**
    List: `[1, 2, 4, 5]`
    *The list is now sorted!*

Here's how this looks visually:

```mermaid
sequenceDiagram
    participant Array "List: [4, 2, 1]"
    Note over Array: Sorting [4, 2, 1] in ascending order

    Array->>Array: Pass 1
    Note over Array: Compare 4 and 2
    Array->>Array: Swap (4 > 2)
    Array->>Array: List becomes [2, 4, 1]
    Note over Array: Compare 4 and 1
    Array->>Array: Swap (4 > 1)
    Array->>Array: List becomes [2, 1, 4]
    Note over Array: Largest element (4) is now at the end

    Array->>Array: Pass 2
    Note over Array: Compare 2 and 1
    Array->>Array: Swap (2 > 1)
    Array->>Array: List becomes [1, 2, 4]
    Note over Array: Next largest element (2) is in place

    Note over Array: List is now sorted: [1, 2, 4]
```

## Bubble Sort: Code Example

Let's see a simplified C++ example of Bubble Sort. This code is inspired by `Level_01/01_Basic Operation With Array/Sorting/bubble_sort.cpp` and `Level_05/Bubble Sort Algorithm.cpp`.

```cpp
#include <iostream> // For input/output

void bubbleSort(int arr[], int n) {
    // Loop through all elements
    for (int i = 0; i < n - 1; i++) {
        // In each pass, compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            // If the element on the left is greater than the one on the right, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];      // Store left element temporarily
                arr[j] = arr[j + 1];    // Move right element to left
                arr[j + 1] = temp;      // Put stored element on the right
            }
        }
    }
}

int main() {
    int numbers[] = {5, 1, 4, 2, 8};
    int n = sizeof(numbers) / sizeof(numbers[0]); // Calculate size of array

    std::cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(numbers, n); // Call our sorting function

    std::cout << "After sorting:  ";
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

**Output:**
```
Before sorting: 5 1 4 2 8 
After sorting:  1 2 4 5 8 
```

In this code:
*   The `bubbleSort` function takes an array `arr` and its `n` size.
*   The **outer loop** (`for (int i = 0; i < n - 1; i++)`) controls how many passes we make. Each pass ensures that one more element is correctly placed at the end.
*   The **inner loop** (`for (int j = 0; j < n - i - 1; j++)`) does the actual comparisons and swaps of adjacent elements. We subtract `i` because the last `i` elements are already sorted and don't need to be checked again.
*   The `if (arr[j] > arr[j + 1])` checks if elements are out of order.
*   The three lines with `temp` perform the **swap**. It's like needing a temporary holding spot when you're swapping two items in your hands.

This example sorts numbers, but you can adapt it to sort other things, like words (alphabetically) or even custom objects based on their properties, just like the `Document` example in `Level_05/Bubble Sort Algorithm.cpp` sorts documents by date.

## Other Common Sorting Algorithms

Bubble Sort is simple to understand, but it's not the most efficient for large lists. There are many other sorting algorithms, each with its own way of getting the job done, some faster and some more complex.

Here are a few more you'll encounter:

### 1. Selection Sort

*   **Idea:** Imagine you want to find the smallest book on your messy shelf and put it in the first spot. Then find the smallest among the *remaining* books and put it in the second spot, and so on.
*   **How it works:** It repeatedly finds the minimum (or maximum) element from the unsorted part of the list and puts it at the beginning (or end) of the sorted part.
*   You can see an example in `Level_01/01_Basic Operation With Array/Sorting/selection_sort.cpp`.

### 2. Insertion Sort

*   **Idea:** Think of sorting a hand of playing cards. You pick up cards one by one and insert them into their correct position among the cards you've already sorted.
*   **How it works:** It builds the final sorted array one item at a time. It iterates through the input elements and consumes one input element in each iteration to place it in its correct place among the sorted elements examined so far.
*   You can find this in `Level_01/01_Basic Operation With Array/Sorting/insertion_sort.cpp`.

### 3. Merge Sort

*   **Idea:** "Divide and Conquer!" If you have a huge stack of books, it's easier to split it into two smaller stacks, sort each smaller stack, and then combine (merge) the two sorted stacks back together.
*   **How it works:** It recursively divides the array into two halves until it gets to single-element arrays (which are sorted by definition). Then, it merges those sorted halves back together in a sorted manner.
*   See `Level_01/01_Basic Operation With Array/Sorting/merge_sort.cpp` for its implementation.

### 4. Quick Sort

*   **Idea:** Pick one book (called a "pivot"). Then, rearrange all other books so that books "smaller" than the pivot are on one side, and books "larger" than the pivot are on the other. Then, do the same thing for the "smaller" and "larger" sections.
*   **How it works:** It picks an element as a "pivot" and partitions the given array around the picked pivot. It then recursively sorts the sub-arrays.
*   An example is available in `Level_01/01_Basic Operation With Array/Sorting/quick_sort.cpp`.

## Why So Many Sorting Algorithms?

You might wonder, why do we need so many ways to sort? It's because different algorithms have different **trade-offs**:

*   **Speed:** Some algorithms are much faster than others, especially for very large lists of data.
*   **Memory Usage:** Some algorithms need extra temporary space to sort, while others sort "in-place" without much extra memory.
*   **Simplicity:** Some are very easy to understand and write, while others are more complex.

For small lists, the choice of algorithm might not matter much. But for millions or billions of items, choosing the right sorting algorithm can make a huge difference in how fast your program runs!

## Conclusion

Sorting algorithms are fundamental tools in computer science that help us arrange data in a meaningful order. We've introduced the concept by imagining a messy bookshelf and learned about **Bubble Sort**, a simple algorithm that repeatedly compares and swaps adjacent elements until the list is ordered. We also briefly touched upon other important sorting methods like Selection Sort, Insertion Sort, Merge Sort, and Quick Sort, understanding that each has its unique approach and trade-offs.

With a solid understanding of sorting, you're now ready to tackle more exciting challenges! In our next chapter, we'll explore another powerful concept: [Prime Number Sieve](03_prime_number_sieve_.md), which helps us find prime numbers efficiently.

---