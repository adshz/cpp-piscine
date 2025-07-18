# Requirement Analysis

## Design Thinking

### Feature list

1. add a person's contact
2. search a person's contact





----DO NOT OVERENGINEERING AS WE ARE JUST DOING EXERCISES----



1. print all contacts
2. delete a person's contact
3. save into a file
4. load a file


We need to think abouot PhoneBook as a software product. 
Because it is a product, we need to think in a product way.

A Phone Book could be a fully-fledged product. When designing this product, we need to consider how to implement it. Before diving into software development, we must first establish a clear approach: how to build it. So when creating this phone book, we should define the system architecture upfront.

We can break this down point by point. 

#### 1. How to store data
The first key point to consider: Out of all the features, let’s first think about how to store contact data. Should we use a linked list, a tree structure, or a graph? These are common data structure.^1

we can use linked list to store our data but if we have a user request that they want to sort data based on alphabetical order. then linked list isn't the best choice. It is better to use Array. because if we use Linked list like singly-linked list will have O(n) random access time. So when it comes to sorting data, we can thinks of some algorithms like MergeSort, QuickSort, these need frequent element access/swaps. it will be inefficient in linked list because Linked list doesn't support random access. 

#### 2. Which file format(container) should we store data in?

How long and how complete data do we need to have? Usually we will save them in files or database, as the second point to consider: We need a way to store data for durablity and completity.

On the other hand, we need to think about the shape of data object in the file. The common format is json but we can use key-value to store name: xxxx, phone: xxxx




#### 3. What details inside the data model do we need?

This naturally leads us to the next question: What information should each contact contain? For a phone book, the most critical fields are name and phone number.





### Glossary:

1. 完善的产品 -> Production-ready product, end-to-end product, Fully-fledged product
2. 思路 -> Approach, design thinking (for higher-level planning), Methodology, strategy, blueprint
3. 这个产品怎么做 -> how to architect it, How to build it, the implementation plan
4. 产品的架构 ->    System architecture, System architecture, software design
5. 一个个点来思考 -> tackle this step by step, Break this down point by point
6. 思考的一个点 -> One key point to consider, a critical aspect to analyze
7. 链表，树形结构，图的结构 -> Linked list, tree structure, or grap
8. 红黑树 ->Red-Black Tree Guarantees O(log n) search/insert/delete, making it ideal for dynamic datasets (e.g., phone book with frequent updates).
9. 平衡二叉树 -> Balanced Binary Tree     AVL trees (stricter balance) for read-heavy workloads (e.g., static contact lists).

    Red-Black trees for mixed read/write workloads (e.g., frequently updated contacts).
10. 哈希表 -> Hash Table (or Hash Map)     O(1) average-time lookups/insertions (e.g., quick name→phone number searches).

    Used in Python’s dict, Java’s HashMap, JavaScript objects.

11. 底层的实现->Low-level implementation


- [^1] I actually didn't know why we started from how to save data first. I guess this is a habit software engineers should have. When you think about a product as well as its features(after confirmed and validate), the engineer apsect is to think about how to store product's data. as data drives everything, the way you store your data (liinked tree, tree-like, grap) dictates how you interact with them. each data structure has its goods/bads. For example, if a user frequently add/delete data, then it is the perfect case to use linked tree; if a user frequently search data, then it is perfect tto use tree (trees for fast lookups like O(log n)).); If a user has millions/billions or you have billions or millions users, then it is a challenge for Scalability (e.g., graphs for complex relationships). 
