Example use-cases of your pmap:


Describe your design for your parallel map:
    pmap delegates cloning to the subclass that implements Rower. Thus, cloning can be 
    either a deep-copy or pointer equality, whichever is favorable for the client. Then, pmap
    splits the mapping of each row to two threads, allocating an additional map call to the 
    second thread if the amount of rows is odd.

Describe how the examples in your parallel_map_examples.cpp file demonstrate that pmap is faster:
    In these extremely large use cases (a million rows), differences in trivial cases 
    (time taken to clone the )

Describe issues that you encountered in implementing your parallel map:
    Because the Rower's dataframe is read-only (currently), we have to gripe with the fact that 
    cloning it according to project specs would unnecessarily take up memory/time. 
    However, because the project specs mentioned that the implementation of pmap only had to 
    asymptotically be faster map, cloning would be fine for this implementation.

    The main problem was attempting to overload the original map method with two new parameters,
    indices marking the ends of the thread slices of the rows. After wrestling with the 
    thread library for hours on how to properly pass in parameters and cast the function 
    correctly, we resigned to just making the pmap's map a helper method instead.

Additions to the original dataframe.h:
    Added a limited_map method that functions like map but takes in two additional parameters:
            size_t start_idx - the starting index of the rows to access
            size_t end_idx - the ending index of the rows to access
        This was added in order for the threads to know where to start in the Rower/clones'
        rows.