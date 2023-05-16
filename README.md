# CPP Helper

## Features

* A helper tool for the [C++ course by Frank Brokken and Jurjen Bokma](http://www.icce.rug.nl/edu/).
* Provides the following features:
  * Generate a folder structure for the weekly exercises in the course (`-g`).
  * Create the `order.txt` required for submission (`-o`)
  * Create the zip file that is to be submitted (`-z`)
  * Create a class (inside a folder, with the header guards) (`-c`)
  * Create a source file for a free (or member) function (`-s`)
  * (Potentially) send the email containing the submissions (`-m`)

## Installing

## Commands

### Folder Generation (`-g`)
* To generate the basic folder structure for an exercise, use the following 
  command:
  ```shell
  # General Pattern
  cppHelper -g [<locToGenTo>] <set> <exStart> <exEnd>
  
  # Example, set 1, exercises 1 to 8, to put into folder ./Exercises
  cppHelper -g ./Exercises 1 1 8
  ```
  By default, the exercise folder that the folder is generated in is the
  current directory.

* By default, if the folder / file already exists, it will not be created /
  overwritten.
* If you have common files that you have in every exercise, this command can
  copy these template files. To do this, put the file or folders you wish to
  copy in `$HOME/.cpphelper/exercise/`. They will automatically be copied.
* Make sure to fill out `$HOME/.cpphelper/metadata.txt` to create a
  `metadata.txt` file as well.
* The file that is placed at the top of every exercise (providing a summary for
  it) is named `summary.txt`.
* Sometimes these files might contain strings that are based on the set number
  or the exercise number. Instead of the number put either of the following
  strings:
  * `<set-no>` which will be replaced with the set number that the files is
    generated under.
  * `<ex-no>` which will be replaced with the exercise number of the folder this
    file will be copied to.
* You can actually replace arbitrary strings with arbitrary strings. If you have
  some string (say `toReplace`) in any file, then to replace that string in all
  files with another string (say `replaceWith`), you can use the `-R` augment,
  followed by the strings:
  ```shell
  cppHelper -g -R toReplace replaceWith ./Exercises 1 1 8
  ```

### `order.txt` Generation
* To generate an `order.txt` for an exercise set, use the following command:
  ```shell
  # General Pattern
  cppHelper -o <setToGenerateFor> {<exerciseToExclude> <whitespace>}
  
  # Example, generate for set in folder "./set1", except for exercise 4 and 5
  cppHelper -o ./set1 4 5
  
* **Note that you will need to modify the order of the files in the `order.txt`
  in some cases, as Frank / Jurjen / TAs expect a certain ordering of files.**
  We try our best to make the `order.txt` as nice as possible, but it won't be
  perfect.
  
* Often enough, there will be folders / files you wish to automatically exclude
  from the `order.txt`, such as build folders / files. To ignore these folders
  / files, add them to `.cpphelpder/ignore.txt`.

  For example, if every exercise (perhaps) contains a folder named
  `cmake-build-debug/` or `CMakeLists.txt` that you never want to include,
  you can add `cmake-build-debug/`  and `CMakeLists.txt` to the `ignore.txt`
  file.
  
  Note, that the path names are relative from the exercise directory.
* Lastly, you often want to order the files in the `order.txt` in a specific
  order. For example, you often want the `.h` file for a class to be above the
  `.cc` files for that class. Furthermore, you need a text file explaining the
  exercise at the top of the `order.txt` (which we call `summary.txt`) 

  It's a difficult task to do perfectly, and an ideal solution would involve
  parsing a subset of C++ to determine which classes a file is associated with.

  To reduce the amount of "fixing" you have to do on the generated `order.txt`,
  we will do some basic ordering on file extensions / file names. This is
  configurable in the `.cpphelper/prio.txt` file (which you can create). File
  names / extensions that appear earlier in this file will be placed higher
  in priority in the final `order.txt`. 

  Each line contains a file name / extension. An extension must start with `.`
  and a filename must be prepended with `$`.

  This ordering is conducted per folder in the exercise, which each folder's
  files being separated in the generated `order.txt`.

  The default ordering is:
  ```
  summary.txt
  grammar
  lexer
  .h
  .ih
  .f
  .hi
  .cc
  .cpp
  ```

### `.zip` Generation
* To generate an `setN.zip` for an exercise set, use the following command:
  ```shell
  # General Pattern
  cppHelper -z <setToGenerateFor> {<exerciseToExclude> <whitespace>}
  
  # Example, generate for set in folder ./set1, except for exercise 4 and 5
  cppHelper -z ./set1 4 5
  ```
  
* Note that the files added to the zip are based on the `order.txt` files inside
  each exercise folder. If no `order.txt` exists in a folder, that exercise will
  not be added.

### Class Generation

### Source File Generation

### Submitting via Email


## Development

### Design
* `Config` is a singleton that gets initialized at the start of the program. It
  contains the information gathered out of parsing the `$HOME/.cpphelper/`
  directory.
* `ArgParser` is a bisonc++ parser that breaks up a command into its components
  (it also uses `ArgScanner` which is a flexc++ lexer:
  * Command
  * Flags
  * Arguments
* The commands are implemented via the Command pattern.
* The main program runs `ArgParser` and creates a POD called `CommandRecipe`.
  Then, Command builds itself based on `CommandRecipe`. From this, we run its
  `execute` member, executing the command.
* For tests, each class being tested has it's own xxxTest folder. The fixture
  for that test has it's own .h and .ih file, and is otherwise a normal class.
  The actual GoogleTest code is inside a test.cc file in that folder.

### Compiling
* We compile the project with CMake.
* To update parser, you can use the `remakeparser.sh` script as follows:
  `remakeparser.sh <parser-name>`. Note then, that the parser folder should 
  then be `<parser-name>Parser` and the scanner folder should be
  `<parser-name>Scanner`.

### TODO
* Error reporting on parser(s)
* Verbose flag for all commands
* Write parser for `replace.txt`
* Write Command
* Write GenFolder Command
* Write GenZip Command 
* Write GenClass Command
* Write GenMember Command
* Write GenMember Command
* Write install script
