[//]: # (It's licensed under MIT, btw)

# An implementation of different structures

## Stack
> https://en.wikipedia.org/wiki/Stack_(abstract_data_type)


#### Types
| type          | description                                                                         |
|:-------------:|:------------------------------------------------------------------------------------|
| stack_t       | The stack itself. Should be assingned the value of `stack_new()` or zeroed manually |
| stack_item_t  | The item stored in the stack |

#### Methods
| method        | time complexity   | return value | arguments                                  | description                                                    |
|:-------------:|:-----------------:|:------------:|:------------------------------------------:|:---------------------------------------------------------------|
| stack_new()   | O(1)              | stack_t      |                                            | Returns `stack_t` filled with zeroes                           |
| stack_empty() | O(1)              | int (bool)   | stack_t  `S`                               | Returns a boolean value indicating whether or not `S` is empty |
| stack_top()   | O(1)              | void*        | stack_t  `S`                               | Accesses the top element                                       |
| stack_push()  | O(1)              |              | stack_t* `S`<br>void* `item`<br>size_t `N` | Inserts `item` (its first `N` bytes) at the top                |
| stack_pop()   | O(1)              |              | stack_t* `S`                               | Removes the top element                                        |

---

## Queue
> https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)


#### Types
| type         | description                                                                    |
|:------------:|:-------------------------------------------------------------------------------|
| queue_t      | The queue type. should be assigned the value of stack_new() or zeroed manually |
| queue_item_t | The item stored in the queue                                                   |

#### Methods
| method        | time complexity | return value | arguments                                  | description                                                        |
|:-------------:|:---------------:|:------------:|:------------------------------------------:|:-------------------------------------------------------------------|
| queue_new()   | O(1)            | queue_t      |                                            | Returns `queue_t` filled with zeroes                               |
| queue_empty() | O(1)            | int (bool)   | queue_t  `Q`                               | Returns a boolean value indicating whether or not `Q` is empty     |
| queue_front() | O(1)            | void*        | queue_t  `Q`                               | Accesses the first element                                         |
| queue_back()  | O(1)            | void*        | queue_t  `Q`                               | Accesses the last element                                          |
| queue_push()  | O(1)            |              | queue_t* `Q`<br>void* `item`<br>size_t `N` | Inserts `item` (its first `N` bytes) at the end                    |
| queue_pop()   | O(1)            |              | queue_t* `Q`                               | Removes the last element                                           |

---
---

## Helper files
## comparator.h

> Provides comparable items and some comparators.
> In the future, it will be used to implement ordered structures like [heap](https://en.wikipedia.org/wiki/Heap_(data_structure)) and [set](https://en.wikipedia.org/wiki/Set_(abstract_data_type))

All comparators answer the same question: "Does `a` have greater value than `b`?"
The definition of the value is up to the comparator

| return value | arguments                        |
|:------------:|:--------------------------------:|
| int (bool)   | cmp_item_t `a`<br>cmp_item_t `b` |



### Types
| type       | description                                                |
|:----------:|:-----------------------------------------------------------|
| cmp_item_t | An element which can be compared independently of its type |


### Size-only compare
> Compare by size (in bytes)

| method            | question                                               |
|:-----------------:|:-------------------------------------------------------|
| cmp_shorter(a, b) | Is the size of `a` less or equal than the size of `b`? |
| cmp_longer(a, b)  | Is the size of `a` longer than the size of `b`?        |

### Platform-dependent
> Compare items byte by byte, with the most significant value defined by the platform's default endianness

| method            | endianness       | question                       |
|:-----------------:|:-----------------|:-------------------------------|
| cmp_smaller(a, b) | Platform default | Is `a` less or equal to `b`?   |
| cmp_greater(a, b) | Platform default | Is `a` greater than `b`?       |

### Platform-independent
> Compare items byte by byte

| method               | endianness    | question                       |
|:--------------------:|:-------------:|:-------------------------------|
| cmp_smaller_le(a, b) | Little-endian | Is `a` less or equal to `b`?   |
| cmp_greater_le(a, b) | Little-endian | Is `a` greater than `b`?       |
| cmp_smaller_be(a, b) | Big-endian    | Is `a` less or equal to `b`?   |
| cmp_greater_be(a, b) | Big-endlian   | Is `a` greater than `b`?       |