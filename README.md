# competitive

This is an ongoing template I am building for competitive programming contests. Right now, I intend to simply do as many easier problems as possible, simply because this way I can quickly figure out what exactly I need templates of.

The template is split into multiple components:
 - `socho_utils` for general utility functions I seem to be using often.
 - `socho_math` for math (especially number theory related) functions I seem to be using often.
 - `socho_graph` for graph structures and functions I seem to be using often. I'm currently redesigning it; in practice I have found a lot of the tools here to be difficult to use. If you'd like to help out with the redesign, please reach out!

Future components planned include:
 - `socho_ds` for data structure components.
 - `socho_geometry` for geometry components.
 - `socho_string` for string components.
 
Some competitive programming friendly shortcuts that this template uses throughout all components:
 - All integers are 64-bit `long long` values.
 - All doubles are 64-bit `long double` values.
 - By default, `endl` is simply replaced with the `'\n'` character, since this significantly speeds up output. You will need to disable this for most interactive problems, or use `flush` explicitly!
 - The default value of `MOD` used in most computations is $10^9+7$, although this can be easily replaced in almost every single function.

Anyway here is a description of how to use every function in this template, in case somebody other than me ends up using it:

## `socho_utils`: general functions which I find useful to keep

#### `copies`

| Description | Copies a string a certain number of times. |
|---|:---|
| Signature | `string copies(string x, int c)`  |
| Usage | `x` must be a string. `c` must be an integer. `copies(x, c)` will a string with `c` copies of `x`. |
| Example | `copies("hello", 3)` returns `"hellohellohello"`. |

#### `count`

##### 1. Default version

| Description | Counts the number of occurrences of a given item |
|---|:---|
| Signature | `int count(vector<T> items, T item)`  |
| Usage | `items` must be a vector of any type. `item` must be an item of the same type. `count(items, item)` returns the number of times `item` occurs in `items`. |
| Example | For example, the function called with `items = {4, 2, 3, 4}`, `item = 4` will return `2`.  |

##### 2. Signed/32-bit friendly version

This is included because using the `count` function mentioned above will not work with a vector of 64-bit values and an integer literal provided directly, which is sometimes useful in competitive programming. This works the same as above.

#### `count_distinct`

##### 1. For vectors

| Description | Counts the number of occurrences of a given item |
|---|:---|
| Signature | `int count_distinct(vector<T> s)`  |
| Usage | `s` must be a vector of any type. `count_distinct` returns the number of distinct values in `s`. |
| Example | For example, the function called with `s = {4, 2, 3, 4}` will return `3`. |

##### 2. For strings

| Description | Counts the number of occurrences of a given character |
|---|:---|
| Signature | `int count_distinct(string s)`  |
| Usage | `s` must be a string. `count_distinct(s)` returns the number of unique characters in `s`. |
| Example | For example, the function called with `s = "dbcda"` will return `4`.  |

#### `digits`

| Description | Returns a vector of integers, representing the digits of a number. |
|---|:---|
| Signature | `vector<int> digits(int x)`  |
| Usage | `x` must be an integer. `digits(x)` will return the vector of digits, in order, of `x`. Note that this function does not work with negative integers. |
| Example | For example, `digits(8)` will return the vector `{8}` and `digits(1300)` will return the vector `{1, 3, 0, 0}`. |

#### `doubleprint`

This is useful for many competitive programming problems seeking absolute or relative error within a certain range.

| Description | Sets the output mode to print doubles with a fixed number of decimal digits after the decimal point. |
|---|:---|
| Signature | `void doubleprint(int precision=10)`  |
| Usage | `precision`, if provided, must be an integer. Otherwise, it will default to `10`. |
| Example | For example, `doubleprint(5)` will output five digits after the decimal point (for any subsequent outputs). |

#### `endswith`

| Description | Checks if a string has another string as its suffix |
|---|:---|
| Signature | `bool endswith(string a, string b)`  |
| Usage | `a` must be a string. `b` must be a string. `endswith(a, b)` will return true if `b` is a suffix of `a`. |
| Example | For example, `endswith("hello", "world")` will return `false`, while `endswith("impossible", "possible")` will return `true`. |

#### `frequency`

1. Arbitrary vector version

