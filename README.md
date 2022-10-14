# idklang

idklang is compiled(transpiled to C++) programming language

## Installation

Use git to clone the project

### Clone

```bash
git clone https://github.com/SakizciAdam/idklang
```

### Compile the project

```bash
mkdir -p ./target
g++ main.cpp -o ./target/idklang -L./include/
```

## How to compile idklang file

```bash
./target/idklang <idklang file path> [-o: output file] [--keep: to keep the C++ file] [--no-compile: does not compile into executable]
```

## Example

```
import <vector>
import <map>
import def "idklang.hpp"

start {
    var s="Hello World";
    print(s);
    
}

```

Or check out exampes folder to see more examples

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)