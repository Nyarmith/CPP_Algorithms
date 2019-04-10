Chapter 3 - Resouce Management

# Item 13 - Use Objects to Manage Resources
- dtor and exceptions making memory leaks with ptrs
- auto_ptr has been deprecated
- RAII !
- can we use it for dynamically allocated arrays yet?

# Item 14 - Think Carefully about Copying Behavior in Resource-Managing Classes
- resources, e.g. mutex
- consider prohibitting copying (delete)

# Item 15 - Provide Access to Raw Resources in Resource-Managing Classes
- It's inevitable you will have to do something not in its API
- So make a good interface for its raw resource
- Can either be done implicitly or explicitly; explicit should be preferred

# Item 16 - Use Correcy Syntax for new and delete
- `delete[]` & `new T[n]`

# Item 17 - Store Newed Objects in Smart Pointers in Standalone Statements
- std::make_unique<uint32_t[]>(arraySize);
