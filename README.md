# Introduction

idklang is compiled(transpiled to C++) custom programming language I made in a day. Since I had some spare time I decided to improve it. idklang's file extension is .idk. The syntax of a mix of JS, C++ and Python. There is probably ton of bugs already so if you find don't forget report it.

## Installation

Use git to clone the project

### Clone

```bash
git clone https://github.com/SakizciAdam/idklang
```

### Build

#### CMake

```bash
mkdir -p cmakebuild
cd cmakebuild
cmake .. # use -G "MinGW Makefiles" flag if you are using MinGW
make
```

#### Make

```bash
make
```

## How to compile idklang file

```bash
./target/idklang <idklang file path> 
[-o: output file] 
[--keep: to keep the C++ file] 
[--no-compile: does not compile into executable]
```

## Example

```
import def "idklang.hpp"

start {
    var s="Hello World";
    printl(s);
    
}
```

Or check out examples folder to see more examples

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
