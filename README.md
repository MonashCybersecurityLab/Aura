# Aura

This repository contains the implementation of Aura, a non-interactive dynamic searchable symmetric encryption (DSSE) scheme. This is the first DSSE scheme that achieves forward and Type-II backward privacy [1] while supporting non-interactive queries. The detailed construction and security proof are presented in our NDSS'21 paper [2].



## Requirements

* Git
* Ubuntu 18.04
* g++-7 (7.5.0 in ubuntu 18.04)
* cmake 3.17
* openssl 1.1.1
* Apache Thrift 0.13.0



## Building

```bash
git clone https://github.com/MonashCybersecurityLab/Aura.git
cd Aura
mkdir build
cd build
# use cmake/make to build the code
cmake ..
make
```



## Usage

After compiling the project, three executable files of Aura will be generated. The first one is `SSETest`, which runs Aura client and server operations as a local procedure. This can be used to evaluate the performance of Aura with no communication cost. The other two files (`AuraServer` and `AuraClient`)  can be used to execute Aura in a networked environment. Particularly, the `AuraServer` starts an Apache Thrift server which can process the setup, update, query operations from the `AuraClient`. The results from these two executable file reflect the performance of Aura in real-world networks.

All the above executable files can be executed without extra parameters.



## Feedback

- [Submit an issue](https://github.com/MonashCybersecurityLab/Aura/issues/new)

- Email the authors: shifeng.sun@monash.edu, shangqi.lai@monash.edu, xingliang.yuan@monash.edu



## Reference

[1] Raphaël Bost, Brice Minaud, and Olga Ohrimenko. 2017. Forward and Backward Private Searchable Encryption from Constrained Cryptographic Primitives. In *Proceedings of the 2017 ACM SIGSAC Conference on Computer and Communications Security* (*CCS '17*). Association for Computing Machinery, New York, NY, USA, 1465–1482. DOI: https://doi.org/10.1145/3133956.3133980

[2] Shi-Feng Sun, Ron Steinfeld, Shangqi Lai, Xingliang Yuan, Amin Sakzad, Joseph Liu, Surya Nepal, and Dawu Gu. 2021. Practical Non-Interactive Searchable Encryption with Forward and Backward Privacy. In *the Network and Distributed System Security Symposium* (*NDSS*). DOI: https://dx.doi.org/10.14722/ndss.2021.24162