| Description | Returns a map of each item in a vector, along with their corresponding frequencies. |
|---|:---|
| Signature | `map<T, int> frequency(vector<T> x)`  |
| Usage | `x` must be a vector of any type `T`. `frequency(x)` will return a map with every item in `x`, along with their corresponding frequencies. |
| Example | For example, `frequency({2, 1, 1, 3})` will return the map `{1: 2, 2: 1, 3: 1}`. |

2. String version

| Description | Returns a map of each character in a string, along with their corresponding frequencies. |
|---|:---|
| Signature | `map<char, int> frequency(string s)`  |
| Usage | `s` must be a string. `frequency(s)` will return a map with every character in `s`, along with their corresponding frequencies. |
| Example | For example, `frequency("hello")` will return the map `{'e': 1, 'h': 1, 'l': 2, 'o': 1}`. |

#### `frequency_alphabet`

| Description | Returns a vector of the frequency of every letter in the alphabet. |
|---|:---|
| Signature | `vector<int> frequency_alphabet(string s)`  |
| Usage | `s` must be a string. `frequency_alphabet(s)` will return a vector with the frequency of every letter. Uppercase and lowercase are not distinguished by this function. |
| Example | For example, `frequency_alphabet("Aa_aaB")` will return the array `[3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]`. |

#### `in_any`

| Description | Returns a vector containing all elements in either input vector. |
|---|:---|
| Signature | `vector<T> in_any(vector<T> a, vector<T> b)`  |
| Usage | `a` must be a vector of any type `T`. `b` must be another vector of the same type `T`. `in_any(a, b)` returns a vector of all elements contained in at least one of `a` or `b`. This is the set-union operation, from a set perspective. |
| Example | `in_any({1, 2}, {1, 3})` returns `{1, 2, 3}`. |

#### `in_both`

| Description | Returns a vector containing all elements in both input vectors. |
|---|:---|
| Signature | `vector<T> in_both(vector<T> a, vector<T> b)`  |
| Usage | `a` must be a vector of any type `T`. `b` must be another vector of the same type `T`. `in_both(a, b)` returns a vector of all elements contained in both `a` and `b`. This is the set-intersection operation, from a set perspective. |
| Example | `in_both({1, 2}, {1, 3})` returns `{1}`. |

#### `in_range`

| Description | Calculates the number of integers in the range between two integers (both ends inclusive). |
|---|:---|
| Signature | `int in_range(int a, int b)`  |
| Usage | `a` must be an integer. `b` must be an integer. `in_range(a, b)` will return the number of integers in `[a, b]` |
| Example | For example, `in_range(5, 8)` will return the integer `4` (since 5, 6, 7 and 8 are in the range) while `in_range(3, 1)` will return `0`, since it checks for numbers greater than or equal to `3`, as well as less than or equal to `1`, of which there are none. |

#### `interval_union`

| Description | Calculates the union of a set of given intervals. |
|---|:---|
| Signature | `vector<pair<int, int>> interval_union(vector<pair<int, int>> intervals)`  |
| Usage | `intervals` must be a vector of intervals, represented as pairs.  |
| Example | For example, `interval_union({{4, 5}, {5, 8}, {10, 14}, {11, 12}})` will return `{{4, 8}, {10, 14}}`. |

#### `inverse`

| Description | Returns a map containing every element and the index of the element in the vector. |
|---|:---|
| Signature | `map<T, int> inverse(vector<T> x, int indexing=0, bool first=false)`  |
| Usage |  `x` must be a vector of elements of any type `T`. `indexing`, if provided must be an integer. `first`, if provided, must be a boolean. `inverse(x, indexing, first)` returns a map containing every element in `x` as well as the last index it occurs at, using `indexing`-indexing (0 or 1 are conventional), unless `first` is true, in which case the first index will be used. |
| Example | For example, `inverse({1, 2, 4, 1})` will return `{1: 3, 2: 1, 4: 2}`. If `indexing` is set to `1`, it will instead return `{1: 4, 2: 2, 4: 3}`. If `indexing` is set to `1` and `first` is set to `true`, it will instead return `{1: 1, 2: 2, 4: 3}`. |

#### `inverses`

| Description | Returns a map containing every element and every index containing that element. |
|---|:---|
| Signature | `map<T, vector<int>> inverses(vector<T> x, int indexing=0)`  |
| Usage |  `x` must be a vector of elements of any type `T`. `indexing`, if provided must be an integer. `inverses(x, indexing)` returns a map containing every element in `x` as well as all indexes it occurs at in a vextor, using `indexing`-indexing (0 or 1 are conventional). |
| Example | For example, `inverses({1, 2, 4, 1})` will return `{1: {0, 3}, 2: {1}, 4: {2}}`. If `indexing` is set to `1`, it will instead return `{1: {1, 4}, 2: {2}, 4: {3}}`. |



