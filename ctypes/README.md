# An implementation of different structures

## Stack
> https://en.wikipedia.org/wiki/Stack_(abstract_data_type)


| type | description |
|:----:|:-----------|
|stack_t|The stack itself. Should be assingned the value of `stack_new()` or zeroed manually |
|stack_item_t|The item stored in the stack|

| method | time complexity | return value | arguments | description |
|:------:|:---------------:|:------------:|:---------:|:------------|
|stack_new()|O(1)|stack_t||Returns `stack_t` filled with zeroes|
|stack_empty()|O(1)|int (bool)|stack_t `S`|Returns a boolean value indicating whether or not `S` is empty|
|stack_top()|O(1)|void*|stack_t `S`|Returns the `item` from the top|
|stack_push()|O(1)||stack_t `S`<br>void* `item`<br>size_t `N`|Inserts an `item` (its first `N` bytes) at the top|
|stack_pop()|O(1)||stack_t `S`|Removes the top element|

---

## Queue
> https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)


| type | description |
|:----:|:------------|
|queue_t|The queue type. should be assigned the value of stack_new() or zeroed manually|
|stack_item_t|The item stored in the queue|

| method | time complexity | return value | arguments | description |
|:------:|:---------------:|:------------:|:---------:|:------------|
|queue_new()|O(1)|queue_t||Returns `queue_t` filled with zeroes|
|queue_empty()|O(1)|int (bool)|queue_t `Q`|Returns a boolean value indicating whether or not the `Q` is empty|
|queue_front()|O(1)|void*|queue_t `Q`|Access the first element|
|queue_back()|O(1)|void*|queue_t `Q`|Access the last element|
|queue_push()|O(1)||queue_t* `Q`<br>void* `item`<br>size_t `N`|Inserts an `item` (its first `N` bytes) at the end|
|queue_pop()|O(1)||queue_t* `Q`|Removes the last element|