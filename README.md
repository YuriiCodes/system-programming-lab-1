# 📘 Dynamic Word Analyzer 📘

Dynamic Word Analyzer is a C project designed to analyze a given text file and identify words with the highest number of unique characters. 🧐 The program is not subject to any restrictions on file size or line length. 🚀 

## 🎯 Objective 🎯

- 📖 Analyze a given text file without restrictions on its size.
- 🕵️ Identify words with the highest number of different letters, i.e., letters that are repeated in a word should not be considered.
- 📊 The identified words should be displayed uniquely, satisfying the condition mentioned above.
  
## 💻 How to Run 💻

1. Clone the repository to your local machine.
   ```sh
   git clone <repo-url>
   ```

2. Navigate to the directory containing the source files.
   ```sh
   cd <directory-name>
   ```

3. Compile the program.
   ```sh
   gcc -o analyzer main.c DynamicWordArray.c -lregex
   ```

4. Run the program with a text file.
   ```sh
   ./analyzer example.txt
   ```

## 📝 Program Logic 📝

1. **File Reading 📖:**
    - The program reads the text file line by line and extracts words from each line using regular expressions.

2. **Word Processing 🔄:**
    - Each word is converted to lowercase and processed to find the unique characters.

3. **Word Analysis 🧠:**
    - The program identifies words with the highest number of unique characters and displays them uniquely.

## 🗃️ Files 🗃️

- `main.c` – contains the main function and the logic for reading the file.
- `DynamicWordArray.c` – manages dynamic memory for storing the words.
- `example.txt` – an example file containing the text to be analyzed.

## 🧪 Example 🧪

```c
// Running with example.txt containing:
// "$%_banana)()*))))__F apple f orange"

// Will output:
// word	#5: orange	|	unique letters: 6
```

## 📚 Dependencies 📚

- C Standard Library
- POSIX Regular Expressions Library

## 📄 License 📄

This project is licensed under the MIT License.

## 💌 Contact 💌

For any queries or concerns, please feel free to reach out to the developers.
```