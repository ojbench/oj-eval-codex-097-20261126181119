# Solution

The level-order representation contains every student ID. The rank depends only
on these values, so the tree does not need to be reconstructed.

Read integer tokens, ignoring the labels and punctuation. Keep one token pending
so that the final token is interpreted as `cnt`; all preceding tokens are node
values. Count their occurrences in an array indexed by ID. Scan from 100000 down
to 1, subtracting each frequency from the requested rank. The first value where
the rank reaches zero is the answer: exactly `cnt` values have been encountered
in descending order.

For input length L and maximum ID U = 100000, time is O(L + U) and auxiliary
space is O(U). Input is processed as a stream. Null markers, if present, contain
no integers and are ignored.

Build with `cmake . && make`, then run `python3 tests/test_solution.py ./code`.
The tests cover the example, boundary IDs, ranks at both ends, randomized inputs
compared with sorting, and all 100000 possible IDs.
