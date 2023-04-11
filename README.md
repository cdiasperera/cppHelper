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

### Folder Generation
* To generate the basic folder structure for an exercise, use the following 
  command:
  ```shell
  # General Pattern
  cppHelper -g "<locToGenTo>" <set> <exStart> <exEnd>
  
  # Example, set 1, exercises 1 to 8, to put into folder "./Exercises"
  cppHelper -g "./Exercises" 1 1 8
  ```

* If you have common files that you have in every project, this command can copy
  these template files. To do this, put the file or folders you wish to copy in
  `$HOME/.cpphelper/exercise/`. They will automatically be copied.
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
  cppHelper -g -R "toReplace" "replaceWith" "./Exercises" 1 1 8
  ```

### `order.txt` Generation

### `.zip` Generation

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

### Compiling
* We compile the project with CMake.
* To update parser, you can use the `remakeparser.sh` script as follows:
  `remakeparser.sh <parser-name>`. Note then, that the parser folder should 
  then be `<parser-name>Parser` and the scanner folder should be
  `<parser-name>Scanner`.

### TODO
* Set up testing
* Error reporting on parser(s)
* Set up testing environment
* Think about what to do for scanner output for things that don't match
* Write parser for `replace.txt`
* Write Command
* Write GenFolder Command
* Replace `<set-no>` and `<ex-no>` during copying of files.
* Write GenOrders Command 
* Write GenZip Command 
* Write GenClass Command
* Write GenMember Command
* Write SendEmail Command
* Write install script