#### `is_lowercase`

| Description | Checks if a character is a lowercase alphabet. |
|---|:---|
| Signature | `bool is_lowercase(char x)`  |
| Usage | `x` must be a character. |
| Example | For example, `is_lowercase('a')` will return `true`, `is_lowercase('A')` will return `false`, and `is_lowercase('#')` will return `false`. |

#### `is_uppercase`

| Description | Checks if a character is an uppercase alphabet. |
|---|:---|
| Signature | `bool is_uppercase(char x)`  |
| Usage | `x` must be a character. |
| Example | For example, `is_uppercase('a')` will return `false`, `is_uppercase('A')` will return `true`, and `is_uppercase('#')` will return `false`. |

#### `is_subset`

| Description | Checks if a set is a subset of another set. |
|---|:---|
| Signature | `is_subset(vector<int> a, vector<int> b)`  |
| Usage | `a` must be a vector of integers. `b` must be a vector of integers. `is_subset(a, b)` will return whether `b` is a subset of `a`. |
| Example | For example, `is_subset({2, 1, 4}, {2})` will return `true`, `is_subset({2, 1, 4}, {2, 3})` will return `false`. |

#### `is_superset`

| Description | Checks if a set is a superset of another set. |
|---|:---|
| Signature | `is_superset(vector<int> a, vector<int> b)`  |
| Usage | `a` must be a vector of integers. `b` must be a vector of integers. `is_superset(a, b)` will return whether `b` is a superset of `a`. |
| Example | For example, `is_superset({2}, {2, 1, 4})` will return `true`, `is_superset({2, 3}, {2, 1, 4})` will return `false`. |

#### `max` and `min`

##### 1. Signed/32-bit friendly version
This is included because using the `max` and `min` functions included by default will not work with a 64-bit value and an integer literal provided directly, which is sometimes useful in competitive programming. Both orders of the 32-bit and 64-bit integer have been included in the template.

##### 2. Three argument version
This is included because the inbuilt `max` and `min` functions accept exactly two arguments, while it is often to use three arguments.

##### 3. Vector version

| Description | Finds the maximum element in a vector. |
|---|:---|
| Signature | `T max(vector<T> a)`  |
| Usage | `a` must be a vector of any type. `max(a)` returns the maximum value in `a`. |
| Example | `max({1, 2})` returns `2`. |

| Description | Finds the minimum element in a vector. |
|---|:---|
| Signature | `T min(vector<T> a)`  |
| Usage | `a` must be a vector of any type. `min(a)` returns the minimum value in `a`. |
| Example | `min({1, 2})` returns `1`. |

#### `max_key`

| Description | Finds the key with highest value |
|---|:---|
| Signature | `T max_key(map<T, int> a)`  |
| Usage | `a` must be a map from any type `T` to integers.. `max_key(a)` returns the key `T` with highest value in `a`  |
| Example | `max_key({3: 1, 4: 2, 5: 0})` returns `4` and `max_key({"hello": 2, "world": 1})` returns `"hello"`. |

#### `mex`

| Description | Returns the first element not in the vector. |
|---|:---|
| Signature | `int mex(vector<int> items, int from=0)`  |
| Usage |  `items` must be a vector of integers. `from`, if provided must be an integer. `mex(items, from)` the smallest integer, counting from `from` which is not in items. |
| Example | For example, `mex({0, 1, 3, 5})` returns `2`, while `mex({1, 2, 4, 6}, 1)` returns `3` (as 0 is excluded when counting from 1). |

#### `pad_left`

| Description | Pads a string to at least a certain length, using a certain character. |
|---|:---|
| Signature | `string pad_left(string x, int len, char c='0')`  |
| Usage | `x` must be a string. `len` must be an integer. `c`, if provided, must be a character, otherwise it will default to `'0'`. `pad_left(x, len, c)` will left-pad `x` to a length of at least `len`, using the character `c`. |
| Example | For example, `pad_left("hi", 5, '-')` will return `"---hi"`, while `pad_left("hello", 2)` will return `"hello"`, since the target length is already met with the input string.|

#### `printif`

This is useful for yes/no and true/false problems on CodeForces and AtCoder.

