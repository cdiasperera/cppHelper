# CPP Helper

## (Planned) Features

Features with a checkmark are those that have been implemented.

* [x] Generate Folder Structures for an exercise set.
  * [x] Copy a template exercise folder for each exercise.
    
    `<set-no>` and `<ex-no>` strings  in any file are automatically replaced with the correct values.
  * [ ] Arbitrary string can be replaced with arbitrary strings (specified with the CLI command).
  * [x] Copy a `metadata.txt` file to the exercise set folder.
  * [x] If the folder already exists, the command will do nothing and report that a folder already exists.
* [x] Create the `order.txt` files automatically
  * **Note that you will need to modify the `order.txt`in some cases, as Frank /
    Jurjen / TAs expect a certain ordering of files / certain files not to be included**. 
    We try our best to make the order.txt as nice as possible, but it won't be
    perfect.
  * [x] Exclude certain exercises from getting an `order.txt`.
  * [x] Exclude folders / files (such as build folders / makefiles) automatically.
  * [x] Preprocesses the order.txt to:
    * Group files in the same folder (with groups separated by `\n\n`)
    * Order groups based on extension / filename. 
* [ ] Create and validate the zip file to be submitted
  * [x] The zipped file is based on the `order.txt`s in the set we are zipping. If
    you used `cppHelper -o ...` for this, it will zip the exercises that you
    created an `order.txt` for.
  * [x] Exclude folders / files (such as build folders / makefiles) automatically.
  * [ ] If you wish to zip all exercises in a set, you must explicitly write `none` 
    with regard to which exercises must be excluded. This is to prevent
    accidentally sending all the exercises when resubmitting.
* [ ] Create source files for free / member functions
* [ ] Send the email containing the submission

## Installing
1. Download the repo.
2. Run `./INSTALL.sh`

This script creates a build folder `.build/`, creates the executable `cppHelper`
and moves it to `/usr/loca/bin`. 

If you wish to keep the executable in a different location, change the location
in `./INSTALL.sh`. Just make sure that the location is in your `PATH`.
## Using 
* Generate folders:
  ```shell
  cppHelper -g <pathToGenerateFolderAt> <setNo> <firstExNum> <LastExNum>
  ```
  For example:
  ```shell
  cppHelper -g ./sets/ 2 9 15
  ```
  Would generate the following folder structure:
  ```
  -sets/
    -set2/
      -09/
      -10/
      -11/
      -12/
      -13/
      -14/
      -15/
      -metadata.txt
  ```
* Generate Order files:
  ```shell
  cppHelper -o <setToGenerateOrdersFor> <commaSeparatedExercisesToNotGenerateOrderTxtFor>
  ```
  
  For example:
  ```shell
  cpp -o ./sets/set2 9,11
  ```
  
  would generate order files for exercises 10,12-15 (for the set generated by
  the command in the Generate Folder example)

* Zip set:
  ```shell
  cppHelper -z <zipPath> <setToZipPath> <commaSeparatedExercisesToIncludeInZip>
  ```
  **Note that the directory that zipPath lies in must exist**

  For example:
  ```shell
  cppHelper -z . ./sets/set2 9 
  ```
  
  would *try* to zip exercises 10-15 for the set / `order.txt`s generated by the
  previous two commands. However, since ex11 doesn't have an `order.txt`, only
  exercises 10,12-15 will be included in the zip.

  A warning that exercise 11 does not have a `order.txt` will be shown.

## Configuration
* You can configure the program via `$HOME/.cpphelper/`.
    * `$HOME/.cpphelper/template` is the template folder that should be copied into every exercise folder.
    * `$HOME/.cpphelper/metadata.txt` is the metadata file that should be copied into every set folder.
    * `$HOME/.cpphelper/ignore.txt` contains the paths to exclude from the order.txt.
      These paths are relative to the exercise folder in the set.
    * `$HOME/.cpphelper/prio.txt` orders each grouping in the generated `order.txt`.
      File names / extensions that appear earlier in this file will be placed higher in priority in the final `order.txt`.
      Each line contains a file name / extension. 
      An extension must start with `.` and a filename must be prepended with `$`.
      After running `.cppHeler -o` for the first time, if a `prio.txt` is not present, one will be created.

## Contribution
* If you would like to contribute, you can either:
  * Add an issue via the Github issues.
  * Fix an issue and submit a PR to the `dev` branch.
  * Document the design in `/docs/design`.
  * Document the code.
  * Perform QA.
  
### Compiling
1. Create a build folder (e.g: `.build/`)
2. Execute: `cmake ../ -DCMAKE_BUILD_TYPE=Debug`
3. Execute: `make`

Naturally with CMake you can use different build tools (e.g: `ninja`). So you
can tinker with these steps as you wish, if you know what you are doing.

### TODO
- Handle no metadata / template folder case (just create empty files) at the start of execution.
- Zip shouldn't rely on the system utility `zip` as it does now.
- Handle frontend parsing failures gracefully.
- Make install script for Windows.

## FAQ
1. What is `$HOME`?
    * It is the environment variable with the name `HOME`. On a linux machine,
    `cd ~` should send you to this directory. 
2. Will this work on Windows?
    * The only platform specific function is the zipping function (which hopefully will be made platform independent).
    * You should in principle be able to write and run a version of INSTALL.sh that uses windows commands instead.