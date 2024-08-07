# There are two types of ways to use string in cpp:

1. **C-style strings**
    ```cpp
    int main(){
        char str[]="gfg";  // when we add "" the compiler automatically adds '\0' to the end of the string
        cout << str;
        return 0;
    }
    ```

    `char str[6]="gfg"` will have the following array: `g f g \0 \0 \0`

    `char str[]="gfg"` and `sizeof(str)` will give 4 due to '\0'

    `char str[]={'g','f','g'}` and if we print this string the output is not defined and its length is only 3.

    `char str[]={'g','f','g','\0'}` we must add '\0' if we use it as a string.

    **Functions:**
    1. `strlen(str)`
    2. `strcmp(s1, s2)` compares them lexicographically (We cannot use assignment operator with array of char / C-style strings, hence we use `strcpy` for assignment)
    3. `strcpy(s1, s2)` copies `s2` to `s1`.

2. **Cpp strings:**

    Richer library

    Supports operators like `+`, `<`, `>`, `==`, `>=`, `<=`

    Can assign a string later

    Do not have to worry about its size because it is dynamically allocated

    Can be converted to C style if needed

    **Functions:**
    ```cpp
    int main() {
        string str = "geeksforgeeks";
        cout << str.length() << " "; // length of the string
        str = str + "xyz"; // concatenation
        cout << str << " ";
        cout << str.substr(1, 3) << " "; // gives the substring, parameters: beginning index, length of the substring
        cout << str.find("eek") << " "; // finds a string in a given string
        return 0;
    }
    ```

    `cin` takes the string up to a space

    To input a whole line we use `getline(str)` which takes the string till the user enters 'Enter'

    Also in `getline(cin, str, char)` we can enter a character where it stops; by default, it stops at `\n`

    To iterate through the string we can use a range-based loop
