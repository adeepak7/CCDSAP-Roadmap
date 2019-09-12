Both std::map & std::unordered_map store elements in key value pair & provide member functions to efficiently insert, search & delete key value pairs.

But they are different in following areas
  - Internal Implementation
  - Memory Usage
  - Time Complexity
  - Using user defined objects as keys
  
Internal Implementation :

  - std::map Internally store elements in a balanced BST. Therefore, elements will be stored in sorted order of keys.

  - std::unordered_map store elements using hash table. Therefore, elements will not be stored in any sorted order. They will be stored in arbitrary order
  
Memory Usage :

  - Memory usage is more in unordered_map as compared to map because unordered_map need space for storing hash table too
  
Time Complexity for Searching element :

  - Time complexity for searching elements in std::map is O(log n). Even in worst case it will be O(log n) because elements are stored internally as Balanced Binary Search tree (BST).

  - Whereas, in std::unordered_map best case time complexity for searching is O(1). Where as, if hash code function is not good then, worst case complexity can be O(n) (In case all keys are in same bucket).

Using user define objects as Keys :
  
  - For std::map to use user defined object as keys, we need to override either < operator or pass external comparator i.e. a functor or function pointer that can be used by map for comparing keys.

  - Where as, For std::unordered_map we need to provide definition of function std::hash<K> for our key type K. Also we need to override == operator
  
When to choose map instead of unordered_map

  - When you need Low Memory:
    
    - Unordered_map consumes extra memory for internal hashing, so if you are keeping millions and billions of data inside the map and want to consume less memory then choose std::map instead of std::unordered_map.

  - When you are interested in Ordering too
    
    - As std::map  internally use balanced BST, so all the elements inside it will be in sorted order based on the key. So, if you want all keys to be ordered then go for std::map.

  - When you need guaranted Performance
    
    - For searching an element, std::unordered_map gives the complexity O(1) in best case but O(n) in worst case (if hash implementation is not perfect).

    - So, if your hash implementation is not good and you have millions and billions of data then go for std::map because it will give you guaranteed O(log N).

When to choose unordered_map instead of map

  - When you have good hasher and no memory limitation
    - Unordered_map consumes extra memory for internal hashing. But to due to this searching complexity is O(1), if hasher function is good
