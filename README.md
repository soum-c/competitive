# competitive

This is an ongoing template I am building for competitive programming contests. Right now, I intend to simply do as many easier problems as possible, simply because this way I can quickly figure out what exactly I need templates of.

The template is split into multiple components:
 - `socho_utils` for general utility functions I seem to be using often.
 - `socho_math` for math (especially number theory related) functions I seem to be using often.
 - `socho_graph` for graph structures and functions I seem to be using often.

Future components planned include:
 - `socho_ds` for data structure components.
 - `socho_geometry` for geometry components.
 
Anyway here is a description of how to use every function in this template, in case somebody other than me ends up using it:

## `socho_utils`: general functions which I find useful to keep

#### `count`

##### 1. Default version

| Description | Counts the number of occurrences of a given item |
|---|:---|
| Signature | `int count(vector<T> items, T item)`  |
| Usage | `items` must be a vector of any type. `item` must be an item of the same type. `count(items, item)` returns the number of times `item` occurs in `items`. |
| Example | For example, the function called with `items = {4, 2, 3, 4}`, `item = 4` will return `2`.  |

##### 2. Signed/32-bit friendly version

This is included because using the `count` function mentioned above will not work with a vector of 64-bit values and an integer literal provided directly, which is sometimes useful in competitive programming. This works the same as above.

#### `max` and `min`

##### 1. Signed/32-bit friendly version
This is included because using the `max` and `min` functions included by default will not work with a 64-bit value and an integer literal provided directly, which is sometimes useful in competitive programming. Both orders of the 32-bit and 64-bit integer have been included in the template.

##### 2. Three argument version
This is included because the inbuilt `max` and `min` functions accept exactly two arguments, while it is often to use three arguments.

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

#### `printif`

This is useful for yes/no and true/false problems on CodeForces and AtCoder.

| Description | Outputs a string based on the value of the first argument. |
|---|:---|
| Signature | `void printif(bool e, string yes="Yes", string no="No")`  |
| Usage | `e` must be a boolean value. If `yes` is provided, it must be a string. If `no` is provided, it must be a string. `printif(e, yes, no)` outputs (using `cout`) the string `yes` followed by a newline if `e` is true, or the string `no` followed by a newline if `e` is false. |
| Example | For example, the function called with `e = true` will return nothing, but will output "Yes" and a newline, while the function called with `e = false` will output "No" and a newline.  |

## `socho_math`: math (usually number) things I seem to be using often


## `socho_graph`: graph things I seem to be using often