| Description | Outputs a string based on the value of the first argument. |
|---|:---|
| Signature | `void printif(bool e, string yes="Yes", string no="No")`  |
| Usage | `e` must be a boolean value. If `yes` is provided, it must be a string. If `no` is provided, it must be a string. `printif(e, yes, no)` outputs (using `cout`) the string `yes` followed by a newline if `e` is true, or the string `no` followed by a newline if `e` is false. |
| Example | For example, the function called with `e = true` will return nothing, but will output "Yes" and a newline, while the function called with `e = false` will output "No" and a newline. The default Yes and No can be changed using the optional `yes` and `no` parameters. |

#### `substring`

| Description | Checks whether a string is a substring of another string. |
|---|:---|
| Signature | `bool substring(string x, string y)`  |
| Usage | `x` must be a string. `y` must be a string. `substring(x, y)` returns true if `y` is a substring of `x`. |
| Example | `substring("triplet", "iple")` returns `true`. `substring("hello", "world")` returns `false`. |

#### `sum`

| Description | Returns a sum of all the elements in the vector. |
|---|:---|
| Signature | `int sum(vector<int> x)`  |
| Usage | `x` must be a vector of integers. `sum(x)` will return the sum of all the integers in the vector. |
| Example | For example, `sum({3, 2, 4, 1})` will return the integer `10` and `sum({-10, 10})` will return the integer `0`. |

#### `to_lower`

##### 1. Character version

| Description | Converts a character into the corresponding lowercase character. |
|---|:---|
| Signature | `char to_lower(char a)`  |
| Usage | `a` must be a character. `to_lower(a)` will return a character which is the lowercase version of `a`. |
| Example | For example, `to_lower('a')` returns `a` and `to_lower('A')` returns `'a'`. |

##### 2. String version

| Description | Converts a string into the corresponding lowercase string, character by character. |
|---|:---|
| Signature | `string to_lower(string a)`  |
| Usage | `a` must be a string. `to_lower(a)` will return a string which is the lowercase version of `a`. |
| Example | For example, `to_lower("Hello World")` will return `"hello world"`. |

#### `to_string`

| Description | Converts an integer into the corresponding string. |
|---|:---|
| Signature | `string to_string(int a)`  |
| Usage | `a` must be an integer. `to_string(a)` will return a string with the digits of `a`. Note that this function does not work with negative integers. |
| Example | For example, `to_string(5)` will return `"5"`, and `to_string(12)` will return `"12"`. |

#### `to_upper`

##### 1. Character version

| Description | Converts a character into the corresponding uppercase character. |
|---|:---|
| Signature | `char to_upper(char a)`  |
| Usage | `a` must be a character. `to_upper(a)` will return a character which is the uppercase version of `a`. |
| Example | For example, `to_upper('a')` returns `A` and `to_upper('A')` returns `'A'`. |

##### 2. String version

| Description | Converts a string into the corresponding uppercase string, character by character. |
|---|:---|
| Signature | `string to_upper(string a)`  |
| Usage | `a` must be a string. `to_upper(a)` will return a string which is the uppercase version of `a`. |
| Example | For example, `to_upper("Hello World")` will return `"HELLO WORLD"`. |

#### `vector_input`

##### 1. Integer vectors

| Description | Inputs an entire vector of integers. |
|---|:---|
| Signature | `vector<int> vector_input(int n)`  |
| Usage | `n` must be an integer. `vector_input(n)` will input a vector of `n` integers and return it. |
| Example | For example, `vector_input(4)` will input 4 integers, and return a vector containing them. |

##### 2. Arbitrary vectors

| Description | Inputs an entire vector of any type. |
|---|:---|
| Signature | `vector<T> vector_input(int n, T x)`  |
| Usage | `n` must be an integer. `x` must be an item of any type `T`. `vector_input(n, x)` will input a vector of `n` items of type `T` and return it. |
| Example | For example, `vector_input(4, 5)` will input 4 integers, and return a vector containing them. |

#### `xor_all`

| Description | Returns the `xor` of all integers in the vector. |
|---|:---|
| Signature | `int xor_all(vector<int> e)`  |
| Usage | `e` must be a vector of integers. `xor_all(e)` will return the xor of all integers in the vector. |
| Example | `xor_all({1, 4, 5, 3})` returns `3`. |

## `socho_math`: math (usually number) things I seem to be using often

To be done.

## `socho_graph`: graph things I seem to be using often

To be done.