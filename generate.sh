#bin/sh

# https://github.com/quicktype/quicktype
# npm install -g quicktype
quicktype ./stats.json -o stats.cs
quicktype ./stats.json -o stats.cpp
quicktype ./stats.json -o stats.rs
quicktype ./stats.json -o stats.ts
quicktype ./stats.json -o stats.py
quicktype ./stats.json -o stats.go

