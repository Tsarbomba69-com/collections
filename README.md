# crab_server
### Eng
A web server built in Rust. The goal is to build a full fledged web framework, basically I'm rewriting the web server i made in C. Both the C version and this one, are
heavily based on the Express framework for the Node runtime environment.

### Pt
Um servidor web construído em Rust. O objetivo é construir um framework web completo, basicamente estou reescrevendo o servidor web que fiz em C. Tanto a versão C quanto esta, são fortemente baseadas no framework Express para o ambiente de execução Node.

## Quick Start
>
> 1. <code>$ bash ./build.sh</code>

## Installation
>
> 1. Copy "libvec.so" to "/usr/lib" folder.
> 2. Import library in your source code. <code>#include "vec.h"</code>
> 3. Link the shared library to your source object. <code>gcc -o [source obj] [source obj].o -lvec -L/usr/lib/</code>
> 4. Enjoy 🙂